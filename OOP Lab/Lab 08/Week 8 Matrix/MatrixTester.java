import java.util.Scanner;

class Matrix implements Runnable
{
	String name;
	public int rows, sum = 0;
	int a[];
	Thread t;
	Matrix (String threadName, int n)
	{
		Scanner entry = new Scanner (System.in);
		name = threadName;
		rows = n;
		a = new int[n];
		System.out.println("Enter elements");
		for (int i=0; i<n; i++)
		{
			a[i] = entry.nextInt();
		}
		t = new Thread (this, name);
		System.out.println("New thread : " +t);
		t.start();
	}

	public void run ()
	{
		try
		{
			for (int i=0; i<rows; i++)
			{
				sum = sum + a[i];
				Thread.sleep (10);
			}
			System.out.println("Indi sum " +sum);
		}
		catch (InterruptedException e)
		{
			System.out.println(name + "interrupted");
		}

		for (int i=0; i<rows; i++)
		{
			sum = sum + a[i];
		}
	}
}

class MatrixTester
{
	public static void main(String args[])
	{
		int objC;
		Scanner userEntry = new Scanner (System.in);
		System.out.println("Enter number of rows you want");
		objC = userEntry.nextInt();
		Matrix mat[] = new Matrix[objC];
		for (int i=0; i<objC; i++)
		{
			System.out.println("Enter thread name and number of elements in a row");
			String tName = userEntry.next();
			int rowS = userEntry.nextInt();
			mat[i] = new Matrix (tName, rowS);
		}
		int s = 0;
		try
		{
			for (int i=0; i<objC; i++)
			{
				System.out.println("Matrix print " +mat[i].sum);
				s = s + mat[i].sum;
			}
		}
		catch (InterruptedException e)
		{
			System.out.println("Interrupting");
		}
		System.out.println("Total sum is " +s);
	}
}
