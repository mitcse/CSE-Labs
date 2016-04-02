CREATE OR REPLACE PACKAGE manageDept AS

	PROCEDURE listInsNames (dName course.dept_name%type);

	FUNCTION getMaxSalary (dName course.dept_name%type) return Instructor.salary%type;

END manageDept;
/

CREATE OR REPLACE PACKAGE BODY manageDept AS

	PROCEDURE listInsNames (dName course.dept_name%type) IS
		CURSOR curseIns (dName Instructor.dept_name%type) IS
			SELECT name FROM Instructor WHERE dept_name = dName;

		BEGIN
			FOR row IN curseIns (dName) LOOP
				DBMS_OUTPUT.PUT_LINE('    ' || row.name);
			END LOOP;
		END;

	FUNCTION getMaxSalary (dName course.dept_name%type)
		return Instructor.salary%type as
			mSal Instructor.salary%type;

		BEGIN
			SELECT max(salary) INTO mSal FROM Instructor WHERE dept_name = dName;
			RETURN mSal;
		END;

END manageDept;
/

DECLARE
BEGIN
	manageDept.listInsNames('Comp. Sci.');
	DBMS_OUTPUT.PUT_LINE(manageDept.getMaxSalary('Comp. Sci.'));
END;
/