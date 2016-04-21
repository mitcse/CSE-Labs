DROP TABLE ZAccount;

CREATE TABLE ZAccount (
	ano VARCHAR(10) PRIMARY KEY, 
	bal NUMERIC(8, 0)
);

INSERT INTO ZAccount VALUES ('1001', 98730);
INSERT INTO ZAccount VALUES ('1002', 48810);
INSERT INTO ZAccount VALUES ('1003', 61730);
INSERT INTO ZAccount VALUES ('1004', 10170);
INSERT INTO ZAccount VALUES ('1005', 69480);
INSERT INTO ZAccount VALUES ('1006', 34050);
INSERT INTO ZAccount VALUES ('1007', 47030);

DROP TABLE ZTransaction;

CREATE TABLE ZTransaction (
	ano VARCHAR(10),
	amt NUMERIC(8, 0)
);

CREATE OR REPLACE TRIGGER ZBanktrans
BEFORE INSERT ON ZTransaction FOR EACH ROW
DECLARE
	kcount NUMERIC(8, 0) := 0;
	kbal FLOAT := 0;
BEGIN
	SELECT count(*) INTO kcount FROM ZAccount WHERE ano = :NEW.ano;
	IF kcount < 1 THEN
		DBMS_OUTPUT.PUT_LINE('Wrong Account!');
		RAISE_APPLICATION_ERROR(-1, 'Wrong Account!');
	ELSE
		SELECT bal INTO kbal FROM ZAccount WHERE ano = :NEW.ano;
		IF kbal - :NEW.amt < 0 THEN
			DBMS_OUTPUT.PUT_LINE('Low balance!');
			RAISE_APPLICATION_ERROR(-2, 'Low balance!');
		ELSIF :NEW.amt < 1 THEN
			DBMS_OUTPUT.PUT_LINE('Cannot withdraw negative amount!');
			RAISE_APPLICATION_ERROR(-3, 'Cannot withdraw negative amount!');
		ELSE
			UPDATE ZAccount SET bal = bal - :NEW.amt WHERE ano = :NEW.ano;
			DBMS_OUTPUT.PUT_LINE('Updated!');
		END IF;
	END IF;
END;
/

INSERT INTO ZTransaction VALUES ('1006', 1000);
INSERT INTO ZTransaction VALUES ('1007', 1000);