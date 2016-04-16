DROP TABLE Account;

CREATE TABLE Account (
	ano VARCHAR(10) PRIMARY KEY, 
	bal NUMERIC(8, 0)
);

INSERT INTO Account VALUES ('AAAA10001', 98730);
INSERT INTO Account VALUES ('AAAA10002', 48810);
INSERT INTO Account VALUES ('AAAA10003', 61730);
INSERT INTO Account VALUES ('AAAA10004', 10170);
INSERT INTO Account VALUES ('AAAA10005', 69480);
INSERT INTO Account VALUES ('AAAA10006', 34050);
INSERT INTO Account VALUES ('AAAA10007', 47030);

DROP TABLE Transaction;

CREATE TABLE Transaction (
	ano VARCHAR(10),
	amt NUMERIC(8, 0)
);

CREATE OR REPLACE TRIGGER Banktrans
BEFORE INSERT ON Transaction FOR EACH ROW
DECLARE
	kcount NUMBER(1) := 0;
	kbal FLOAT := 0;
BEGIN
	SELECT bal INTO kbal FROM Account WHERE ano = :NEW.ano;
	IF :NEW.ano < 0 THEN
		RAISE_APPLICATION_ERROR(-1, 'Wrong account!');
	ELSIF kbal - :NEW.amt < 0 THEN
		RAISE_APPLICATION_ERROR(-2, 'Low balance!');
	ELSIF :NEW.amt < 1 THEN
		RAISE_APPLICATION_ERROR(-3, 'Cannot withdraw negative amount!');
	ELSE
		UPDATE Account SET bal = bal - :NEW.amt WHERE ano = :NEW.ano;
	END IF;
END;
/