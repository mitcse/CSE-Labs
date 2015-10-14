import java.util.Scanner;

class Stack <Gen>
{
    	private Gen obj[];
	private int top;

    	Stack(int n)
	{
        	obj= (Gen[]) new Object[n];
        	top= -1;
    	}

    	void push(Gen o)
	{
        	obj[++top]=o;
    	}

	void display ()
	{
		if (top == -1)
			System.out.println("Stack is Empty");
		else
		{
			for (int i=0; i<=top; i++)
				System.out.println(obj[i]);
		}
	}
}

class Student
{
    	private String name;
    	private double cgpa;

    	Student()
	{
        	Scanner userEntry = new Scanner(System.in);
	        System.out.println("Enter name and cgpa");
	        name = userEntry.nextLine();
	        cgpa = userEntry.nextDouble();
    	}

    	public String toString()
	{
        	return "Name:"+name+"\nCGPA:"+cgpa;
    	}
}


class Employee
{
    	private String name;
    	private int empID;

    	Employee()
	{
        	Scanner userEntry = new Scanner(System.in);
        	System.out.println("Enter name and employee id");
        	name = userEntry.nextLine();
        	empID = userEntry.nextInt();
    	}

    	public String toString()
	{
        	return "Name: "+name+"\nID: "+empID;
    	}
}

public class StackClass
{
	public  static  void main (String args[])
	{
	        Scanner userEntry = new Scanner(System.in);
		char choice;
		do
		{
	        	System.out.println("Enter 1 for students and 2 for employees");
	        	int ch = userEntry.nextInt();
	        	System.out.println("Enter the no. of values");
	        	int n = userEntry.nextInt();
	        	if (ch == 1)
			{
	        	        Stack <Student> stack = new Stack <> (n);
	        	        for(int i=0;i<n;i++)
        	       	 		stack.push(new Student());
	                	System.out.println("List of students is");
	                	stack.display();
        		}
        		else if (ch == 2)
			{
            			Stack <Employee> stack = new Stack<>(n);
            			for(int i=0;i<n;i++)
                			stack.push(new Employee());
            			System.out.println("List of employees is");
            			stack.display();
        		}
			System.out.println("Go again? y/n?");
			choice = userEntry.next().charAt(0);
		} while (choice == 'y');
	}
}
