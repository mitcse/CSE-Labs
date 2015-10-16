//
//	GenericStackTest.java
//
//	Created by Avikant Saini on 10/16/15.
//

import java.util.Scanner;

class Stack <GenericStack> {

	private GenericStack arr[];
	private int tos;

	public Stack (int n) {
		tos = -1;
		arr = (GenericStack [])(new Object[n]);
	}

	public void push (GenericStack item) {
		if (tos == arr.length - 1) {
			System.out.println("\n\tSTACK OVERFLOW!");
			return;
		}
		arr[++tos] = item;
	}

	public GenericStack pop () {
		if (tos == -1) {
			System.out.println("\n\tSTACK UNDERFLOW!");
			return null;
		}
		return arr[tos--];
	}

	@Override
	public String toString () {
		if (tos == -1)
			return "STACK IS EMPYT!";
		String str = "";
		for (int i = 0; i <= tos; ++i)
			str += "\t" + arr[i];
		return str;
	}

}

class Student {

	private String name;
	private double cgpa;

	public void input () {
		Scanner sc = new Scanner(System.in);
		System.out.print("\tEnter student name: ");
		name = sc.nextLine();
		System.out.print("\tEnter student cgpa: ");
		cgpa = sc.nextDouble();
	}

	@Override
	public String toString () {
		return "\n\tSTUDENT\n\tNAME: " + name + "\n\tCGPA: " + cgpa + "\n"; 
	}

}

class Employee {

	private String name;
	private String idno;

	public void input () {
		Scanner sc = new Scanner(System.in);
		System.out.print("\tEnter employee name: ");
		name = sc.nextLine();
		System.out.print("\tEnter employee id: ");
		idno = sc.nextLine();
	}

	@Override
	public String toString () {
		return "\n\tEMPLOYEE\n\tNAME: " + name + "\n\tIDNO: " + idno + "\n"; 
	}

}

public class GenericStackTest {

	public static void main (String [] args) {
		Scanner sc = new Scanner(System.in);
		int choice;
		do {
			System.out.print("\n\t1. Student\n\t2. Employee\n\tCHOICE: ");
			choice = sc.nextInt();

			if (choice < 1 || choice > 2) {
				System.out.println("Invalid Choice!");
				System.exit(0);
			}

			System.out.print("\n\tEnter the size of the stack: ");
			int n = sc.nextInt();

			if (choice == 1) {
				Stack <Student> stack = new Stack<>(n);
				int stch;
				do {
					System.out.print("\n\t1. Push\n\t2. Pop\n\t3. Display\n\tChoice: ");
					stch = sc.nextInt();
					if (stch < 1 || stch > 3)
						break;
					if (stch == 1) {
						Student stud = new Student();
						stud.input();
						stack.push(stud);
					}
					else if (stch == 2) {
						Student stud = stack.pop();
						if (stud != null)
							System.out.print("Popped: " + stud);
					}
					System.out.println("\n\tCurrent Stack: \n" + stack);

				} while (stch >= 1 && stch <= 3);
			}

			else if (choice == 2) {
				Stack <Employee> stack = new Stack<>(n);
				int stch;
				do {
					System.out.print("\n\t1. Push\n\t2. Pop\n\t3. Display\n\tChoice: ");
					stch = sc.nextInt();
					if (stch < 1 || stch > 3)
						break;
					if (stch == 1) {
						Employee empl = new Employee();
						empl.input();
						stack.push(empl);
					}
					else if (stch == 2) {
						Employee empl = stack.pop();
						if (empl != null)
							System.out.print("Popped: " + empl);
					}
					System.out.println("\n\tCurrent Stack: \n" + stack);
				} while (stch >= 1 && stch <= 3);
			}

		} while (choice == '1' || choice == '2');

	}

}

