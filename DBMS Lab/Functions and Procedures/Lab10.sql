1.
create or replace procedure print_q1 is 
begin 
	dbms_output.put_line('Good Day to You'); 
end; 
/
declare 
begin 
	print_hello; 
end; 
/

2.
create or replace procedure dept (name varchar) is
cursor studname is select name from student where dept_name=name;
cursor cour is select course_id from course  where dept_name=name;
begin 
 for stu in studname loop
   dbms_output.put_line('name='  || stu.name);
 end loop;
for c in cour loop
 dbms_output.put_line('course id is ' || c.course_id);
end loop;
end;
/ 
declare
begin
  dept('Biology');
end;
