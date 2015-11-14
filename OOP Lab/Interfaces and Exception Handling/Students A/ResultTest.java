import java.util.*;

interface Sports
{
	void putGrade();
}

class Student
{
	int rollNo;
	int marks;

	Scanner userEntry = new Scanner (System.in);

	void getNumber ()
	{
		System.out.println("Enter roll number");
		int rN = userEntry.nextInt();
		this.rollNo = rN;
	}

	void getMarks ()
	{
		System.out.println("Enter marks");
		int ma = userEntry.nextInt();
		this.marks = ma;
	}

	Student ()
	{
		getNumber();
		getMarks();
	}

	void putNumber()
	{
		System.out.println("Roll : " +rollNo);
	}

	void putMarks()
	{
		System.out.println("Marks : " +marks);
	}

	void display()
	{
		putNumber();
		putMarks();
	}
}

class Result extends Student implements Sports
{
	char grade;

	Scanner userEntry = new Scanner (System.in);

	Result ()
	{
		super();
		putGrade();
	}

	public void putGrade()
	{
		System.out.println("Enter grade");
		grade = userEntry.next().charAt(0);
	}

	void display()
	{
		super.display();
		System.out.println("Grade : " +grade);
	}
}

class ResultTest
{
	public static void main (String args[])
	{
		Result r = new Result();
		r.display();
	}
}

	
