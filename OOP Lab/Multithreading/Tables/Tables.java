//
//	Tables.java
//
//	Created by Avikant Saini on 10/06/15
//

import java.util.*;

class Table {
	
	public static synchronized void printTable (int n, int k) throws InterruptedException {
		for (int i = 1; i <= k; ++i) {
			System.out.printf("\t%4d x %d\t= %4d\n", n, i, n*i);
			Thread.sleep(250);
			if (i == k)
				System.out.println();
		}
	}

}

class TableThread extends Thread {

	Table table;
	int n;
	int k;
	
	public TableThread (String threadName, int n, int k, Table table) {
		super(threadName);
		this.n = n;
		this.k = k;
		this.table = table;
		start();
	}

	@Override
	public void run () {
		try {
			Table.printTable(n, k);
		}
		catch (InterruptedException e) {
			System.err.println("Thread Interrupted: " + e);
		}
	}

}


public class Tables {

	public static void main (String [] args) {
	
		Scanner sc = new Scanner(System.in);
		System.out.print("\n\tHow many tables do you want to print: ");
		int l = sc.nextInt();
		int arr[] = new int[l];
		
		System.out.print("\tEnter the elements: ");
		for (int i = 0; i < l; ++i)
			arr[i] = sc.nextInt();
			
		System.out.print("\tEnter the table limit: ");
		int k = sc.nextInt();
		
		System.out.println();
		
		Table table = new Table();
		
		TableThread tableThreads[] = new TableThread[l];
		
		for (int i = 0; i < l; ++i)
			tableThreads[i] = new TableThread("Thread"+arr[i], arr[i], k, table);

	}

}
