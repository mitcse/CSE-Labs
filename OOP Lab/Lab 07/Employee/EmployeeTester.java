import java.util.*;
import java.io.*;

class Employee
{
	String name;
	int age;
	double grossSalary;
	float takeHomeSalary;
	char grade;

	void input ()
	{
		Scanner userEntry = new Scanner (System.in);
		try
		{
			System.out.println("Enter name");
			name = userEntry.nextLine();
			System.out.println("Enter age");
			String ageS = userEntry.nextLine();
			age = Integer.parseInt(ageS);
			if (age < 0)
				throw new IOException();
			System.out.println("Enter gross salary");
			grossSalary = userEntry.nextDouble();
			if (grossSalary < 0)
				throw new IOException();
			System.out.println("Enter take home salary");
			takeHomeSalary = userEntry.nextFloat();
			if (takeHomeSalary < 0)
				throw new IOException();
			System.out.println("Enter grade");
			grade = userEntry.next().charAt(0);
		}
		catch (IOException ioe)
		{
			System.out.println("Invalid input, try all over again");
			input();
		}
	}

	void display()
	{
		System.out.println("Employee details are:");
		System.out.println("Name :" +name);
		System.out.println("Age :" +age);
		System.out.println("Gross Salary : " +grossSalary);
		System.out.println("Take Home Salary : " +takeHomeSalary);
		System.out.println("Grade : " +grade);
	}
}

class EmployeeTester
{
	public static void main (String args[])
	{
		Employee e = new Employee();
		Scanner userEntry = new Scanner (System.in);
		int c;
		System.out.println("1. Input\n2. Display\n3. Exit");
		c = userEntry.nextInt();
		if (c == 1)
		{
			e.input();
			System.out.println("Do you want to display details? y/n");
			char h = userEntry.next().charAt(0);
			if (h == 'y')
				e.display();
		}
		else if (c == 2)
			e.display();
	}
}
