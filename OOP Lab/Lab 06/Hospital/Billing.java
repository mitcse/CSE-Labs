import java.util.*;

class Patient
{
	int age, hospNo;
	String name;

	static Scanner userEntry = new Scanner (System.in);

	Patient()
	{
		System.out.println("Enter name");
		name = userEntry.nextLine();

		System.out.println("Enter age");
		age = userEntry.nextInt();

		System.out.println("Enter hospital number");
		hospNo = userEntry.nextInt();
	}

	void display()
	{
		System.out.println("Patient details are :");
		System.out.println("Name : " +name);
		System.out.println("Age : " +age);
		System.out.println("Hospital Number : " +hospNo);
	}
}

class Inpatient extends Patient
{
	String depName;
	int roomType;
	GregorianCalendar admnDate;

	Inpatient()
	{
		super();

		System.out.println("Enter department name");
		depName = userEntry.nextLine();
		depName = userEntry.nextLine();
		System.out.println("Enter room type. 1 for special, 2 for semi-special, 3 for general");
		roomType = userEntry.nextInt();
		System.out.println("Enter date, month, year of admission");
		int d = userEntry.nextInt();
		int m = userEntry.nextInt();
		int y = userEntry.nextInt();

		admnDate = new GregorianCalendar(y, m, d);
	}

	void display()
	{
		super.display();

		System.out.println("Department Name : " +depName);

		if (roomType == 1)
		{
			System.out.println("Room Type : Special");
		}
		else if (roomType == 2)
		{
			System.out.println("Room Type : Semi-Special");
		}
		else if (roomType == 3)
		{
			System.out.println("Room Type : General");
		}

		System.out.println("Admission Date : " +admnDate.get(Calendar.DATE) +":" + admnDate.get(Calendar.MONTH) + ":" +admnDate.get(Calendar.YEAR));
	}
}

class Billing extends Inpatient
{
	GregorianCalendar discDate;

	Billing()
	{
		super();

		System.out.println("Enter discharge date, month, year");
		int d = userEntry.nextInt();
		int m = userEntry.nextInt();
		int y = userEntry.nextInt();
		discDate = new GregorianCalendar (y, m, d);
	}

	void display()
	{
		super.display();

		int days = ((discDate.get(Calendar.YEAR) - super.admnDate.get(Calendar.YEAR)) * 365) + ((discDate.get(Calendar.MONTH) - super.admnDate.get(Calendar.MONTH)) * 30) + (discDate.get(Calendar.DATE) - super.admnDate.get(Calendar.DATE));

		if (super.roomType == 1)
		{
			int amount = days * 1200;
			System.out.println("Total bill is " +amount);
		}
		else if (super.roomType == 2)
		{
			int amount = days * 600;
			System.out.println("Total bill is " +amount);
		}
		else if (super.roomType == 3)
		{
			int amount = days * 150;
			System.out.println("Total bill is " +amount);
		}
	}

	public static void main(String args[])
	{
		Billing b1 = new Billing();
		b1.display();
	}
}
