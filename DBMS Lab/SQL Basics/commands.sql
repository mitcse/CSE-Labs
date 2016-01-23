select name, dept_name
from student;


select id, name, dept_name, salary
from instructor
where instructor.dept_name = 'Comp. Sci.';


select title
from course
where course.credits = 3;


select takes.course_id, course.title
from takes, course
where course.course_id = takes.course_id and takes.id = '12345'


select name,salary
from instructor
where instructor.salary between 40000 and 90000;


update advisor set i_id = 1001 where s_id between 100 and 200;


update instructor set dept_name = 'Comp. Sci.' where dept_name = 'it';


update instructor set salary = salary*1.05;


delete from department where dept_name = 'IT';


delete from prereq where course_id = '101';


select from course where course_id not in (select course_id from teaches);


alter table student add(Date_Of_Birth numeric(8,0));


alter table department modify(dept_name varchar(20));


alter table student drop column Date_Of_Birth;


select student.name, course.title, section.year
from student, course, section
where section.course_id = course.course_id and section.room_number = '303';


select name,salary inst_salary
from instructor
where salary > some (select salary from instructor where dept_name = 'Comp. Sci.');


select name, dept_name from instructor where dept_name like '%ch%';
