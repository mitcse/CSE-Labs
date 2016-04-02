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
	CREATE table client
		(c_no varchar(5) primary key,
		 name varchar(20),
		 bal_due number);
		insert into client values ('10001','SomeGuy',10000);
		insert into client values ('10002','SomeOtherGuy',20000);
		insert into client values ('10003','YetAnotherGuy',30000);
	CREATE table audit_client
		(c_no varchar(5),
		 name varchar(20),
		 bal_due number,
		 op varchar(3),
		 user_id varchar(5) default('00000'),
		 opDate date);

	CREATE or REPLACE trigger client_audit
	BEFORE UPDATE or INSERT on client
	FOR EACH ROW
	BEGIN
		CASE
			WHEN UPDATING THEN
				insert into audit_client values (:OLD.c_no,:OLD.name,:OLD.bal_due,'upd',NULL,sysdate);
			WHEN DELETING THEN
				insert into audit_client values (:OLD.c_no,:OLD.name,:OLD.bal_due,'del',NULL,sysdate);
		END CASE;
	END;
	/
	

--4)
	create or replace view adv_stu as
		select s_id,S.name as s_name,S.dept_name as s_dept,S.tot_cred,i_id,I.name as i_name,i.dept_name as i_dept,I.salary  
		from ((student S join advisor A on s.id=a.s_id) join instructor I on i_id=i.id);

	CREATE or REPLACE trigger advisor_update
	INSTEAD of DELETE on adv_stu 
	FOR EACH ROW
	BEGIN
		delete from advisor where s_id = :OLD.s_id;
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

