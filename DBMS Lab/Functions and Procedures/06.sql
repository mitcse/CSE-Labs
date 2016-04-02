CREATE OR REPLACE FUNCTION popularCourse (deptName course.dept_name%type)
	RETURN takes.course_id%type as
	pop takes.course_id%type;
BEGIN
	WITH counts AS (SELECT takes.course_id, count(id) AS students
					FROM takes GROUP BY takes.course_id
					HAVING takes.course_id IN (SELECT course_id FROM course WHERE dept_name = deptName)),
		max_count AS (SELECT max(students) AS ms FROM counts)
	SELECT course_id INTO pop FROM counts, max_count WHERE students = ms;
	RETURN pop;
END;
/

DECLARE
	mostPopular course.course_id%type;
	mostPopularTitle course.title%type;
BEGIN
	mostPopular := popularCourse('Physics');
	SELECT title INTO mostPopularTitle FROM course WHERE course_id = mostPopular;
	DBMS_OUTPUT.PUT_LINE('Most popular course in Physics dept. is ' || mostPopular || ' (' || mostPopularTitle || ').');
END;
/