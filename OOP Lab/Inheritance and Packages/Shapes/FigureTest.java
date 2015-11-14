//
// FigureTest.java
// Abstract Class Figure: Rectangle, Square and Triangle
//

import java.util.*;

abstract class Figure {

	int dim1;
	int dim2;
	abstract double area(int dim1, int dim2);

	static void printStuff(){System.out.println("STATIC STUFF");}

	void printX (){System.out.println(" STUFF");}

}

class Rectangle extends Figure {

	double area(int dim1, int dim2) {
		return dim1 * dim2;
	}

	static void printStuff () {
		System.out.println("RECT STUFF");
	}

	void printX () {
		System.out.println("RECT X");
	}

}

class Triangle extends Figure {

	double area(int dim1, int dim2) {
		return 0.5 * dim1 * dim2;
	}

	static void printStuff () {
		System.out.println("TRI STUFF");
	}
}

class Square extends Figure {

	double area(int dim1, int dim2) {
		return dim1 * dim2;
	}

}

public class FigureTest {

	public static void main (String [] args) {

		int dim1, dim2;

		Scanner sc = new Scanner(System.in);

		Rectangle rectangle = new Rectangle();
		Triangle triangle = new Triangle();
		Square square = new Square();

		Figure figure;

		figure = rectangle;
		System.out.print("Enter length and breadth of rectangle: ");
		dim1 = sc.nextInt();
		dim2 = sc.nextInt();
		System.out.println("Rectangle area = " + figure.area(dim1, dim2));
		Rectangle.printStuff();
		figure.printX();
		Figure.printStuff();

		figure = triangle;
		System.out.print("Enter the base and height of triangle: ");
		dim1 = sc.nextInt();
		dim2 = sc.nextInt();
		System.out.println("Triangle area = " + figure.area(dim1, dim2));
		Triangle.printStuff();

		figure = square;
		System.out.print("Enter the side of the square: ");
		dim1 = sc.nextInt();
		System.out.println("Rectangle area = " + figure.area(dim1, dim1));
	}
}
