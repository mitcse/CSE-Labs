//
//	MatrixTest.java
//
//	Created by Avikant Saini on 10/06/15
//

import java.util.Scanner;

class Matrix implements Runnable {

	int mat[][];
	int sum[];

	public Matrix (int n, int m) {
		mat = new int[n][m];
		sum = new int[n];
	}

	public void input () {
		Scanner sc = new Scanner(System.in);
		System.out.println("\n\tEnter the matrix: ");
		for (int i = 0; i < mat.length; ++i)
			for (int j = 0; j < mat[i].length; ++j)
				mat[i][j] = sc.nextInt();
	}

	public void run () {
		int tno = Integer.parseInt(Thread.currentThread().getName());
		sum[tno] = 0;
		for (int i: mat[tno])
			sum[tno] += i;
	}

	public int getSum () {
		int sumAll = 0;
		for (int i : sum)
			sumAll += i;
		return sumAll;
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

		for (int i = 0; i < n; ++i) {
			threads[i] = new Thread(matrix, ""+i);
			threads[i].start();
		}

		for (Thread thrd : threads) {
			try {
				thrd.join();
			}
			catch (Exception e) {
				System.err.println("Error in joining: " + e);
			}
		}

		System.out.println("\n\tTotal sum = " + matrix.getSum());

	}

}