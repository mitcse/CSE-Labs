package p1;
import p1.Max;
import java.util.Scanner;
public class MaxTester
{
	public static void main(String args[])
	{
		Max m = new Max();
		int a,b,c;
		float a1,b1,c1;
		Scanner userEntry = new Scanner(System.in);

		int res;
		System.out.println("Enter 1 to find largest integer, 2 for floats, 3 for array, 4 for matrix"); 
		int choice = userEntry.nextInt();
		switch(choice)
		{
			case 1:
				System.out.println("Enter 3 integers");
				a = userEntry.nextInt();
				b = userEntry.nextInt();
				c = userEntry.nextInt();
				res = m.max(a,b,c);
				System.out.println("Largest = "+res);
				break;
			case 2 :
				System.out.println("Enter 3 floats");
				a1 = userEntry.nextFloat();
				b1 = userEntry.nextFloat();
				c1 = userEntry.nextFloat();
				float res1 = m.max(a1,b1,c1);
				System.out.println("Largest = "+res1);
				break;
			case 3 :
				System.out.println("Enter array size");
				int num = userEntry.nextInt();
				int array[] = new int[num];
				System.out.println("Enter array elements");
				for(int i=0;i<num;i++)
				{
					array[i] = userEntry.nextInt();
				}
				res = m.max(array,num);
				System.out.println("Largest = "+res);
				break;
			case 4 :
				System.out.println("Enter rows and columns");
				int ro = userEntry.nextInt();
				int co = userEntry.nextInt();
				int matrix[][] = new int[ro][co];
				System.out.println("Enter matrix");
				for(int i=0;i<ro;i++)
					for(int j=0;j<co;j++) 
						matrix[i][j]=userEntry.nextInt();
				res = m.max(matrix,ro,co);
				System.out.println("Largest = "+res);
				break;

		}
	}
}
