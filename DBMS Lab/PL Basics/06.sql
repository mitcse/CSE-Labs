SET SERVEROUTPUT ON

DROP TABLE SPHERE;
CREATE TABLE SPHERE (raduis numeric(2, 0), volume numeric(8, 2), sarea numeric(8, 2));

DECLARE

	svalue int := 3;
	evalue int := 24;
		
BEGIN

	DBMS_OUTPUT.PUT_LINE('');
	
	while (svalue <= evalue) loop
		INSERT INTO SPHERE VALUES (svalue, round(1.33 * 3.14 * svalue * svalue * svalue, 2), round(4 * 3.14 * svalue * svalue, 2));
		svalue := svalue + 1;
	end loop;
	
END;
/

SELECT * FROM SPHERE;