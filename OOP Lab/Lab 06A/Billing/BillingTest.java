//
// BillingTest.java
// Patient
//		Inpatient
//			 Billing
//
//	Created by Avikant Saini on 9/26/15
//

import java.util.*;
import java.text.*;

class Patient {
	
	private String name;
	private GregorianCalendar dateOfBirth;
	private int hosptialNumber;

	Patient () {
		name = "";
		dateOfBirth = new GregorianCalendar ();
		hosptialNumber = 0;
	}

	public void input () {
		Scanner sc = new Scanner (System.in);
		System.out.print("Enter name: ");
		name = sc.nextLine();
		System.out.print("Enter date of birth (yyyy mm dd): ");
		dateOfBirth = new GregorianCalendar (sc.nextInt(), sc.nextInt(), sc.nextInt());
		System.out.print("Enter hosptial number: ");
		hosptialNumber = sc.nextInt();
	}

	public void display () {
		SimpleDateFormat dateFomat = new SimpleDateFormat ("MMM dd, yyyy");
		System.out.println(	"	 	  	  Name 	|	" + name + 
							"\n	 Date of Birth	|	" + dateFomat.format(dateOfBirth.getTime()) + 
							"\n  Hospital Number|	" + hosptialNumber);
	}

}

class Inpatient extends Patient {

	String departmentName;
	GregorianCalendar dateOfAdmission;
	String roomType;

	Inpatient () {
		super();
		departmentName = "";
		dateOfAdmission = new GregorianCalendar ();
		roomType = "";
	}

	public void input () {
		super.input();
		Scanner sc = new Scanner (System.in);
		System.out.print("Enter dept. name: ");
		departmentName = sc.nextLine();
		System.out.print("Enter date of admission (yyyy mm dd): ");
		dateOfAdmission = new GregorianCalendar (sc.nextInt(), sc.nextInt(), sc.nextInt());
		System.out.print("Enter room type (General, SemiSpecial, Special): ");
		sc.nextLine();
		roomType = sc.nextLine();
	}

	public void display () {
		super.display();
		SimpleDateFormat dateFomat = new SimpleDateFormat ("MMM dd, yyyy");
		System.out.println(	"		 Dept Name 	|	" + departmentName + 
							"\nDate of Admission|	" + dateFomat.format(dateOfAdmission.getTime()) + 
							"\n		Room Type	|	" + roomType);
	}

}

class Billing extends Inpatient {

	GregorianCalendar dischargeDate;

	Billing () {
		super ();
		dischargeDate = new GregorianCalendar ();
	}

	public void input () {
		super.input();
		Scanner sc = new Scanner (System.in);
		System.out.print("Enter discharge date (yyyy mm dd): ");
		dischargeDate = new GregorianCalendar (sc.nextInt(), sc.nextInt(), sc.nextInt());
	}

	public void display () {
		super.display();
		SimpleDateFormat dateFomat = new SimpleDateFormat ("MMM dd, yyyy");
		System.out.println(	"Discharge Date	|	" + dateFomat.format(dischargeDate.getTime()));
		System.out.println(	"\nBilling Total	|	" + getBillingTotal());
	}

	private long getBillingTotal () {
		long daysSpent = dischargeDate.getTime().getTime() - dateOfAdmission.getTime().getTime();
		daysSpent /= (1000 * 24 * 60 * 60);
		if (roomType.equals("Special"))
			return 1200 * daysSpent;
		else if (roomType.equals("SemiSpecial"))
			return 600 * daysSpent;
		return 150 * daysSpent;
	}

}

public class BillingTest {

	public static void main(String [] args) {
		
		Billing billing = new Billing ();
		billing.input ();
		billing.display ();

	}

}


