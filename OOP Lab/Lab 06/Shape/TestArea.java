import java.util.Scanner;

abstract class Figure
{
	double dim1;
	double dim2;
	abstract double area(double d1, double d2);
}

class Rectangle extends Figure
{
	double area(double dim1, double dim2)
	{
		return (dim1*dim2);
	}

}

class Triangle extends Figure
{
	double area(double dim1, double dim2)
	{
		return (0.5*dim1*dim2);
	}
}

class Square extends Figure
{
	double area(double dim1, double dim2)
	{
		return (dim1*dim2);
	}

}

class TestArea
{
	public static void main (String args[])
	{
		double a, b;
		Scanner userEntry = new Scanner(System.in);
		Rectangle r = new Rectangle();
		Triangle t = new Triangle();
		Square s = new Square();
		Figure figTest;
		System.out.print("Enter length and breadth of rectangle: ");
		figTest = r;
		a = userEntry.nextDouble();
		b = userEntry.nextDouble();
		System.out.println("Area is: " + figTest.area(a, b));

		System.out.print("Enter height and base of triangle: ");
		figTest = t;
		a = userEntry.nextDouble();
		b = userEntry.nextDouble();
		System.out.println("Area is: " + figTest.area(a, b));

		System.out.print("Enter side of square: ");
		figTest = s;
		a = userEntry.nextDouble();
		System.out.println("Area is: " + figTest.area(a, a));
	}
}
