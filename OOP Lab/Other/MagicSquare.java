//
// MagicSquare.java
//
// Created by Avikant Saini on 9/29/15
//

import java.util.*;

class MagicSquare implements Runnable {

	int mat[][];	// To store the matrix
	int sum[];		// To store the sum : rows + columns + diagonals
	boolean isUnique;

	public MagicSquare (int n) {
		mat = new int[n][n];
		sum = new int[n + n + 2];
		isUnique = false;
	}

	public void input () {
		Scanner sc = new Scanner(System.in);
		int n = mat.length;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                System.out.print("\tEnter matrix[" + (i+1) + "][" + (j+1) + "] : ");
                mat[i][j] = sc.nextInt();
            }
        }
	}

	public void run () {
		// Get the current thread's name
		String threadName = Thread.currentThread().getName();

		int n = mat.length;

		// Checking for uniqueness
		if (threadName.equals("Uniqe")) {
			isUnique = true;
			int temp[] = new int[n * n];
			int i, j, k = 0;
			for (i = 0; i < n; ++i)
				for (j = 0; j < n; ++j)
					temp[k++] = mat[i][j];
			for (i = 0; i < n * n; ++i) {
				for (j = i + 1; j < n; ++j) {
					if (temp[j] == temp[i]) {
						isUnique = false;
					}
				}
			}
		}
		// Storing the row sum
		else if (threadName.equals("RSum")) {
			for (int i = 0; i < n; ++i) {
	            int rt = 0;
	            for (int j = 0; j < n; ++j)
	                rt += mat[i][j];
	            sum[i] = rt;
        	}
		}
		// Storing the column sum
		else if (threadName.equals("CSum")) {
			for (int i = 0; i < n; ++i) {
	            int ct = 0;
	            for (int j = 0; j < n; ++j)
	                ct +=  mat[j][i];
	            sum[i + n] = ct;
        	}
		}
		// Storing the principal diagonal sum
		else if (threadName.equals("PDSum")) {
			for (int i = 0; i < n; ++i)
	            sum[n + n] += mat[i][i];
		}
		// Storing the secondary diagonal sum
		else {
			for (int i = 0; i < n; ++i)
	            sum[n + n + 1] += mat[i][i];
		}
	}

	public boolean isMagicSquare () {
		int n = mat.length;
		if (isUnique) {
			for (int i = 1; i < n + n + 2; ++i)
				if (sum[i] != sum[0])
					return false;
			return true;
		}
		return false;
	}

}

class MagicTest {

	public static void main (String [] args) {
		// Take the matrix...
		Scanner sc = new Scanner(System.in);
		System.out.print("\n\tEnter the number of elements in the matrix: ");
		int n = sc.nextInt();
		MagicSquare msq = new MagicSquare(n);
		msq.input();

		// Create five named threads...
		String threadNames[] = {"Uniqe", "RSum", "CSum", "PDSum", "SDSum"};
		Thread threads[] = new Thread[5];
		for (int i = 0; i < 5; ++i) {
			// Label the threads and start them.
			threads[i] = new Thread(msq, threadNames[i]);
			threads[i].start();
		}

		// Wait for each thread to finish...
		for (Thread thrd : threads) {
			try {
			 	thrd.join();
			}
			catch (Exception exception) {
				System.err.println("Error in threads: " + exception);
			}
		}

		// Now call the isMagicSquareMethod
		if (msq.isMagicSquare()) 
			System.out.println("\n\tMatrix is a magic square!\n\n");
		else
			System.out.println("\n\tMatrix is not a magic square!\n\n");

	}
}