# 16

select sum(salary) as ssal, max(salary) as maxsal, min(salary) as minsal, avg(salary) as avgsal 
from Xemployee;

# 17

select sum(salary) as ssal, max(salary) as maxsal, min(salary) as minsal, avg(salary) as avgsal 
from Xemployee
where dno in (select dno from XDepartment where dname='Machine Field');

# 18 

 select XProject.pno, pname, count (*)
 from XProject, XWorksOn where XProject.pno = XWorksOn.pno
 group by pno, pname;


# 19 

select XProject.pno, pname, count(*)
from XProject, XWorksOn where XProject.pno = XWorksOn.pno
group by XProject.pno, pname having count(*) > 2;

# 20 

select dname, count(*)
from XDepartment, Xemployee where XDepartment.dno = Xemployee.dno and salary >40000 and dno in
(select dno 
	from Xemployee
		group by dno having count(*) > 5)
group by dname;
