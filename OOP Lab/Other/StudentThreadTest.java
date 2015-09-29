//
// StudentThreadTest.java
//
// Created by Avikant Saini on 9/29/15
//

import java.util.*;

class StudentThread implements Runnable {

	double cgpa[][]; // Rows: 'n' semesters, Columns: CGPA for 'm' students in a semester
	double max[];	 // Maximum in a semster for 'n' semesters

	public StudentThread (int n) {
		cgpa = new double[n][];
		max = new double[n];
	}

	public void input () {
		Scanner sc = new Scanner(System.in);
		for (int i = 0; i < cgpa.length; ++i) {
			System.out.print("\n\tEnter number of students in semester \'" + (i+1) + "\': ");
			int m = sc.nextInt();
			cgpa[i] = new double[m];
			System.out.print("\tEnter CGPA of " + m + " students in semester " + (i+1) + ": ");
			for (int j = 0; j < m; ++j)
				cgpa[i][j] = sc.nextDouble();
		}
	}

	public void run () {
		// Get the thread number that we put in main as string
		int tno = Integer.parseInt(Thread.currentThread().getName());

		// Calculate max for that semester and put that in the max array
		max[tno] = 0.0;
		for (int i = 0; i < cgpa[tno].length; ++i)
			if (cgpa[tno][i] > max[tno])
				max[tno] = cgpa[tno][i];
	}

	public double getAllMax () {
		double allMax = 0;
		for (double i : max)
			if (i > allMax)
				allMax = i;
		return allMax;
	}

}

public class StudentThreadTest {

	public static void main (String [] args) {
		
		Scanner sc = new Scanner(System.in);

		System.out.print("\n\tEnter the number of semesters: ");
		int n = sc.nextInt();

		StudentThread sthrd = new StudentThread(n);
		sthrd.input();

		// Create 'n' threads
		Thread threads[] = new Thread[n];

		for (int i = 0; i < n; ++i) {
			// Set title of the thread to string equivalent of 'i', we'll retrieve it later, and start the thread.
			threads[i] = new Thread(sthrd, ""+i);
			threads[i].start();
		}

		for (Thread thrd : threads) {
			try {
			 	thrd.join();
			}
			catch (Exception exception) {
				System.err.println("Error in threads: " + exception);
			}
		}

		System.out.println("\n\tAll time best GPA: " + sthrd.getAllMax());
	}
}