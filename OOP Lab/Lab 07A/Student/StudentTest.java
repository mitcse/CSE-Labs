//
//  StudentTest.java
//
//  Created by Avikant Saini on 10/3/15
//

import java.util.Scanner;

class SeatsFilledException extends Exception {
	SeatsFilledException (String errorMessage) {
		super(errorMessage);
	}
	public SeatsFilledException () {
		System.err.println("\n\tAll seats have been filled, sit on the ground.\n");
	}
}

class Student {
	
	String name;
	int yearJoined;
	int regNo;

	static int seatNo = 1;

	public Student () {
		name = "";
		yearJoined = 0;
		regNo = 0;
	}
	
	public void input () throws SeatsFilledException {
		Scanner sc = new Scanner(System.in);
		System.out.print("\tEnter name: ");
		name = sc.nextLine();
		System.out.print("\tEnter year of joining: ");
		yearJoined = sc.nextInt();
		if (seatNo > 25)
			throw new SeatsFilledException();
		else
			regNo = (yearJoined % 100) * 100 + seatNo;
		seatNo++;
	}

	public void display () {
		System.out.println("\n                Name | " + name);
		System.out.println("     Year of Joining | " + yearJoined);
		System.out.println(" Registration Number | " + regNo);
	}
	
}

public class StudentTest {
	
	public static void main (String [] args) {
		
		Scanner sc = new Scanner(System.in);
		Student studs[] = new Student[30];
		
		for (int i = 0; i < 30; ++i) {
			System.out.println("\n\tEnter details of student " + (i+1) + ": ");
			studs[i] = new Student();
			try {
				studs[i].input();
			}
			catch (SeatsFilledException e) {
				System.err.println("Error: " + e);
				studs[i] = null;
				break;
			}
			System.out.print("\n\tContinue (y/n): ");
			char ch = sc.next().charAt(0);
			if (ch != 'y')
				break;
		}
		
		for (Student stud: studs)
			if (stud != null)
				stud.display();
		
	}
}
	
	
	
	
