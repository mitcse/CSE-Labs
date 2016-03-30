SET SERVEROUTPUT ON

DECLARE
 
	a float := 3;
	b float := 5;
	c float := -1;
		
	d float;
		
	r1 float;
	r2 float;
		
BEGIN

	d := b * b - 4 * a * c;
	
	if (d >= 0) then
		r1 := (-b + sqrt(d))/(2 * a);
		r2 := (-b - sqrt(d))/(2 * a);
		DBMS_OUTPUT.PUT_LINE('Roots: ' || r1 || ', ' || r2);
	else
		DBMS_OUTPUT.PUT_LINE('Imaginary Roots!');
	end if;
	
END;
/