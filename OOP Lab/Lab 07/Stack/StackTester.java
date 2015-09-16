import java.util.*;

interface Stack
{
	public void push (int ele);
	public int pop ();
}

class FixedStack implements Stack
{
	int  a[], top;

	FixedStack ()
	{
		Scanner userEntry = new Scanner (System.in);
		System.out.println("Enter fixed array size");
		int n = userEntry.nextInt();
		a = new int [n];
		top = -1;
	}

	public void push (int ele)
	{
		if (top == a.length-1)
		{
			System.out.println("Stack Overflow");
			return;
		}
		a[++top] = ele;
	}

	public int pop ()
	{
		if (top == -1)
		{
			System.out.println("Stack underflow");
			return -32767;
		}
		return a[top--];
	}

	void display()
	{
		System.out.println("Fixed stack is");
		for (int i=0; i<a.length; i++)
			System.out.println(a[i]);
	}
}

class DynamicStack implements Stack
{
	int a[], top;

	DynamicStack ()
	{
		Scanner userEntry = new Scanner (System.in);
		System.out.println("Enter initial dynamic array size");
		int n = userEntry.nextInt();
		a = new int[n];
		top = -1;
	}

	public void push (int ele)
	{
		if (top == a.length-1)
		{
			int temp [] = new int[(2*a.length)];
			for (int i=0; i<a.length; i++)
			{
				temp[i] = a[i];
			}
			a = temp;
			temp = null;
		}
		a[++top] = ele;
	}

	public int pop ()
	{
		if (top == -1)
		{
			System.out.println("Stack underflow");
			return -32767;
		}
		return a[top--];
	}

	void display()
	{
		System.out.println("Dynamic stack is");
		for (int i=0; i<a.length; i++)
			System.out.println(a[i]);
	}
}

class StackTester
{
	public static void main (String args[])
	{
		Scanner userEntry = new Scanner(System.in);

		FixedStack fs = new FixedStack();
		DynamicStack ds = new DynamicStack();

		char p;
		do
		{
			System.out.println("Enter stack you want to work on. 1 for static fixed, 2 for dynamic");
			int c = userEntry.nextInt();
			if (c == 1)
			{
				System.out.println("1 to push, 2 to pop, 3 to display");
				int x = userEntry.nextInt();
				if (x == 1)
				{
					System.out.println("Enter element");
					int e = userEntry.nextInt();
					fs.push(e);
				}
				else if (x == 2)
				{
					int delE = fs.pop();
					System.out.println("Deleted element is " +delE);
				}
				else if (x == 3)
					fs.display();
				else
					break;
			}

			if (c == 2)
			{
				System.out.println("1 to push, 2 to pop, 3 to display");
				int x = userEntry.nextInt();
				if (x == 1)
				{
					System.out.println("Enter element");
					int e = userEntry.nextInt();
					ds.push(e);
				}
				else if (x == 2)
				{
					int delE = ds.pop();
					System.out.println("Deleted element is " +delE);
				}
				else if (x == 3)
					ds.display();
				else
					break;
			}

			System.out.println("Go again? y/n");
			p = userEntry.next().charAt(0);
		}  while (p == 'y');
	}
}
