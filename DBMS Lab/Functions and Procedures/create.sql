drop table payment;
drop table borrower;
drop table depositor;
drop table account;
drop table loan;
drop table customer;
create table customer( customer_id varchar(5) primary key);
create table loan(
	loan_number varchar(5) primary key,
	amount number
);

create table account( account_no varchar(5) primary key,
					balance number);

create table depositor(customer_id varchar(5),
					account_no varchar(5),
					primary key(customer_id, account_no),
					foreign key(customer_id) references customer(customer_id),
					foreign key(account_no) references account(account_no));

create table borrower( customer_id varchar(5),
					loan_number varchar(5),
					primary key(customer_id,loan_number),
					foreign key(customer_id) references customer(customer_id),
					foreign key(loan_number) references loan(loan_number));

create table payment(loan_number varchar(5),
					payment_number varchar(5),
					amount number,
					primary key(loan_number,payment_number),
					foreign key(loan_number) references loan(loan_number));


insert into customer values('00001');
insert into customer values('00002');
insert into customer values('00003');
insert into loan values('00001',100000);
insert into loan values('00002',200000);
insert into loan values('00003',300000);
insert into loan values('00004',800000);
insert into borrower values('00001','00001');
insert into borrower values('00001','00002');
insert into borrower values('00001','00003');
insert into borrower values('00002','00004');
insert into payment values('00001','00001',100000);
insert into payment values('00002','00001',50000);
insert into payment values('00002','00002',50000);
insert into payment values('00004','00001',500000);
insert into account values('00001',400000);
insert into account values('00002',300000);
insert into account values('00003',400000);
insert into depositor values('00001','00001');
insert into depositor values('00002','00002');
insert into depositor values('00002','00003');

	with loan_amount as (select sum(amount) as amount from borrower natural join loan where customer_id='00001'),
deposit_amount as (select sum(balance) as amount from account natural join depositor where customer_id='00001')
select loan_amount.amount as la, deposit_amount.amount as pa from loan_amount,deposit_amount;