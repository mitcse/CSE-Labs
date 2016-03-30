set serveroutput on;

DECLARE
	CURSOR curse is SELECT * FROM student ORDER BY tot_cred;
	studrow student%rowtype;

BEGIN
	DBMS_OUTPUT.PUT_LINE('name \t|\t ID \t|\t credits');

	OPEN curse;
	LOOP 
		FETCH curse INTO studrow;
		DBMS_OUTPUT.PUT_LINE(studrow.name || ' | ' || studrow.ID || ' | ' || studrow.tot_cred);
		EXIT WHEN curse%ROWCOUNT > 9;
	END LOOP;

	CLOSE curse;
END;
/