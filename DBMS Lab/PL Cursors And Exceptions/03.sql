DROP TABLE salesman_master;
DROP TABLE Comission_payable;

CREATE TABLE Salesman_master (sno int, sname varchar2(20), rate float, starget float, tsales float);
CREATE TABLE Comission_payable (camt float, sno int, pdate date);

INSERT INTO salesman_master VALUES (1, 'Murdock', 10.0, 1000, 500);
INSERT INTO salesman_master VALUES (2, 'Nelson', 2.5, 2000, 1000);
INSERT INTO salesman_master VALUES (3, 'Fisk', 4.5, 5000, 6000);

DECLARE
	target float;
	total float;
	salesmanno int;
	roc float;
	EXC exception;

BEGIN

	DBMS_OUTPUT.PUT_LINE('Enter salesman no: ');
	salesmanno := &salesmanno;

	SELECT sno, starget, tsales, rate INTO salesmanno, total, target, roc FROM Salesman_master WHERE sno = salesmanno;

	IF target > total THEN
		INSERT INTO Comission_payable VALUES (total * roc, salesmanno, (SELECT sysdate FROM dual));
		DBMS_OUTPUT.PUT_LINE('Commisson payed.');
	ELSE
		RAISE EXC;
	END IF;

EXCEPTION
		WHEN EXC THEN DBMS_OUTPUT.PUT_LINE('Salesman master has not reached the goal!');
		WHEN OTHERS THEN DBMS_OUTPUT.PUT_LINE('Unknown error!');

END;
/

SELECT * FROM Salesman_master;
SELECT * FROM Comission_payable;