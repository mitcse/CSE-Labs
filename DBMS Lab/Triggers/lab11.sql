--1)
	create table takes_log (
		toc timestamp,
		type varchar(3),
		ID			varchar(5), 
		course_id		varchar(8),
		sec_id			varchar(8), 
		semester		varchar(6),
		year			numeric(4,0),
		grade		        varchar(2),
	 	primary key (toc, ID, course_id, sec_id, semester, year),
	 	foreign key (course_id,sec_id, semester, year) references section
		on delete cascade,
	 	foreign key (ID) references student
		on delete cascade);
	
	CREATE or REPLACE trigger log_takes
	BEFORE INSERT OR UPDATE-- OF id,course_id,sec_id,semester,year,grade
	OR DELETE on takes
	FOR EACH ROW
	BEGIN
		CASE
			WHEN INSERTING THEN
				insert into takes_log values (current_timestamp,'ins',:NEW.id,:NEW.course_id,:NEW.sec_id,:NEW.semester,:NEW.year,:NEW.grade);
			WHEN DELETING THEN
				insert into takes_log values (current_timestamp,'del',:OLD.id,:OLD.course_id,:OLD.sec_id,:OLD.semester,:OLD.year,:OLD.grade);
			WHEN UPDATING THEN
				insert into takes_log values (current_timestamp,'upd',:NEW.id,:NEW.course_id,:NEW.sec_id,:NEW.semester,:NEW.year,:NEW.grade);
		END CASE;
	END;
	/

--2)
	CREATE or REPLACE trigger item_update
	BEFORE INSERT on item_trans
	FOR EACH ROW
	BEGIN
		CASE
			WHEN INSERTING THEN
				update item_master set bal_stock=bal_stock-:NEW.quantity;
		END CASE;
	END;
	/

--3)
		CREATE or REPLACE trigger ValidateTransaction
		BEFORE INSERT on Transactions for EACH ROW
		Declare
			varAccountNo Varchar2(10):=0;
			varCurrentBalance Number(10);
			BEGIN
				select count(AccountNo) into varAccountNo from Accounts where AccountNo =: NEW.AccountNo;
				if varAccountNo = 0 THEN
					Raise_Application_Error(-20000,'The Account Number is invalid');
				End if;
				if :NEW.Ammount<=0 then 
				Raise_Application_Error(-20001,'The transaction ammount cannot be negative or zero');
				END IF;

				select CurrentBalance into varCurrentBalance from Accounts where AccountNo = :NEW.AccountNo;

			END;
			/


--4)
	create trigger audit_trail
		after update or delete on client_master
		for each row
		Declare
			oper varchar2(8);
			client_no varchar2(6);
			Name varchar2(20);
			Bal_due number(10,2);
		Begin 
			if updating then
				oper:='update';
				END IF
				if deleting then 
					oper :='delete';
				end if;
				client_no :+:old.client_no;
				Name :=: old.name;
				bal_due:= old.bal_due;
				insert into auditclient 
					values(client_no,name,bal_due,oper,user,sysdate);
			END;
			/

--5)
	create view Advisor_Student as select Instructor.id as iid, student.id as sid, instructor.name as iname, student.name as sname from instructor, advisor, student where instructor.id=i_id and student.id=s_id;
	create or replace trigger delete_advisor instead of delete on Advisor_student
	for each row
	begin
		delete from advisor where advisor.i_id=:old.iid;
	end;
	/

