package com.course.buildings;

import java.util.*;

public class School extends Building {

	int nClass;
	String grade;
	
	void setClass (int nClass) {
		this.nClass = nClass;
	}

	void setGrade (String grade) {
		this.grade = new String(grade);
	}

	int getnClass () {
		return nClass;
	}

	String getGrade () {
		return grade;
	}
}
