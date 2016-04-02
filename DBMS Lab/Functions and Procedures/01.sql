-- PROCEDURE to say hi

CREATE OR REPLACE PROCEDURE Hello IS
BEGIN
	DBMS_OUTPUT.PUT_LINE('Not a good day to you!');
END;
/

DECLARE
BEGIN
	Hello;
END;
/