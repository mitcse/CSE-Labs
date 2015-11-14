import java.util.Scanner;
import java.io.*;

class PushException extends Exception
{
	PushException()
	{
		System.out.println("Stack Overflow");
	}

}


class PopException extends Exception
{
	PopException()
	{
		System.out.println("Stack Underflow");
	}

}

class Stack
{
	int st[];
	int tos;
	int MAX;

	Stack()
	{
		Scanner userEntry = new Scanner(System.in);
		System.out.print("Enter size to be allocated for stack: ");
		MAX = userEntry.nextInt();	
		st = new int[MAX];
		tos = -1;
		
	}	


	void push(int ele) throws PushException
	{
		if(tos == MAX-1)
			throw new PushException();
		else
			st[++tos] = ele;		
	}

	void pop() throws PopException
	{
		if (tos == -1)
			throw new PopException();
		else
			System.out.println("Popped element: " + st[tos--]);

	}

	void disp()
	{
		for(int i = 0; i<=tos; i++)
			System.out.print(st[i]+"-> ");
		
	}

	public static void main(String[] args)
	{
		Scanner entry = new Scanner(System.in);
		Stack s = new Stack();
		char ch = '1';
		do
		{
			System.out.print("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ");
			ch = entry.next().charAt(0);
			switch(ch)
			{
				case '1': try
					{
						System.out.print("Enter element: ");
						s.push(entry.nextInt());
						break;
					}
					catch(PushException e)
					{
						break;
					}
				case '2': try
					{
						s.pop(); 
						break;
					}
					catch(PopException e)
					{
						break;
					}
				case '3': s.disp();
					  break;
				case '4': System.exit(0);

			}
		} while(ch!='4');
			
	}
}
