package p1;
import p1.Max;
import java.util.Scanner;
public class Max2 {
	public static void main(String args[]) {
	Max trymax = new Max();
	int a,b,c;
	float a1,b1,c1;
	Scanner obj = new Scanner(System.in);
	
	int res;
	System.out.println("1. Find largest among interger \n2. Largest float \n3. Array\n 4. Matrix\nEnter choice: "); 
	int choice = obj.nextInt();
	switch(choice) {
	case 1:
		System.out.println("Enter the three numbers respectively: ");
		a=obj.nextInt();
		b=obj.nextInt();
		c=obj.nextInt();
		res = trymax.max(a,b,c);
		System.out.println("The largest number is: "+res);
	break;
	case 2 :
		System.out.println("Enter the three floating point integers: ");
		a1=obj.nextFloat();
		b1=obj.nextFloat();
		c1=obj.nextFloat();
		float res0=trymax.max(a1,b1,c1);
		System.out.println("The largest number is: "+res0);
	break;
	case 3 :
		System.out.println("Enter the number of array elements: ");
		int num = obj.nextInt();
		int array[] = new int[num];
		System.out.println("Enter the elements of the array: ");
		for(int i=0;i<num;i++) {
			array[i] = obj.nextInt();
		}
		res = trymax.max(array,num);
		System.out.println("The largest is: "+res);
	break;
	case 4 :
		System.out.println("Enter the number of rows and column of the matrix: ");
		int ro = obj.nextInt();
		int co = obj.nextInt();
		int matrix[][] = new int[ro][co];
		System.out.println("Enter the elements of the matrix: ");
		for(int i=0;i<ro;i++)
			for(int j=0;j<co;j++) 
				matrix[i][j]=obj.nextInt();
		res = trymax.max(matrix,ro,co);
		System.out.println("The largest is: "+res);
	break;
	
	}
	}
}		
