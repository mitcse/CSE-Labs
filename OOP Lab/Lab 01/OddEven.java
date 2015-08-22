import java.util.*;
public class OddEven {
	static boolean isEven(int n) {
		if (n > 1 && n%2 == 0)
			return true;
		return false;
	}
	public static void main(String []args) {
		Scanner sc = new Scanner (System.in);
		System.out.print("\nThis program will count the odd and even numbers from \'n\' numbers.\n\tEnter \'n\': ");
		int n = sc.nextInt();
		System.out.println("\nEnter "+n+" numbers :");
		int i, oc = 0, ec = 0, nc = 0;
		for (i = 0; i < n; ++i) {
			int k = sc.nextInt();
			if (isEven(k))
				++ec;
			else if (k == 1)
				++nc;
			else
				++oc;
		}
		System.out.println("\n\n\tTotal numbers entered \t= "+n+"\n\t\tEven numbers \t= "+ec+"\n\t\tOdd numbers \t= "+oc+"\nNeither odd nor even numbers \t= "+nc+"\n\n");
	}	
}
