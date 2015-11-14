import java.util.*;
public class Armstrong {
	static boolean isArmstrong(int n) {
		if (n == sumDigitsCube(n))
			return true;
		return false;
	}
	static int sumDigitsCube(int n) {
		if (n == 0)
			return 0;
		return (int)Math.pow(n%10, 3) + sumDigitsCube(n/10);
	}
	public static void main(String []args) {
		Scanner sc = new Scanner (System.in);
		System.out.print("This program will check if the inputted number is an Armstrong number or not.\n\n\tEnter a number: ");
		int n = sc.nextInt();
		if (isArmstrong(n))
			System.out.println("\n\t"+n+" is an Armstrong number. :)\n\n");
		else
			System.out.println("\n\t"+n+" is not an Armstrong number. :(\n\n");
	}	
}
