import java.util.Scanner;

class Link <Gen>
{
	private Gen obj;
	Link next;

	Link()
	{
        	this.next=null;
	}

	void insert(Gen o, Link root)
	{
		Link node = new Link();
        	node.obj=o;
        	Link temp = root;
        	while(temp.next != null)
            		temp=temp.next;
        	temp.next=node;
	}

	void display(Link root)
	{
        	Link temp = root.next;
        	if(temp==null)
        	{
			System.out.print("EMPTY!");
            		return;
		}
        	while(temp!=null)
		{
                	System.out.print(temp.obj + "\t");
            		temp=temp.next;
		}
	}
}

public class ListClass
{
        public static void main(String args[])
	{
		char choice;
		Scanner userEntry = new Scanner(System.in);
		Link <Integer> headerInteger = new Link <> ();
		Link <Double> headerDouble = new Link <> ();
                Link <Integer> iOb= new Link <> ();
                Link <Double> dOb = new Link<>();
		do
		{
			System.out.println("1 to enter integer values, 2 to input double type values");
			int ch = userEntry.nextInt();
			if (ch != 1 || ch != 2)
			{
				System.out.println("Invalid input...bye bye");
				System.exit(0);
			}
	        	if (ch == 1)
			{
                		System.out.println("Enter the integer to be inserted");
                		int n = userEntry.nextInt();
                		iOb.insert(n, headerInteger);
            		}
            		else if (ch == 2)
			{
                		System.out.println("Enter the double integer to be inserted");
                		double n = userEntry.nextDouble();
                		dOb.insert(n, headerDouble);
            		}
			System.out.println("Want to go again? y/n?");
			choice = userEntry.next().charAt(0);
		} while (choice == 'y');
		System.out.println("Integer list is");
		iOb.display(headerInteger);
		System.out.println("");
		System.out.println("Double list is");
		dOb.display(headerDouble);
		System.out.println("");
        }
}
