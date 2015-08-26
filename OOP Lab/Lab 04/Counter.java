import java.util.Scanner;

class Counter
{
	static int countObjects = 0;

	static void showCount()
	{
		System.out.println("Number of static objects right now are " +countObjects);
	}

	Counter ()
	{
		countObjects++;
	}

	public static void main(String args[])
	{
		Counter c1 = new Counter();
		showCount();
		Scanner userEntry = new Scanner(System.in);
		char f;
		System.out.println("Do you want to keep adding classes? y/n");
		f = userEntry.next().charAt(0);
		while (f == 'y')
		{
			Counter c = new Counter();
			showCount();
			System.out.println("Do you want to keep adding classes? y/n");
			f = userEntry.next().charAt(0);
		}
			
	}
}
