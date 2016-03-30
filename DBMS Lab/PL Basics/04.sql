SET SERVEROUTPUT ON

DECLARE
 
	num int := 109383901;
	rev int;
	tmp int;
	
	b int;
		
BEGIN

	DBMS_OUTPUT.PUT_LINE('');
	
	tmp := num;
	rev := 0;
	
	while (tmp > 0) loop
		b := mod(tmp, 10);
		rev := rev * 10 + b;
		tmp := floor(tmp / 10);
	end loop;
	
	if (num = rev) then
		DBMS_OUTPUT.PUT_LINE('PALINDROME!!!');
	else
		DBMS_OUTPUT.PUT_LINE('NOT A PALINDROME!');
	end if;
	
END;
/