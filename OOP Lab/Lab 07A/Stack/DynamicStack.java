//
//
//
//
//

import java.util.Scanner;

class DynamicStack implements Stack {

	int arr[], tos;

	public DynamicStack () {
		arr = new int[4];
		tos = -1;
	}

	public void push (int item) {

		if (tos == arr.length - 1) {
			int newArr[] = new int[2 * arr.length];
			for (int i = 0; i < arr.length; ++i)
				newArr[i] = arr[i];
			arr = newArr;
			newArr = null;
		}
		arr[++tos] = item;
	}

	public int pop () {
		if (tos == -1) {
			System.out.println("\n\tSTACK UNDERFLOW!\n");
			return -32767;
		}
		return arr[tos--];
	}

	public void display () {
		System.out.print("\n\tCURRENT STACK: ");
		for (int i = 0; i <= tos; ++i)
			System.out.print("\t" + arr[i]);
	}
}