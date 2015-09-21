<<<<<<< HEAD:OOP Lab/Lab 06/CollegeGraduate.java
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
		System.out.println ("GPA: " + gpa +
							"\nYear of Graduation: " + yearGraduated);
		
=======
import java.util.*;

class Person
{
	private String name;
	private GregorianCalendar dob;

	Person ()
	{
		System.out.println("Inside Person default constructor");
		Scanner userEntry = new Scanner(System.in);
		System.out.println("Enter name");
		name = userEntry.nextLine();
		System.out.println("Enter date of birth");
		int y, m, d;
		d = userEntry.nextInt();
		m = userEntry.nextInt();
		y = userEntry.nextInt();
		dob = new GregorianCalendar(y, m, d);
	}

	String getName()
	{
		return this.name;
	}

	GregorianCalendar getDOB()
	{
		return this.dob;
	}

	void display()
	{
		System.out.println("Student details are");
		System.out.println("Name : " +name);
		System.out.println("Date of Birth : " +dob.get(Calendar.DATE) + ":" +dob.get(Calendar.MONTH) + ":" +dob.get(Calendar.YEAR));
>>>>>>> e75bafd707a71991d6b0d178c728c4007e958e80:OOP Lab/Lab 06/Person/CollegeGraduate.java
	}

<<<<<<< HEAD:OOP Lab/Lab 06/CollegeGraduate.java
=======
	CollegeGraduate()
	{
		super();
		System.out.println("Inside College Graduate default constructor");
		Scanner userEntry = new Scanner(System.in);
		System.out.println("Enter gpa");
		gpa = userEntry.nextFloat();
		System.out.println("Enter year of graduation");
		yrOfGrad = userEntry.nextInt();
	}

	float getGpa()
	{
		return this.gpa;
	}

	float getGradYr()
	{
		return this.yrOfGrad;
	}

	void display()
	{
		super.display();
		System.out.println("GPA is "+gpa);
		System.out.println("Year of graduation is "+yrOfGrad);
	}

	public static void main(String args[])
	{
		System.out.println("Is the person a college graduate? y/n");
		Scanner userEntry = new Scanner(System.in);
		char x;
		x = userEntry.next().charAt(0);
		if (x == 'y')
		{
			CollegeGraduate cg1 = new CollegeGraduate();
			cg1.display();
		}
		else if (x == 'n')
		{
			Person p1 = new Person();
			p1.display();
		}
		else
		{
			System.out.println("You have entered invalid input. Exiting program...");
		}
	}
>>>>>>> e75bafd707a71991d6b0d178c728c4007e958e80:OOP Lab/Lab 06/Person/CollegeGraduate.java
}
