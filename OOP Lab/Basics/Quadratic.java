import java.util.*;
public class Quadratic {
	public static void main(String []args) {
		Scanner sc = new Scanner (System.in);
		double a, b, c, d, x1, x2;
		
		System.out.print("This program will compute the roots of the quadratic equation:\n\t\tax\u00B2 + bx + c = 0\n\n\tEnter 'a': ");
		a = sc.nextDouble();
		System.out.print("\tEnter 'b': ");
		b = sc.nextDouble();
		System.out.print("\tEnter 'c': ");
		c = sc.nextDouble();
		
		d = b*b - 4*a*c;
		
		// '0' for equal, '1' for distinct, and '2' for imaginary
		int roots = (d == 0)?0:((d>0)?1:2);
		switch (roots) {
			case 0: x1 = -b/(2*a);
				System.out.println("\nThe roots of \'"+a+"x\u00B2 + "+b+"x + "+c+" = 0\' are real and equal.\n\tRoots = "+x1+".");
				break;
			case 1: d = Math.sqrt(d);
				x1 = (-b+d)/(2*a);
				x2 = (-b-d)/(2*a);
				System.out.println("\nThe roots of \'"+a+"x\u00B2 + "+b+"x + "+c+" = 0\' are real and distinct.\n\tRoots = "+x1+", "+x2+".");
				break;
			case 2: d = Math.sqrt(Math.abs(d));
				x1 = -b/(2*a);
				x2 = d/(2*a);
				System.out.println("\nThe roots of \'"+a+"x\u00B2 + "+b+"x + "+c+" = 0\' are complex conjugates.\n\tRoots = \t"+x1+" + "+x2+"i\n\t\t\t"+x1+" - "+x2+"i.");
				break;
			default:
				break;
		}
	}	
}
