import java.util.Scanner;

class Complex
{

	double a, b;
	
	void getNumbers(double a, double b)
	{
		this.a = a;
		this.b = b;
	}

	void printNumbers()
	{
		System.out.println("Complex number is " +this.a+ " + i" +this.b);
	}

	Complex addNumbers(Complex c2)
	{
		Complex c3 = new Complex();
		c3.a = this.a + c2.a;
		c3.b = this.b + c2.b;
		return c3;
	}

	Complex diffOfNumbers(Complex c2)
	{
		Complex c4 = new Complex();
		c4.a = this.a - c2.a;
		c4.b = this.b - c2.b;
		return c4;
	}

}

class ComplexTest
{
	public static void main(String args[])
	{
		Scanner userEntry = new Scanner (System.in);
		char f, x;
		int flag;
		double a, b, c, d;
		f = 'y';
		while (f == 'y')
		{
			System.out.println("Enter first complex number");
			a = userEntry.nextDouble();
			b = userEntry.nextDouble();
			Complex c1 = new Complex();
			c1.getNumbers(a, b);

			c1.printNumbers();

			System.out.println("Do you want to enter another number? y or n?");
			x = userEntry.next().charAt(0);
			if (x == 'y')
			{
				System.out.println("Enter second complex number");

				c = userEntry.nextDouble();
				d = userEntry.nextDouble();
				Complex c2 = new Complex();
				c2.getNumbers(c, d);

				c2.printNumbers();

				System.out.println("Enter 1 to add, 2 to find difference");
				flag = userEntry.nextInt();


				if (flag == 1)
				{
					Complex c3 = new Complex();
					c3 = c1.addNumbers(c2);
					c3.printNumbers();
				}
				if (flag == 2)
				{
					Complex c3 = new Complex();
					c3 = c1.diffOfNumbers(c2);
					c3.printNumbers();
				}
			}

			System.out.println("Do you want to go again? y or n?");
			f = userEntry.next().charAt(0);
		}
	}
}

