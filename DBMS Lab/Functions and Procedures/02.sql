-- PROCEDURE that lists all the students associated with a department

CREATE OR REPLACE PROCEDURE listDept (deptName Student.dept_name%type) IS
	CURSOR curseStudent (deptName student.dept_name%type) IS 
		SELECT name FROM Student WHERE dept_name = deptName;
	CURSOR curseCourses (deptName course.dept_name%type) IS 
		SELECT course_id FROM Course WHERE dept_name = deptName;
BEGIN
	DBMS_OUTPUT.PUT_LINE('...........................');
	DBMS_OUTPUT.PUT_LINE('-- DEPARTMENTs STUDENTs --');
	FOR row IN curseStudent (deptName) LOOP
		DBMS_OUTPUT.PUT_LINE('    ' || row.name);
	END LOOP;
	DBMS_OUTPUT.PUT_LINE('...........................');
	DBMS_OUTPUT.PUT_LINE('-- COURSES --');
	FOR row IN curseCourses (deptName) LOOP
		DBMS_OUTPUT.PUT_LINE('    ' || row.course_id);
	END LOOP;
END;
/

DECLARE
BEGIN
	listDept('Comp. Sci.');
END;
/