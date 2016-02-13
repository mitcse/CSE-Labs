create table XEmployee (
	fname varchar(20) not null,
	mname varchar(20),
	lname varchar(20) not null,
	ssn number(8) not null, 
	address varchar(40) not null,
	bdate date,
	sex varchar(1) not null check (sex in ('M', 'F')),
	salary number(8),
	sssn number(8),
	dno number(8),
	primary key (ssn)
);

alter table XEmployee add foreign key(sssn) references XEmployee(ssn);

insert into XEmployee values ('Harold', 'J', 'Finch', 101, 'Classified', '10-NOV-61', 'M', 192000, null, 601);
insert into XEmployee values ('John', 'B', 'Smith', 102, '5th Avenue, NY', '21-FEB-72', 'M', 112000, 101, 603);
insert into XEmployee values ('Sameen', 'R', 'Shaw', 103, '4th Loop, NY', '18-DEC-78', 'F', 112000, 101, 603);
insert into XEmployee values ('Samantha', 'R', 'Groves', 104, '1, Infinite Loop', '08-APR-79', 'F', 250000, null, 602);
insert into XEmployee values ('Lionel', 'P', 'Fusco', 105, '18th Rose Drive', '10-JUN-68', 'M', 89000, 104, 606);
insert into XEmployee values ('John', 'F', 'Greer', 106, 'Classified', '28-DEC-51', 'M', 800000, null, 609);

create table XDepartment (
	dname varchar(20) not null,
	dno number(8) not null,
	mssn number(8) not null,
	msdate date,
	primary key (dno),
	foreign key (mssn) references XEmployee(ssn)
);

insert into XDepartment values ('Admin', 601, 101, '02-JAN-03');
insert into XDepartment values ('Machine Field', 603, 102, '02-MAY-11');
insert into XDepartment values ('Analog Interface', 602, 104, '02-JAN-03');
insert into XDepartment values ('Enforcement', 606, 105, '02-JAN-78');
insert into XDepartment values ('Samaritan', 609, 106, '02-DEC-13');

create table XDeptLoc (
	dno number(8) not null,
	dloc varchar(20) not null,
	primary key (dno, dloc),
	foreign key (dno) references XDepartment(dno)
);

insert into XDeptLoc values (601, 'Classified');
insert into XDeptLoc values (602, 'Thornhill');
insert into XDeptLoc values (603, 'NY');
insert into XDeptLoc values (606, 'Brooklyn 99');
insert into XDeptLoc values (609, 'Texas');

create table XProject (
	pname varchar(20) not null,
	pno number(8) not null,
	ploc varchar(20),
	dno number(8) not null,
	primary key (pno),
	foreign key (dno) references XDepartment(dno)
);

insert into XProject values ('ProjectX', 701, 'NY', 601);
insert into XProject values ('ProjectY', 702, 'FR', 602);
insert into XProject values ('ProjectZ', 703, 'TX', 606);
insert into XProject values ('ProjectW', 704, 'CA', 609);

create table XWorksOn (
	essn number(8) not null,
	pno number(8) not null,
	hours number(6),
	foreign key (essn) references XEmployee(ssn),
	foreign key (pno) references XProject(pno)
);

insert into XWorksOn values (101, 701, 32);
insert into XWorksOn values (102, 702, 16);
insert into XWorksOn values (103, 702, 16);
insert into XWorksOn values (104, 704, 40);

create table XDependent (
	essn number(8),
	dname varchar(20),
	sex varchar(1) not null check (sex in ('M', 'F')),
	bdate date,
	relationship varchar(20),
	primary key (dname),
	foreign key (essn) references XEmployee(ssn)
);

insert into XDependent values (101, 'Bear', 'M', '10-OCT-01', 'Pet');
insert into XDependent values (102, 'World', 'M', '10-OCT-01', 'Protector');
insert into XDependent values (103, 'Jakku', 'M', '10-OCT-01', 'Protector');
insert into XDependent values (104, 'Machine', 'M', '02-JAN-03', 'Interface');