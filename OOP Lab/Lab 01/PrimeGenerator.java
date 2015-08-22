import java.util.*;
public class PrimeGenerator {
	static boolean isPrime(int n) {
		for (int i = 2; i <= n/2; ++i)
			if (n%i == 0)
				return false;
		return true;
	}
	public static void main(String []args) {
		Scanner sc = new Scanner (System.in);
		System.out.print("This program will generate \'n\' prime numbers.\nEnter \'n\': ");
		int n = sc.nextInt();
		System.out.println("\n\tN\t|\tNth Prime\n\t\t|");
		int k = 1;
		for (int i = 2; k <= n; ++i)
			if (isPrime(i))
				System.out.println("\t"+(k++)+"\t|\t"+i);
		System.out.println("\n\nPeace Out!");
	}	
}
