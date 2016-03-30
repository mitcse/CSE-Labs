SET SERVEROUTPUT ON

DECLARE
 
	a int;
	b int;
	c int;
	
	x int := 500;
		
BEGIN

	a := 0;
	b := 1;
	
	DBMS_OUTPUT.PUT_LINE(a || ' ');
	DBMS_OUTPUT.PUT_LINE(b || ' ');
	
	while ((a + b) <= x) loop
		c := a + b;
		a := b;
		b := c;
		DBMS_OUTPUT.PUT_LINE(c || ' ');
	end loop;
	
END;
/