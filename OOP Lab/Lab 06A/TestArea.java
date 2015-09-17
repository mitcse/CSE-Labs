import java.util.Scanner;

abstract class Figure{
	double dim1;
	double dim2;
	abstract double area(double d1, double d2);
}

class Rectangle extends Figure{
	double area(double d1, double d2){
		return (d1*d2);
	}

}

class Triangle extends Figure{
	double area(double d1, double d2){
		return (0.5*d1*d2);
	}
}

class Square extends Figure{
	double area(double d1, double d2){
		return (d1*d2);
	}

}

class TestArea{
	public static void main(String[] args){
		double a, b;
		Scanner sc = new Scanner(System.in);
		Rectangle rect = new Rectangle();
		Triangle tri = new Triangle();
		Square sq = new Square();
		Figure ftest;
		System.out.print("Enter dimensions for rectangle: ");
		ftest = rect;
		a = sc.nextDouble();
		b = sc.nextDouble();
		System.out.println("Area is: " + ftest.area(a, b));

		System.out.print("Enter dimensions for triangle: ");
		ftest = tri;
		a = sc.nextDouble();
		b = sc.nextDouble();
		System.out.println("Area is: " + ftest.area(a, b));

		System.out.print("Enter dimension for square: ");
		ftest = sq;
		a = sc.nextDouble();
		System.out.println("Area is: " + ftest.area(a, a));

		

	}
}
