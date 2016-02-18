# 6

select pno
from XProject
where dno in (select dno from XDepartment where mssn in (select ssn from XEmployee where lname='Smith'))
or pno in (select pno from XWorksOn where essn in (select ssn from XEmployee where lname='Smith'));

# 7

select *
from XEmployee
where address='Classified';

# 8

update XEmployee
set salary = salary * 1.10
where ssn in 
	(select essn from XWorksOn where pno in
		(select pno from XProject where pname='ProjectX'));
		
select fname, salary
from XEmployee;

# 9

select fname, lname
from XEmployee
where salary between 50000 and 150000 and dno in
	(select dno from XDepartment where dname='Machine Field');
	
# 10 
	
 select fname, lname, pname, dname
 from XEmployee, XWorksOn, XDepartment
 where XEmployee.ssn=XWorksOn.ssn and XEmployee.dno=XDepartment.dno and XWorksOn.pno = ProjectX.pno
 order by dname, lname, fname;