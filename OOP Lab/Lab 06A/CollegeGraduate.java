import java.util.*;

class Person
{
	private String name;
	private GregorianCalendar dob;

	Person()
	{
		System.out.println("In default constructor of person");
		Scanner userEntry = new Scanner(System.in);
		System.out.print("Enter name: ");
		name = userEntry.nextLine();
		System.out.print("Enter date of birth: ");
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
		System.out.println("Student details->");
		System.out.println("Name : " +name);
		System.out.println("Date of Birth : " +dob.get(Calendar.DATE) + ":" +dob.get(Calendar.MONTH) + ":" +dob.get(Calendar.YEAR));
	}
}

class CollegeGraduate extends Person
{
	private float gpa;
	private int yrOfGrad;

	CollegeGraduate()
	{
		super();
		System.out.println("In College Graduate default constructor ");
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter GPA: ");
		gpa = sc.nextFloat();
		System.out.println("Enter year of graduation: ");
		yrOfGrad = sc.nextInt();
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
		System.out.println("GPA is: "+gpa);
		System.out.println("Year of graduation is: "+yrOfGrad);
	}

	public static void main(String args[])
	{
		System.out.println("Is the person a college graduate? (y/n)");
		Scanner sc = new Scanner(System.in);
		char x;
		x = sc.next().charAt(0);
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
			System.out.println("Invalid Input!");
		}
	}
}
