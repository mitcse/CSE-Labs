SET SERVEROUTPUT ON

DECLARE

	i int;
	x int;
	f int;
		
BEGIN

	DBMS_OUTPUT.PUT_LINE('');
	
	x := &x;
	f := 1;
	
	for i in 2..x loop
		f := f * i;
	end loop;
	
	DBMS_OUTPUT.PUT_LINE('' || x || '! = ' || f);
	
END;
/