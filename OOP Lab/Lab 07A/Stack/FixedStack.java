//
//  FixedStack.java
//
//  Created by Avikant Saini on 10/3/15
//


import java.util.Scanner;

class FixedStack implements Stack {

	int  arr[], tos;

	public FixedStack () {
		Scanner sc = new Scanner (System.in);
		System.out.print("\n\tEnter size of the fixed stack: ");
		int n = sc.nextInt();
		arr = new int[n];
		tos = -1;
	}

	public void push (int item) {

		if (tos == arr.length - 1) {
			System.out.println("\n\tSTACK OVERFLOW!!\n");
			return;
		}
		arr[++tos] = item;
	}

	public int pop () {
		if (tos == -1) {
			System.out.println("\n\tSTACK UNDERFLOW!!\n");
			return -32767;
		}
		return arr[tos--];
	}

}
