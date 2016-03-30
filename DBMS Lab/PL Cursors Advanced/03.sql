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
		DBMS_OUTPUT.PUT_LINE('ROLLBACKED!');
	END IF;

END;
/
