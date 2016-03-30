-- 2

CREATE TABLE Item_Master (itemid int primary key, descrption varchar(50), balanceStock int);
CREATE TABLE Item_Transaction (itemid int primary key, descrption varchar(50), quantity int);

INSERT INTO Item_Master VALUES (1, 'Kryptonite Balls', 10);
INSERT INTO Item_Master VALUES (2, 'Batrangs', 200);
INSERT INTO Item_Master VALUES (3, 'Smoke Bombs', 100);

DECLARE

	CURSOR curse(item int) IS
		SELECT * FROM Item_Master WHERE itemid = item FOR UPDATE;

	rowItemMaster Item_Master%ROWTYPE;
	id int;
	desc varchar(50);
	qty int;

BEGIN

	id := &id;
	des := &des;
	qty := &qty;

	OPEN curse(id);

	FETCH curse INTO rowItemMaster;
	INSERT INTO Item_Transaction VALUES (id, des, qty);
	IF curse%NOTFOUND THEN
		INSERT INTO Item_Master VALUES (id, des, qty);
	ELSE
		UPDATE Item_Master SET balanceStock = balanceStock - qty WHERE itemid = id;
	END IF;

END;

/

SELECT * FROM Item_Master;
SELECT * FROM Item_Transaction;