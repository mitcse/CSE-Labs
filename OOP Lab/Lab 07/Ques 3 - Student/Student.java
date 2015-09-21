import java.util.*;

class SeatsFilledException extends Exception
{
	public SeatsFilledException ()
	{
		System.out.println("Seats have been filled");
	}
}

class Student
{
	String name;
	int yrOfJoining;
	int regNo;

	static int count = 0;

	Student()
	{
		Scanner userEntry = new Scanner(System.in);
		System.out.println("Enter name");
		name = userEntry.nextLine();
		System.out.println("Enter year of joining");
		yrOfJoining = userEntry.nextInt();
		regNo = (yrOfJoining % 100)*100 + count;
		count += 1;
	}

	void throwRegNoException(int r) throws SeatsFilledException
	{
		if (r > ((yrOfJoining % 100)*100 + 25))
			throw new SeatsFilledException();
	}

	void display()
	{
		System.out.println("Entered student details are :");
		System.out.println("Name : " +name);
		System.out.println("Year of Joining : " +yrOfJoining);
		System.out.println("Registration Number : " +regNo);
	}

	public static void main (String args[])
	{
		Scanner userEntry = new Scanner(System.in);
		int r;
		char c;
		do
		{
			System.out.println("Enter student details");
			Student s = new Student();
			r = s.regNo;
			try
			{
				s.throwRegNoException(r);
			}
			catch (SeatsFilledException sfe)
			{
				System.exit(0);
			}
			s.display();
			System.out.println("Do you want to enter other? y/n");
			c = userEntry.next().charAt(0);
		}  while (c == 'y');
	}
}
