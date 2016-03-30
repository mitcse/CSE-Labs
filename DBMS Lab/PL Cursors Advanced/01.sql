
-- 1 (i)

DROP TABLE Salary_Raise;
CREATE TABLE Salary_Raise (iid varchar(20), rdate date, raise numeric(8, 2));

DECLARE

	CURSOR curse IS
		SELECT * FROM Instructor WHERE dept_name = 'Biology' FOR UPDATE;
	raiseamt numeric(8, 2);

BEGIN

	FOR sal IN curse LOOP
		raiseamt := sal.salary * 1.05;
		UPDATE Instructor SET salary = salary * 1.05;
		INSERT INTO Salary_Raise VALUES (sal.ID, CURRENT_DATE, raiseamt);
	END LOOP;

END;
/

SELECT * FROM Salary_Raise;

-- 1 (ii)

DROP TABLE Salary_Raise;
CREATE TABLE Salary_Raise (iid varchar(20), rdate date, raise numeric(8, 2));

DECLARE

	id varchar(20);
	sal numeric(8, 2);
	dept varchar(20);
	raiseamt numeric(8, 2);

	CURSOR curse IS
		SELECT ID, salary, dept_name FROM Instructor FOR UPDATE;

BEGIN

	OPEN curse;

	LOOP
		FETCH curse INTO id, sal, dept;
		IF dept = 'Comp. Sci.' THEN
			UPDATE Instructor SET salary = sal * 1.05 WHERE CURRENT OF curse;
			raiseamt := sal * 1.05;
			INSERT INTO Salary_Raise VALUES (id, CURRENT_DATE, raiseamt);
		END IF;
		EXIT WHEN curse%NOTFOUND;
	END LOOP;

END;
/

SELECT * FROM Salary_Raise;

-- 3

DECLARE

	tsal numeric;

BEGIN

	SAVEPOINT insertIn;

	INSERT INTO Instructor VALUES ('19299', 'Walter White', 'Chemistry', '80000');

	SAVEPOINT salInc;

	UPDATE Instructor SET salary = 100000 WHERE name LIKE '%Mozart%';
	UPDATE Instructor SET salary = 150000 WHERE name LIKE '%Srinivasan%'

	SELECT SUM(salary) INTO tsal FROM Instructor;

	IF tsal > 2000000 THEN
		ROLLBACK TO SAVEPOINT salInc;
	END IF;

END;
/
