import java.util.Scanner;
public class Largest {
	public static void main(String []args) {
		Scanner sc = new Scanner (System.in);
		System.out.println("Enter three numbers: ");
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		System.out.println("Largest of "+a+", "+b+", and "+c+" is "+largest(a, b, c)+".");
	}
	static int largest(int a, int b, int c) {
		return (a>b)?((a>c)?a:c):((b>c)?b:c);
	}	
}
