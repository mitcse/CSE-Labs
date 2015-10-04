//
//
//
//
//

import java.util.Scanner;

public class StackTest {

	public static void main (String [] args) {

		Scanner sc = new Scanner(System.in);

		FixedStack fs = new FixedStack();
		DynamicStack ds = new DynamicStack();

		int choice;
		do {
			System.out.print("\n\t1. FixedStack\n\t2. DynamicStack\n\tElse exit.\n\tChoice: ");
			choice = sc.nextInt();

			int x;

			if (choice == 1) {
				do {
					System.out.print("\n\t1. Push\n\t2. Pop\n\t3. Display\n\tElse exit.\n\tChoice: ");
					x = sc.nextInt();
					if (x < 1 || x > 3)
						break;
					if (x == 1) {
						System.out.print("\n\tEnter item to push: ");
						int item = sc.nextInt();
						fs.push(item);
					}
					else if (x == 2) {
						int item = fs.pop();
						if (item != -32767)
							System.out.println("\n\tPopped item: " + item);
					}
					fs.display();
				} while (x > 0 && x < 4);
			}

			else if (choice == 2) {
				do {
					System.out.print("\n\t1. Push\n\t2. Pop\n\t3. Display\n\tElse exit.\n\tChoice: ");
					x = sc.nextInt();
					if (x < 1 || x > 3)
						break;
					if (x == 1) {
						System.out.print("\n\tEnter item to push: ");
						int item = sc.nextInt();
						ds.push(item);
					}
					else if (x == 2) {
						int item = ds.pop();
						if (item != -32767)
							System.out.println("\n\tPopped item: " + item);
					}
					ds.display();
				} while (x > 0 && x < 4);
			}

		}  while (choice == 1 || choice == 2);
	}
}