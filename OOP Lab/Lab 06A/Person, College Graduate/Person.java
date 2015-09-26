//
//	Person.java
//	Created by Avikant Saini on 9/14/15
//

import java.util.GregorianCalendar;
import java.util.Scanner;
import java.text.*;

public class Person {

	private String name;
	private GregorianCalendar dateOfBirth;

	public Person () {
		name = "";
		dateOfBirth = new GregorianCalendar ();
	}
	
	public void setName (String n) {
		name = n;
	}
	
	public void setDOB (GregorianCalendar dob) {
		dateOfBirth = dob;
	}

	public String getName () {
		return name;
	}

	public GregorianCalendar getDOB ()  {
		return dateOfBirth;
	}
	
	public void inputFields () {
		Scanner sc = new Scanner (System.in);
		
		System.out.print ("Enter name: ");
		String name = sc.nextLine ();
		
		System.out.print ("Enter dob (yyyy/mm/dd): ");
		GregorianCalendar dob = new GregorianCalendar (sc.nextInt(), sc.nextInt() - 1, sc.nextInt());
	}
	
	public void display () {
		SimpleDateFormat dateFormat = new SimpleDateFormat("MMM dd, yyyy");
		System.out.println ("\n\nName: " + name + "\nDOB: " + dateFormat.format(dateOfBirth.getTime()));
	}
	
}
