//
//	CollegeGraduate.java
//	Created by Avikant Saini on 9/14/15
//

import java.util.GregorianCalendar;
import java.util.Scanner;

public class CollegeGraduate extends Person {
	
	private double gpa;
	private int yearGraduated;

	public CollegeGraduate () {
		super ();
		gpa = 0.0;
		yearGraduated = 0;
	}
	
	public double getGPA () {
		return gpa ;
	}
	
	public int getYearOfGraduation () {
		return yearGraduated;
	}
	
	public void inputFields () {
		Scanner sc = new Scanner (System.in);
		
		System.out.print ("Enter name: ");
		setName (sc.nextLine ());
		
		System.out.print ("Enter dob (yyyy/mm/dd): ");
		GregorianCalendar db = new GregorianCalendar (sc.nextInt(), sc.nextInt() - 1, sc.nextInt());
		setDOB (db);
		
		System.out.print ("Enter gpa: ");
		gpa = sc.nextDouble ();
		
		System.out.print ("Enter year of graduation: ");
		yearGraduated = sc.nextInt();
	}
	
	public void display () {
		super.display ();
		System.out.println ("GPA: " + gpa + "\nYear of Graduation: " + yearGraduated);
	}
}