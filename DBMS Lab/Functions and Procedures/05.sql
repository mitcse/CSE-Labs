CREATE OR REPLACE FUNCTION square (x number)
	RETURN number AS
		s number;
BEGIN
	s := x * x;
	RETURN s;
END;
/

DECLARE
BEGIN
	DBMS_OUTPUT.PUT_LINE('16 ^ 2 = '||square(16));
END;
/