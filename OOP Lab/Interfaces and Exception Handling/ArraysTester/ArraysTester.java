import java.util.*;
import java.io.*;

class Arrays
{
	int a[];
	int n;
	Arrays ()
	{
		Scanner userEntry = new Scanner (System.in);
		System.out.println("Enter array size");
		n = userEntry.nextInt();
		a = new int [n];
		System.out.println("Enter array now");
		for (int i=0; i<n; i++)
		{
			a[i] = userEntry.nextInt();
		}
	}

	int getValue (int ind)
	{
		return a[ind];
	}
}

class ArraysTester
{
	public static void main(String args[])
	{
		Arrays arr = new Arrays();
		Scanner userEntry = new Scanner (System.in);
		System.out.println("Enter index you want a value from");
		int i = userEntry.nextInt();
		try
		{
			int ans = arr.getValue(i-1);
			System.out.println(ans);
		}
		catch (ArrayIndexOutOfBoundsException e)
		{
			System.out.println("Index is out of bounds. Sorry.");
			System.out.println("First element is " +arr.getValue(0));
		}
	}
}
