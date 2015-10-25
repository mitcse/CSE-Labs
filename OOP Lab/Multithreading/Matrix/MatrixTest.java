//
//	MatrixTest.java
//
//	Created by Avikant Saini on 10/06/15
//

import java.util.Scanner;

class Matrix {
	private int arr[][];
	
	public Matrix (int n, int m) {
		arr = new int[n][n];
	}

	public int[] getRow (int i) {
		return arr[i];
	}

	public void input () {
		Scanner sc = new Scanner(System.in);
		System.out.println("\n\tEnter the matrix: ");
		for (int i = 0; i < arr.length; ++i)
			for (int j = 0; j < arr[i].length; ++j)
				arr[i][j] = sc.nextInt();
	}

}

class RowSum implements Runnable {

	private int arr[];
	private int sum;

	RowSum (int a[]) {
		arr = a;
		sum = 0;
	}

	public int getRowSum () {
		return sum;
	}

	public void run () {
		for (int i: arr)
			sum += i;
	}

}

public class MatrixTest {

	public static void main (String [] args) {

		Scanner sc = new Scanner(System.in);

		System.out.print("\n\tEnter the dimensions of the matrix: ");
		int n = sc.nextInt();
		int m = sc.nextInt();

		Matrix matrix = new Matrix(n, m);
		matrix.input();

		Thread threads[] = new Thread[n];
		RowSum rowsum[] = new RowSum[n];

		for (int i = 0; i < n; ++i) {
			rowsum[i] = new RowSum(matrix.getRow(i));
			threads[i] = new Thread(rowsum[i]);
			threads[i].start();
		}

		int sum = 0;

		try {
			for (int i = 0; i < n; ++i) {
				threads[i].join();
				sum += rowsum[i].getRowSum();
			}
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}

		System.out.println("\n\tTotal sum = " + sum);

	}

}