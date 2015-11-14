import java.util.Scanner;

class BankAccount
{
	String name;
	int accNo;
	String accType;
	int accBalance;
	static float intRate;

	BankAccount()
	{
		System.out.println("Inside default constructor");
		this.name  = "John Doe";
		this.accNo = 42;
		this.accType = "Savings";
		this.accBalance = 500;
		this.intRate = 5;
		System.out.println("Bank account details\n" + this.name + "\n" + this.accNo + "\n" + this.accType + "\n" + this.accBalance);
	}

	BankAccount(String n, int an, String at, int ab)
	{
		System.out.println("Inside parametrized constructor with b2 account");
		name = n;
		accNo = an;
		accType = at;
		accBalance = ab;
		System.out.println("Bank account details\n" + this.name + "\n" + this.accNo + "\n" + this.accType + "\n" + this.accBalance);
	}

	BankAccount (BankAccount b1)
	{
		System.out.println("Inside copy constructor with b1 account");
		name = b1.name;
		accNo = b1.accNo;
		accType = b1.accType;
		accBalance = b1.accBalance;
		System.out.println("Bank account details\n" + this.name + "\n" + this.accNo + "\n" + this.accType + "\n" + this.accBalance);
	}

	void depositMoney (int m)
	{
		this.accBalance += m;
	}

	void makeWithdrawal (int m)
	{
		if (m > accBalance)
		{
			System.out.println("Not enough money, cannot make withdrawal");
		}
		else
		{
			this.accBalance -= m;
		}
	}

	void printDetails()
	{
		System.out.println("Bank account details\n" + "Name : " +this.name + "\n" + "Account Number : " + this.accNo + "\n" + "Account type : " + this.accType + "\n" + "Account Balance : " + this.accBalance);
	}

	static void displayRate()
	{
		System.out.println("Interest rate is " +intRate);
	}

	public static void main(String args[])
	{

		Scanner userEntry = new Scanner (System.in);

		BankAccount b1 = new BankAccount();
		System.out.println("Enter name of account holder");
		String nam = new String();
		nam = userEntry.next();
		System.out.println("Enter account number");
		int acn;
		acn = userEntry.nextInt();
		System.out.println("Enter account type. Savings or Current?");
		String act = new String();
		act = userEntry.next();
		System.out.println("Enter account balance");
		int bal;
		bal = userEntry.nextInt();
		BankAccount b2 = new BankAccount(nam, acn, act, bal);
		BankAccount b3 = new BankAccount(b1);

		displayRate();

		int deposit, withdraw, flag;
		System.out.println("1 to deposit, 2 to withdraw");
		flag = userEntry.nextInt();
		if (flag == 1)
		{
			System.out.println("Enter money you want to deposit in account 1");
			deposit = userEntry.nextInt();
			b1.depositMoney(deposit);
			b1.printDetails();
		}
		if (flag == 2)
		{
			System.out.println("Enter money you want to withdraw from account 2");
			withdraw = userEntry.nextInt();
			b2.depositMoney(withdraw);
			b2.printDetails();
		}
	}
}
