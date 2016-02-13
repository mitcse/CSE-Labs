# 16

select sum(salary) as ssal, max(salary) as maxsal, min(salary) as minsal, avg(salary) as avgsal 
from Xemployee;

# 17

select sum(salary) as ssal, max(salary) as maxsal, min(salary) as minsal, avg(salary) as avgsal 
from Xemployee
where dno in (select dno from XDepartment where dname='Machine Field');

# 18 (Doubtful...)

-- select XProject.pno, pname, count (essn)
-- from XProject inner join XWorksOn on XProject.pno=XWorksOn.pno
-- group by pname;


# 19 (???)



# 20 (???)

-- select dno, count (ssn)
-- from XDepartment D, XEmployee E
-- where 
