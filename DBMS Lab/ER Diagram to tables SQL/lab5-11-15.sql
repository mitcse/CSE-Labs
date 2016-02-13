# 11

select fname, lname
from XEmployee
where sssn is null;

# 12

select fname, lname
from XEmployee, XDependent
where XEmployee.ssn = XDependent.essn and XEmployee.sex = XDependent.sex and XEmployee.lname = XDependent.dname;

# 13

select fname, lname
from XEmployee
where ssn not in (select essn from XDependent);

# 14

select fname, lname
from XEmployee
where ssn in (select essn from XDependent) and ssn in (select mssn from XDepartment);

# 15

select ssn
from XEmployee
where ssn in (select essn from XWorksOn where pno between 701 and 703);