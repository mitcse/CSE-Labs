import java.util.*;

class Data {
	private int value;
	private boolean available = false;
	public synchronized int get() {
		while (available == false) {
			try {
				wait();
			}
			catch (InterruptedException e) {
			}
		}
		available = false;
		notifyAll();
		return value;
	}
	public synchronized void put(int value) {
		while (available == true) {
			try {
				wait();
			}
			catch (InterruptedException e) { 
			} 
		}
		this.value = value;
		available = true;
		notifyAll();
	}
}

class Producer extends Thread {
	private Data data;

	public Producer(Data c) {
		data = c;
	}

	public void run() {
		for (int i = 0; i < 10; i++) {
			data.put(i);
			System.out.println("Put: " + i);
		}
	}
}

class Consumer extends Thread {
	private Data data;
	public Consumer(Data c) {
		data = c;
	}
	public void run() {
		int value = 0;
		for (int i = 0; i < 10; i++) {
			value = data.get();
			System.out.println("Got: " + value);
		}
	}
}

public class P3{
	public static void main(String[] args) {
		Data c = new Data();
		Producer p1 = new Producer(c);
		Consumer c1 = new Consumer(c);
		p1.start(); 
		c1.start();
	}
}
