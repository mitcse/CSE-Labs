import java.util.Scanner;

class Customer
{
	private int customerID;
	private String customerName;
	private double creditLimit;

	Customer (int id, String name, double limit)
	{
		this.customerID = id;
		this.customerName = name;
		this.creditLimit = limit;
	}

	void display()
	{
		System.out.println("Customer details are : ");
		System.out.println("ID : " + this.customerID);
		System.out.println("Name : " + this.customerName);
		System.out.println("Credit Limit : " + this.creditLimit);
	}

	public static void main(String args[])
	{
		Scanner userEntry = new Scanner (System.in);
		int n, custID;
		String custName;
		double cred;
		System.out.println("Enter number of customers you want");
		n = userEntry.nextInt();
		Customer c[] = new Customer[n];
		for (int i=0; i<n; i++)
		{
			System.out.println("Enter customer id");
			custID = userEntry.nextInt();
			System.out.println("Enter customer name");
			custName = userEntry.next();
			System.out.println("Enter credit limit");
			cred = userEntry.nextDouble();
			c[i] = new Customer(custID, custName, cred);
		}
		for (int i=0; i<n; i++)
		{
			c[i].display();
		}
	}
}
