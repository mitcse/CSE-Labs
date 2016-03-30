DROP TABLE salary_raise;
CREATE TABLE salary_raise (iid varchar(5), rdate date, amt number(8,2));

set serveroutput on;

DECLARE
	temp instructor%ROWTYPE;
	dname varchar2(20) := 'Biology';
	CURSOR curse IS SELECT * FROM instructor WHERE dept_name = dname;
	raiset number(8,2);

BEGIN
	OPEN curse;
	
	LOOP
		FETCH curse INTO temp;
		EXIT WHEN curse%notfound;
		UPDATE instructor SET salary = salary * 1.05 WHERE dept_name = dname;		
		raiset := temp.salary * 0.05;		
		INSERT INTO salary_raise VALUES (temp.id, (SELECT sysdate FROM dual), raiset);
	END loop;

	CLOSE curse;
end;
/

SELECT * FROM salary_raise;