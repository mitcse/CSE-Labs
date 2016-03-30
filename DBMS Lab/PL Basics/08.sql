SET SERVEROUTPUT ON



DECLARE

	n int;
	c int;
	s int;
	a float;
	
	type numbers is varray(10) of integer;
	num numbers := numbers(11, 24, 16, 98, 82, 59, 19, 03, -1, 10);
		
BEGIN

	DBMS_OUTPUT.PUT_LINE('');
	
	c := 0;
	s := 0;
	
	loop
		n := num(c + 1);
		if (n = -1) then
			goto ends;
		else
			c := c + 1;
			s := s + n;
		end if;
	end loop;
	
	<<ends>>
	if (c = 0) then
		a := 0;
	else
		a := s / c;
	end if;
	DBMS_OUTPUT.PUT_LINE('Average = ' || a);
	
END;
/