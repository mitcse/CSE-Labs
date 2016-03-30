set serveroutput on

DECLARE
	name varchar2(20);
	deptName varchar2(20);
	dcount int;
	EXC exception;

BEGIN

	DBMS_OUTPUT.PUT_LINE('Enter department name: ');
	deptName := &deptName;

	SELECT name INTO name FROM instructor WHERE dept_name = deptName;
	SELECT name, count(*) into name, dcount FROM instructor GROUP BY name;

	IF dcount > 1 THEN
		raise EXC;
	END if;

	DBMS_OUTPUT.PUT_LINE('Name: '|| name);

EXCEPTION
	WHEN NO_DATA_FOUND THEN DBMS_OUTPUT.PUT_LINE('No associated instructor');
	WHEN TOO_MANY_ROWS THEN DBMS_OUTPUT.PUT_LINE('Ambiguous data.');
	WHEN EXC THEN DBMS_OUTPUT.PUT_LINE('1 instructor, multiple depts');

END;
/