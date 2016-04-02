CREATE OR REPLACE PROCEDURE interestCalculation (
	principal number,
	timet number,
	rate number,
	si OUT number,
	ci OUT number,
	totalSum IN OUT number
) IS
	initSum number;
BEGIN
	si := (principal * rate * timet) / 100;
	initSum := totalSum;
	totalSum := totalSum * power(((1 + (rate/100))), FLOOR(timet));
	ci := totalSum - initSum;
END;
/

DECLARE
	principal number := 10000;
	rate number := 10;
	timet number := 3;
	si number;
	ci number;
	totalSum number := 44000;
BEGIN
	interestCalculation (principal, timet, rate, si, ci, totalSum);
	DBMS_OUTPUT.PUT_LINE('principal = ' || principal);
	DBMS_OUTPUT.PUT_LINE('rate = ' || rate);
	DBMS_OUTPUT.PUT_LINE('time = ' || timet);
	DBMS_OUTPUT.PUT_LINE('si = ' || si);
	DBMS_OUTPUT.PUT_LINE('ci = ' || ci);
	DBMS_OUTPUT.PUT_LINE('totalSum = ' || totalSum);
END;
/