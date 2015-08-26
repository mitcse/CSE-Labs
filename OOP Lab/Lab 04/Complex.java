import java.util.Scanner;

class Complex
{

	double a, b;

	Complex()
	{
		System.out.println("Inside default constructor");
		this.a = 50;
		this.b = 75;
		System.out.println("The values entered/assigned are " +a + " " +b);
	}
	
	Complex (double a, double b)
	{
		System.out.println("Inside parametrized constructor");
		this.a = a;
		this.b = b;
		System.out.println("The values entered/assigned are " +this.a +" " +this.b);
	}

	void printNumbers()
	{
		System.out.println("Complex number is " +this.a+ " + i" +this.b);
	}

	Complex (Complex c2)
	{
		System.out.println("Inside copy constructor");
		a = c2.a;
		b = c2.b;
		System.out.println("The values entered/assigned are " +a +" " +b);
	}

	public static void main(String args[])
	{
		Complex c1 = new Complex();
		c1.printNumbers();
		Complex c2 = new Complex(10, 20);
		c2.printNumbers();
		Complex c3 = new Complex(c2);
		c3.printNumbers();
	}
}

