SET SERVEROUTPUT ON

DROP TABLE TBL_NEXT_DATE;
CREATE TABLE TBL_NEXT_DATE (gdate date, ndate date);

DECLARE

	sdate date := '01-JAN-2016';
	edate date := '31-DEC-2016';
		
BEGIN

	DBMS_OUTPUT.PUT_LINE('');
	
	/*
	while not (sdate >= edate) loop
		INSERT INTO TBL_NEXT_DATE VALUES (sdate, sdate + 2);
		sdate := sdate + 7;
	end loop;
	*/
	
	while not (sdate = 'Z') loop
		INSERT INTO TBL_NEXT_DATE VALUES (sdate, sdate + 2);
		sdate := sdate + 7;
	end loop;
	
END;
/
-- 
-- SELECT * FROM TBL_NEXT_DATE;