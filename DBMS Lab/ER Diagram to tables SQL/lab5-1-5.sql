# 1

select bdate, address
from XEmployee
where fname='John' and mname='B' and lname='Smith';

# 2

select fname, lname, address
from XEmployee
where dno in (select dno from XDepartment where dname='Machine Field');

# 3

select pno, XProject.dno, lname, address, bdate
from XProject, XEmployee, XDepartment
where ploc='NY' and XProject.dno=XDepartment.dno and XDepartment.mssn=XEmployee.ssn;

# 4

select distinct salary from XEmployee;

# 5

select E.fname, E.lname, S.fname, S.lname
from XEmployee E, XEmployee S
where E.sssn=S.ssn;