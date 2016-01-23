alter table student add primary key(ID);
alter table student add foreign key(dept_name) references department;

alter table takes add primary key(ID, course_id, sec_id, semester, year);
alter table takes add foreign key(course_id, sec_id, semester, year) references section;

alter table course add primary key(course_id);
alter table course add foreign key(dept_name) references department;

alter table department add primary key(dept_name);

alter table section add primary key(course_id, sec_id, semester, year);
alter table section add foreign key(building, room_nuimber) references classroom;

alter table time_slot add primary key(time_slot_id, day, start_time);
alter table time_slot add foreign key(time_slot_id) references section;

alter table instructor add primary key(ID);
alter table instructor add foreign key(dept_name) references department;

alter table prereq add primary key(course_id, prereq_id);
alter table prereq add foreign key(course_id) references course;

alter table classroom add primary key(building, room_no);

alter table department add primary key(dept_name);

alter table teaches add primary key(ID, course_id, sec_id, semester, year);
alter table teaches add foreign key(course_id, sec_id, semester, year) references section;