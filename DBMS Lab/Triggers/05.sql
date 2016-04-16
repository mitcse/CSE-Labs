CREATE OR REPLACE VIEW Advisor_Student AS
	SELECT s_id, s.name AS s_name, s.dept_name AS s_dept, s.tot_cred, i_id, i.name AS i_name, i.dept_name AS i_dept, i.salary
	FROM ((Student s JOIN Advisor a ON s.id = a.s_id) JOIN Instructor i on i_id = i.id);

CREATE OR REPLACE TRIGGER AdvUpdate
INSTEAD OF DELETE ON Advisor_Student FOR EACH ROW
BEGIN
	DELETE FROM Advisor WHERE s_id = :OLD.s_id;
END;
/