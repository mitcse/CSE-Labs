import java.util.*;
public class Pyramid {
	public static void main(String []args) {
		Scanner sc = new Scanner (System.in);
		System.out.println("Enter the number of lines in the pyramid: ");
		int n = sc.nextInt();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j)
				System.out.print(" *");
			System.out.println();
		}
	}	
}
