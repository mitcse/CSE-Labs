-- Procedure to find the highest paid department for a given branch

CREATE OR REPLACE PROCEDURE deptHighest IS
	CURSOR curseInstructor IS 
		WITH maxSalaries AS (SELECT dept_name, max(salary) AS max_sal FROM Instructor GROUP BY dept_name)
			SELECT id, salary FROM Instructor NATURAL JOIN maxSalaries WHERE salary = max_sal;
BEGIN
	FOR row IN curseInstructor LOOP
		DBMS_OUTPUT.PUT_LINE(row.id || ', ' || row.salary);
	END LOOP;
END;
/

-- CREATE OR REPLACE PROCEDURE deptHighestBranch (dname Department.dept_name%TYPE) IS
-- 	CURSOR curseInstructor (dname Department.dept_name%TYPE) IS
-- 		WITH maxSalaries AS (SELECT dept_name, max(salary) AS max_sal FROM Instructor GROUP BY dept_name)
-- 			SELECT id, salary FROM Instructor NATURAL JOIN maxSalaries WHERE salary = max_sal AND Instructor.dept_name = dname; 
-- BEGIN
-- 	FOR row IN curseInstructor (dname) LOOP
-- 		DBMS_OUTPUT.PUT_LINE(row.id || ', ' || row.salary);
-- 	END LOOP;
-- END;
-- /

DECLARE
BEGIN
	DBMS_OUTPUT.PUT_LINE('----- ALL DEPTs HIGHEST SALARIES ------');
	deptHighest;
	-- DBMS_OUTPUT.PUT_LINE('----- HIGHEST FOR A GIVEN BRANCH ------');
	-- deptHighestBranch('Comp. Sci.');
END;
/