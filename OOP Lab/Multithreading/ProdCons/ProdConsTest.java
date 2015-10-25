import java.util.Scanner;

class RandomClassName
{
	private int count;
	private boolean isAvailable;

	public RandomClassName ()
	{
		count = 0;
		isAvailable = false;
	}

	public synchronized int get ()
	{
		while (!isAvailable)
		{
			try
			{
				wait();
			}
			catch (InterruptedException e)
			{
				System.err.println("Interrupted: " + e);
			}
		}
		isAvailable = false;
		notify();
		return count;
	}

	public synchronized void put (int n)
	{
		while (isAvailable)
		{
			try
			{
				wait();
			}
			catch (InterruptedException e)
			{
				System.err.println("Interrupted: " + e);
			}
		}
		count = n;
		isAvailable = true;
		notify();
	}
}

class Producer extends Thread
{
	private RandomClassName randomClassInstance;
	private int n;

	public Producer (RandomClassName randomClassInstance, int n)
	{
		this.randomClassInstance = randomClassInstance;
		this.n = n;
		start();
	}

<<<<<<< HEAD
	@Override
	public void run () {
		for (int i = 1; i <= n; ++i) {
			try {
				thing.put(i);
				System.out.println("\tProducer - Put -> " + i + " | ");
				sleep(100);
=======
	public void run ()
	{
		for (int i = 1; i <= n; ++i)
		{
			try
			{
				randomClassInstance.put(i);
				System.out.println("Producer Put\t" + i + "\n");
				sleep(20);
>>>>>>> d6ac074a70ec617e4f0f912c585adb3ed3ac1e55
			}
			catch (InterruptedException e)
			{
				System.err.println("Interrupted: " + e);
			}
		}
	}
}

class Consumer extends Thread
{
	private RandomClassName randomClassInstance;
	private int n;

	public Consumer (RandomClassName randomClassInstance, int n)
	{
		this.randomClassInstance = randomClassInstance;
		this.n = n;
		start();
	}

<<<<<<< HEAD
	@Override
	public void run () {
		for (int i = 1; i <= n; ++i) {
			try {
				int no = thing.get();
				System.out.println("\t                | " + i + " -> Get - Consumer\n");
				sleep(200);
=======
	public void run ()
	{
		for (int i = 1; i <= n; ++i)
		{
			try
			{
				int no = randomClassInstance.get();
				System.out.println("\n" + i + "Get Consumer\n");
				sleep(20);
>>>>>>> d6ac074a70ec617e4f0f912c585adb3ed3ac1e55
			}
			catch (InterruptedException e)
			{
				System.err.println("Interrupted: " + e);
			}
		}
	}
}

public class ProducerConsumer
{
	public static void main (String args[])
	{
		
		Scanner userEntry = new Scanner(System.in);
		System.out.print("\nEnter number of items\n");
		int n = userEntry.nextInt();

		System.out.println("\n");

		RandomClassName randomClassInstance = new RandomClassName();

		Producer producer = new Producer(randomClassInstance, n);
		Consumer consumer = new Consumer(randomClassInstance, n);
	}
}