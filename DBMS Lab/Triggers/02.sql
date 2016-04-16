CREATE OR REPLACE TRIGGER Item_update
BEFORE INSERT ON Item_Transaction FOR EACH ROW
BEGIN
	UPDATE Item_Master SET balanceStock = balanceStock - :NEW.quantity;
END;
/