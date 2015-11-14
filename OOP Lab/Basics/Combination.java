import java.util.*;
public class Combination {
	static long fact(int n) {
		long fact = 1;
		for (int i = 1; i <= n; ++i)
			fact *= i;
		return fact;
	}
	public static void main(String []args) {
		Scanner sc = new Scanner (System.in);
		System.out.print("This program will compute the combination nCr.\nEnter \'n\': ");
		int n = sc.nextInt();
		while (n < 1 || n > 51) {
			System.out.print("\nInvalid range of \'n\'. Enter \'n\' in range (1-50): ");
			n = sc.nextInt();
		}
		System.out.print("\nEnter 'r': ");
		int r = sc.nextInt();
		while (r < 1 || r > 51 || r > n) {
			System.out.print("\nInvalid range of \'r\'. Enter \'r\' in range (1-50) [Must be smaller than \'n\']: ");
			r = sc.nextInt();
		}
		long comb = (long)(fact(n))/(fact(r)*fact(n-r));
		System.out.println("\nThe combination "+n+"C"+r+" = "+comb+".");
	}
}
