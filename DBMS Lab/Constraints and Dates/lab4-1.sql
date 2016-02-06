create table Employee (
	empNo number(8),
	empName varchar(20) not null,
	sex varchar(1) check (sex = 'M' or sex = 'F') not null,
	salary numeric(8,0) default (1000) not null,
	address varchar(40) not null,
	dno number(8),
	primary key (empNo)
);