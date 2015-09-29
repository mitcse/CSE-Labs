//
// StackTest.java
//
// Created by Avikant Saini on 9/29/15
//

import java.util.*;

class PushException extends Exception {
	PushException (String errorMessage) {
		super(errorMessage);
	}
}

class PopException extends Exception {
	PopException (String errorMessage) {
		super(errorMessage);
	}
}

class Stack {
	int tos;
	int arr[];

	public Stack (int n) {
		tos = -1;
		arr = new int[n];
	}

	public void push (int item) {
		try {
			if (tos == arr.length - 1)
				throw new PushException("Stack Overflow!");
			else
				arr[++tos] = item;
		}
		catch (PushException exception) {
			System.err.println("Error: " + exception);
		}
	}

	public int pop () {
		int item = 0;
		try {
			if (tos == -1) {
				item = -32767;
				throw new PopException("Stack Underflow!");
			}
			else
				item = arr[tos--];
		}
		catch (PopException exception) {
			System.err.println("Error: " + exception);
		}
		finally {
			return item;
		}
	}

	@Override
	public String toString () {
		String stck = "";
		for (int i = 0; i <= tos; ++i)
			stck += "\t" + arr[i];
		return stck;
	}
}

public class StackTest {
	
	public static void main (String [] args) {
		
		Scanner sc = new Scanner(System.in);
		
		System.out.print("\tEnter the number of elements in the stack: ");
		int n = sc.nextInt();
		
		Stack stack = new Stack(n);

		int choice;
		do {
			System.out.print("\n\t1. Push\n\t2. Pop\n\t3. Display\n\tChoice: ");
			choice = sc.nextInt();

			if (choice == 1) {
				System.out.print("\n\tEnter item to push: ");
				int item = sc.nextInt();
				stack.push(item);
			}

			else if (choice == 2) {
				int item = stack.pop();
				if (item != -32767)
					System.out.print("\n\tPopped item: " + item);
			}

			System.out.println("\n\tCurrent Stack: " + stack);

		} while (choice == 1 || choice == 2 || choice == 3);
	}
}
