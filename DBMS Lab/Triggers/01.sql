-- Trigger to insert into a new table everytime any change is made in the Takes table

SET SERVEROUTPUT ON;

DROP TABLE Log_Change_Takes;

CREATE TABLE Log_Change_Takes (
	ID VARCHAR(8),
	type VARCHAR(6),
	toc TIMESTAMP,
	course_id VARCHAR(8),
	sec_id VARCHAR(8),
	semester VARCHAR(8),
	year NUMERIC(4, 0),
	grade VARCHAR(2),
	PRIMARY KEY (ID, toc, course_id, sec_id, semester, year)
);

CREATE OR REPLACE TRIGGER Log_Change_Takes 
BEFORE INSERT OR UPDATE OR DELETE ON Takes FOR EACH ROW
BEGIN
	CASE
		WHEN INSERTING THEN
			INSERT INTO Log_Change_Takes VALUES (:NEW.ID, 'INSERT', CURRENT_TIMESTAMP, :NEW.course_id, :NEW.sec_id, :NEW.semester, :NEW.year, :NEW.grade);
			DBMS_OUTPUT.PUT_LINE('INSERT ' || :NEW.ID);
		WHEN DELETING THEN
			INSERT INTO Log_Change_Takes VALUES (:OLD.ID, 'DELETE', CURRENT_TIMESTAMP, :OLD.course_id, :OLD.sec_id, :OLD.semester, :OLD.year, :OLD.grade);
			DBMS_OUTPUT.PUT_LINE('DELETE ' || :OLD.ID);
		WHEN UPDATING THEN
			INSERT INTO Log_Change_Takes VALUES (:NEW.ID, 'UPDATE', CURRENT_TIMESTAMP, :NEW.course_id, :NEW.sec_id, :NEW.semester, :NEW.year, :NEW.grade);
			DBMS_OUTPUT.PUT_LINE('UPDATE ' || :NEW.ID);
	END CASE;
END;
/