//
//
//
//
//
//
//

import java.io.*;
import java.util.*;

class Counter {

	private int count;

	public Counter () {
		count = 0;
	}

	public synchronized void increment () {
		try {
			if (count < 3) {
				count++;
				notify();
			}
			else {
				wait();
				System.out.println("\tWaiting(+)...");
			}
			System.out.println("\tCount(+): " + count);
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

	public synchronized void decrement () {
		try {
			if (count > 0) {
				count--;
				notify();
			}
			else {
				wait();
				System.out.println("\tWaiting(-)...");
			}
			System.out.println("\tCount(-): " + count);
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

}

class IncThread extends Thread {

	Counter counter;

	public IncThread (String name, Counter counter) {
		super(name);
		this.counter = counter;
		start();
	}

	@Override
	public void run () {
		try {
			for (int i = 0; i < 50; ++i) {
				counter.increment();
				Random random = new Random();
				Thread.sleep(random.nextInt(250) + 250);	
			}
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

}

class DecThread extends Thread {

	Counter counter;

	public DecThread (String name, Counter counter) {
		super(name);
		this.counter = counter;
		start();
	}

	@Override
	public void run () {
		try {
			for (int i = 0; i < 50; ++i) {
				counter.decrement();
				Random random = new Random();
				Thread.sleep(random.nextInt(250) + 250);	
			}
		}
		catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

}

public class CounterTest {

	public static void main (String [] args) {
		
		Counter counter = new Counter();

		IncThread incThread = null;
		DecThread decThread = null;

		try {

			incThread = new IncThread("IncThread", counter);
			decThread = new DecThread("DecThread", counter);

		}
		catch (Exception e) {
			e.printStackTrace();
		}

	}

}