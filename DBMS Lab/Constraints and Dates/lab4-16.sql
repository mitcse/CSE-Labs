alter table Employee add dob date;

update Employee set dob='16-NOV-70' where empNo='001';
update Employee set dob='14-NOV-73' where empNo='002';
update Employee set dob='03-DEC-72' where empNo='003';
update Employee set dob='08-JAN-74' where empNo='004';
update Employee set dob='23-FEB-77' where empNo='005';
update Employee set dob='19-OCT-81' where empNo='006';

select to_char(dob, 'DD-MON-YYYY') from employee;
select to_char(dob, 'DD-MON-YY') from employee;
select to_char(dob, 'DD-MM-YY') from employee;