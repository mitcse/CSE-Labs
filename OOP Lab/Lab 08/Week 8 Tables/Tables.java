import java.io.*;

// using custom definitions of threads (i.e. not Thread t and super method)

class FiveThread extends Thread
{
	String name;
	int number;
	FiveThread (String name, int number)
	{
		this.name = name;
		this.number = number;
	}
	public void run()
	{
		try
		{
			System.out.println("Running " +name);
			for (int i=1; i<10; i++)
			{
				System.out.print(i + "*" +number +" = " +i*number + "\n");
				Thread.sleep(50);						// dictates how long thread waits before working again (in milliseconds)
			}
			System.out.println(" ");
		}
		catch (InterruptedException e) 
		{
			System.out.println("Table of " +number+ " interrupted\n");
		}
		System.out.println("Exiting table of " +number);
	}
}

class SevenThread extends Thread
{
	String name;
	int number;
	SevenThread (String name, int number)
	{
		this.name = name;
		this.number = number;
	}
	public void run()
	{
		try
		{
			System.out.println("Running " +name);
			for (int i=1; i<10; i++)
			{
				System.out.print(i + "*" +number +" = " +i*number + "\n");
				Thread.sleep(140);						// dictates how long thread waits before working again (in milliseconds)
			}
			System.out.println(" ");
		}
		catch (InterruptedException e)
		{
			System.out.println("Table of " +number+ " interrupted\n");
		}
		System.out.println("Exiting table of " +number);
	}
}


class Tables
{
	public static void main (String args[])
	{
		System.out.println("Starting thread of five");
		FiveThread Fivetable = new FiveThread ("FiveThread", 5);
		Fivetable.start();
		System.out.println("Starting thread of seven");
		SevenThread Seventable = new SevenThread ("SevenThread", 7);
		Seventable.start();
	}
}
