package p1;

import p1.Max;

import java.util.Scanner;

public class MaxTest {

	public static void main (String [] args) {

		Scanner sc = new Scanner (System.in);

		Max max = new Max ();
		char choice;

		do {

			System.out.print("\n\t1. Largest integer\n\t2. Largest float\n\t3. Largest in array\n\t4. Largest in matrix\n\tQ. Quit\n\tChoice: ");
			choice = sc.next().charAt(0);

			switch(choice) {

				case '1' : {
					System.out.print("\tEnter 3 integers: ");
					int a = sc.nextInt();
					int b = sc.nextInt();
					int c = sc.nextInt();
					System.out.println("\n\tLargest = " + max.max(a, b, c));
				}
					break;

				case '2' : {
					System.out.print("\tEnter 3 floating point numbers: ");
					float a = sc.nextFloat();
					float b = sc.nextFloat();
					float c = sc.nextFloat();
					System.out.println("\n\tLargest = " + max.max(a, b, c));
				}
					break;

				case '3' : {
					System.out.print("\tEnter number of integers in array: ");
					int n = sc.nextInt();
					int arr[] = new int[n];
					System.out.print("\tEnter " + n + " elements: ");
					for(int i = 0; i < n; ++i)
						arr[i] = sc.nextInt();
					System.out.println("\n\tLargest = " + max.max(arr));
				}
					break;

				case '4' :	{
					System.out.print("\tEnter size of the matrix: ");
					int r = sc.nextInt();
					int c = sc.nextInt();
					int mat[][] = new int[r][c];
					System.out.print("\tEnter the matrix: ");
					for(int i = 0; i < r; ++i)
						for (int j = 0; j < c; ++j)
							mat[i][j] = sc.nextInt();
					System.out.println("\n\tLargest = " + max.max(mat));
				}
					break;

				default : break;
			}	

		} while ("1234".indexOf(choice) > -1);

	}
}
