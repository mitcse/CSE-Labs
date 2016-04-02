--1)
	create or replace procedure sayHi is
	BEGIN
		DBMS_OUTPUT.PUT_LINE('Good Day to You!');
	END;
	/

	DECLARE
	BEGIN
		sayHi;
	END;
	/

--2)
	create or replace procedure list_dept (name_dept student.dept_name%type) is
	--DECLARE
		cursor sCursor(dName student.dept_name%type) is 
		select name from student where dept_name=dName;
		cursor cCursor(dName course.dept_name%type) is 
		select course_id from course where dept_name=dName;
	BEGIN
		DBMS_OUTPUT.PUT_LINE('Dept : '||name_dept);
		for r in sCursor(name_dept) LOOP
			DBMS_OUTPUT.PUT_LINE(r.name);
		END LOOP;
		DBMS_OUTPUT.PUT_LINE('---------------');
		for r in cCursor(name_dept) LOOP
			DBMS_OUTPUT.PUT_LINE(r.course_id);
		END LOOP;
	END;
	/

	DECLARE
	BEGIN
		list_dept('Comp. Sci.');
	END;
	/
 
--3)
	create or replace procedure dept_highest is
	--DECLARE
		cursor sCursor is 
		with mSal as (select dept_name, max(salary) as max_sal from instructor group by dept_name)
		select id,salary from instructor natural join mSal where salary=max_sal;
	BEGIN
		for r in sCursor LOOP
			DBMS_OUTPUT.PUT_LINE(r.id||', '||r.salary);
		END LOOP;
	END;
	/

	DECLARE
	BEGIN
		dept_highest;
	END;
	/

--4)
	--(a)
		create or replace procedure print_loan_details (c_id depositor.customer_id%type) is
			cursor apCursor(id depositor.customer_id%type) is 
			with amounts as( select amount from borrower natural join loan where customer_id=id),
				payments as( select payment_amount from borrower natural join payment where customer_id=id)
			select sum(amount) as total_amount, sum(payment_amount) as total_payment from amounts, payments;
			a loan.amount%type;
			p payment.payment_amount%type;
		BEGIN
			DBMS_OUTPUT.PUT_LINE('Customer : '||c_id);
			open apCursor(c_id);
			fetch total_amount,total_payment into a,p;
			DBMS_OUTPUT.PUT_LINE('Total Amount : '||a||', Total Payment : '||p);
		END;
		/
	--(b)
		create or replace procedure print_loan_branch(b_name loan_branch.branch_name%type) is
			cursor adCursor(name loan_branch.branch_name%type) is 
			with amounts as(select amount from loan_branch natural join loan where branch_name=name),
				deposits as(select balance from account_branch natural join account where branch_name=name)
			select sum(amount) as total_amount, sum(balance) as total_deposit from amounts, deposits;
			a loan.amount%type;
			d account.balance%type;
		BEGIN
			DBMS_OUTPUT.PUT_LINE('Branch : '||b_name);
			open apCursor(b_name);
			fetch total_amount,total_deposit into a,d;
			DBMS_OUTPUT.PUT_LINE('Total Amount : '||a||', Total Deposit : '||d);
		END;
		/

--5)
	create or replace function square(a number)
		RETURN number as
		s number;
	BEGIN
		s:= a*a;
		RETURN s;
	END;
	/

	DECLARE
	BEGIN
		DBMS_OUTPUT.PUT_LINE('5 ^ 2 = '||square(5));
	END;
	/

--6)
	create or replace function popular_course(dName course.dept_name%type)
		RETURN takes.course_id%type as
		pop takes.course_id%type;
	BEGIN
		with counts as (select takes.course_id,count(id) as students
						from takes group by takes.course_id
						having takes.course_id in (select course_id from course where dept_name=dName)),
		max_count as (select max(students) as ms from counts)
		select course_id into pop from counts,max_count where students = ms;
		RETURN pop;
	END;
	/

	DECLARE
	BEGIN
		DBMS_OUTPUT.PUT_LINE('Most popular Course in Comp. Sci. is '||popular_course('Comp. Sci.'));
	END;
	/

--7)
	create or replace package manage_dept as
		procedure list_instNames (dName course.dept_name%type) is
			cursor iCursor is
			select name from instructor where dept_name=dName;

		BEGIN
			for r in iCursor LOOP
				DBMS_OUTPUT.PUT_LINE(r.name);
			END LOOP;
		END;

		FUNCTION get_max_salary (dName course.dept_name%type)
			return instructor.salary%type as
			mSal instructor.salary%type;

		BEGIN
			select max(salary) into mSal from instructor where dept_name = dName;
			RETURN mSal;
		END;
	END manage_dept;

	DECLARE
	BEGIN
		call manage_dept.list_instNames("Comp. Sci.");
		DBMS_OUTPUT.PUT_LINE(call manage_dept.get_max_salary("Comp. Sci."));
	END;
	/

--8)
	CREATE or REPLACE PROCEDURE interesting_stuff(p number,t number, r number, si OUT number,ci OUT number, tSum IN OUT number) is
	temp number;
	BEGIN
		si := (p*t*r)/100;
		temp := tSum;
		tSum := power((tSum*(1+(r/100))),FLOOR(t));
		ci := tSum - temp;
	END;
	/

	DECLARE
	p number := 1000
	t number := 2
	r number := 10
	si number;
	ci number;
	tSum number := 100;	--principal for CI
	BEGIN
		interesting_stuff(p,t,r,si,ci,tSum);
		DBMS_OUTPUT.PUT_LINE(si||", "||ci||", "||tSum);
	END;
	/
			
