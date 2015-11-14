//
//  StackTest.java
//
//  Created by Avikant Saini on 10/3/15
//


import java.util.Scanner;

public class StackTest {

	public static void main (String [] args) {

		Scanner sc = new Scanner(System.in);

		FixedStack fs = new FixedStack();
		DynamicStack ds = new DynamicStack();
		
		Stack st = null;

		int choice;
		do {
			System.out.print("\n\t1. FixedStack\n\t2. DynamicStack\n\tElse exit.\n\tChoice: ");
			choice = sc.nextInt();
			
			if (choice == 1)
				st = fs;
			else if (choice == 2)
				st = ds;
			else
				System.exit(0);
				
			int x;

			do {
				System.out.print("\n\t1. Push\n\t2. Pop\n\tElse exit.\n\tChoice: ");
				x = sc.nextInt();
				if (x < 1 || x > 3)
					break;
				if (x == 1) {
					System.out.print("\n\tEnter item to push: ");
					int item = sc.nextInt();
					st.push(item);
				}
				else if (x == 2) {
					int item = st.pop();
					if (item != -32767)
						System.out.println("\n\tPopped item: " + item);
				}
			} while (x > 0 && x < 3);

		}  while (choice == 1 || choice == 2);
	}
}
