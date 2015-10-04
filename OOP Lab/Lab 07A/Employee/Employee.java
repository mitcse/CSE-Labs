//
//  Employee.java
//
//  Created by Avikant Saini on 10/3/15
//

import java.util.*;
import java.io.*;

public class Employee {

	String name;
	int age;
	double grossSalary;
	float takeHomeSalary;
	char grade;

	public void input () {
		
		Scanner sc = new Scanner (System.in);

		try {
			System.out.print("            Enter name : ");
			name = sc.nextLine();

			System.out.print("             Enter age : ");
			String ageS = sc.nextLine();

			age = Integer.parseInt(ageS);

			if (age < 0 || age > 100)
				throw new IOException();

			System.out.print("    Enter gross salary : ");
			String grossSalaryStr = sc.nextLine();

			grossSalary = Double.parseDouble(grossSalaryStr);

			if (grossSalary < 0)
				throw new IOException();

			System.out.print("Enter take home salary : ");
			String takeHomeSalaryStr = sc.nextLine();

			takeHomeSalary = Float.parseFloat(takeHomeSalaryStr);

			if (takeHomeSalary < 0)
				throw new IOException();

			System.out.print("            Enter grade : ");
			String gradeStr = sc.nextLine();

			if (gradeStr.length() > 1)
				throw new InputMismatchException();

			grade = gradeStr.charAt(0);

		}
		catch (Exception exception) {
			System.err.println("\nError occured: " + exception + ". Try again.\n");
			input();
		}
	}

	public void display() {
		System.out.println("\n\n\t            Name | " + name);
		System.out.println("\t             Age | " + age);
		System.out.println("\t    Gross Salary | " + grossSalary);
		System.out.println("\tTake Home Salary | " + takeHomeSalary);
		System.out.println("\t           Grade | " + grade + "\n\n");
	}
}
