//
//	Tables.java
//
//	Created by Avikant Saini on 10/06/15
//

class Table5 extends Thread {

	Table5 (String name) {
		super(name);
		start();
	}

	@Override
	public void run () {
		try {
			for (int i = 1; i <= 10; ++i) {
				System.out.printf("\t%d * %d\t= %d\n", i, 5, i*5);
				Thread.sleep(500);
			}
		}
		catch (InterruptedException e) {
			System.err.println("Thread Interrupted: " + e);
		}
	}

}

class Table7 extends Thread {

	Table7 (String name) {
		super(name);
		start();
	}

	@Override
	public void run () {
		try {
			for (int i = 1; i <= 10; ++i) {
				System.out.printf("\t%d * %d\t= %d\n", i, 7, i*7);
				Thread.sleep(500);
			}
		}
		catch (InterruptedException e) {
			System.err.println("Thread Interrupted: " + e);
		}
	}

}

public class Tables {

	public static void main (String [] args) {
		
		Table5 fiveTable = new Table5("fiveTable");
		Table7 sevenTable = new Table7("sevenTable");

	}

}