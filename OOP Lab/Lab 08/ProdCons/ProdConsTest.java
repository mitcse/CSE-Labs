//
//	ProdConsTest.java
//
//	Created by Avikant Saini on 10/06/15
//

import java.util.Scanner;

class Thing {

	private int count;
	private boolean isAvailable;

	public Thing () {
		count = 0;
		isAvailable = false;
	}

	public synchronized int get () {
		while (!isAvailable) {
			try {
				wait();
			}
			catch (InterruptedException e) {
				System.err.println("Interrupted: " + e);
			}
		}
		isAvailable = false;
		notify();
		return count;
	}

	public synchronized void put (int n) {
		while (isAvailable) {
			try {
				wait();
			}
			catch (InterruptedException e) {
				System.err.println("Interrupted: " + e);
			}
		}
		count = n;
		isAvailable = true;
		notify();
	}

}

class Producer extends Thread {

	private Thing thing;
	private int n;

	public Producer (Thing thing, int n) {
		this.thing = thing;
		this.n = n;
		start();
	}

	@Override
	public void run () {
		for (int i = 1; i <= n; ++i) {
			try {
				thing.put(i);
				System.out.println("\tProducer - Put -> " + i + " | ");
				sleep(20);
			}
			catch (InterruptedException e) {
				System.err.println("Interrupted: " + e);
			}
		}
	}

}

class Consumer extends Thread {

	private Thing thing;
	private int n;

	public Consumer (Thing thing, int n) {
		this.thing = thing;
		this.n = n;
		start();
	}

	@Override
	public void run () {
		for (int i = 1; i <= n; ++i) {
			try {
				int no = thing.get();
				System.out.println("\t                | " + i + " -> Get - Consumer\n");
				sleep(20);
			}
			catch (InterruptedException e) {
				System.err.println("Interrupted: " + e);
			}
		}
	}

}

public class ProdConsTest {

	public static void main (String [] args) {
		
		Scanner sc = new Scanner(System.in);
		System.out.print("\n\tEnter number of items: ");
		int n = sc.nextInt();

		System.out.println("\n");

		Thing thing = new Thing();

		Producer producer = new Producer(thing, n);
		Consumer consumer = new Consumer(thing, n);

	}

}

