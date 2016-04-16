DROP TABLE Client_Master;

CREATE TABLE Client_Master (
	cno VARCHAR(8) PRIMARY KEY,
	name VARCHAR(20),
	address VARCHAR(50),
	dues NUMBER
);

INSERT INTO Client_Master VALUES ('01430', 'Gazorpzorp', 'Lowlanet', 3000);
INSERT INTO Client_Master VALUES ('04862', 'Ifiwiuefiu', 'Ppdjsfro', 4000);
INSERT INTO Client_Master VALUES ('16796', 'Loswiueweo', 'Xvwouire', 6000);

DROP TABLE Audi_Client;

CREATE TABLE Audi_Client (
	operation VARCHAR(6),
	tstamp TIMESTAMP,
	cno VARCHAR(8),
	name VARCHAR(20),
	address VARCHAR(50),
	dues NUMBER,
	userid VARCHAR(5)
);

CREATE OR REPLACE TRIGGER ClientAudit
BEFORE UPDATE OR DELETE ON Client_Master FOR EACH ROW
BEGIN
	CASE
		WHEN UPDATING THEN
			INSERT INTO Audi_Client VALUES ('UPDATE', CURRENT_TIMESTAMP, :NEW.cno, :NEW.name, :NEW.address, :NEW.dues, NULL);
		WHEN DELETING THEN
			INSERT INTO Audi_Client VALUES ('DELETE', CURRENT_TIMESTAMP, :OLD.cno, :OLD.name, :OLD.address, :OLD.dues, NULL);
	END CASE;
END;
/