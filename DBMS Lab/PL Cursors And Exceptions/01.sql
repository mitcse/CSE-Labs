DROP TABLE Areas;
CREATE TABLE Areas (radius float, area float);

INSERT INTO Areas VALUES (1, 3.14);
INSERT INTO Areas VALUES (2, 3.14 * 4);
INSERT INTO Areas VALUES (3, 3.14 * 9);
INSERT INTO Areas VALUES (4, 3.14 * 16);

set serveroutput on

DECLARE
	rad float;
	ara float;

BEGIN

	DBMS_OUTPUT.PUT_LINE('Enter the radius you want to get the area for: ');
	rad := &rad;

	SELECT area INTO ara FROM Areas WHERE radius = rad;

	DBMS_OUTPUT.PUT_LINE('Area of radius ' || rad || ' = ' || ara);

EXCEPTION
	WHEN NO_DATA_FOUND THEN DBMS_OUTPUT.PUT_LINE('No data found!');

	WHEN OTHERS THEN DBMS_OUTPUT.PUT_LINE('Other Exc.');

END;
/