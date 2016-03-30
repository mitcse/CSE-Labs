SET SERVEROUTPUT ON

DECLARE
 
	issue date := '21-DEC-2012';
	retur date := '18-FEB-2014';
	
	days int;
	fine float;
		
BEGIN

	days := retur - issue;
	
	if (days < 5) then
		fine := 0;
	elsif (days = 5) then
		fine := 0.5;
	elsif (days <= 10) then
		fine := 0.5 + (days - 5) * 1.00;
	elsif (days <= 30) then
		fine := 0.5 + 5 * 1.0 + (days - 10) * 5.00;
	else
		fine := 0.5 + 5 * 1.0 + 20 * 5.00 + (days - 30) * 10;
	end if;
	
	DBMS_OUTPUT.PUT_LINE('FINE : ' || fine);
	
END;
/