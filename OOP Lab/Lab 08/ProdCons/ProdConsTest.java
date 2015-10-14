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

	public void run ()
	{
		for (int i = 1; i <= n; ++i)
		{
			try
			{
				randomClassInstance.put(i);
				System.out.println("Producer Put\t" + i + "\n");
				sleep(20);
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

	public void run ()
	{
		for (int i = 1; i <= n; ++i)
		{
			try
			{
				int no = randomClassInstance.get();
				System.out.println("\n" + i + "Get Consumer\n");
				sleep(20);
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