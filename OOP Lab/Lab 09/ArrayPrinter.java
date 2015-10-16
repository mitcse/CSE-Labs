import java.util.Scanner;
class ArrayPrinter
{
	public static <Gen> void display(Gen[] arr)
	{
		for(Gen item : arr)
		{
			System.out.println(item);
		}
	}

	public static void main(String args[])
	{
		Scanner userEntry = new Scanner(System.in);
		char choice;
		do
		{
			System.out.println("1 for integer array, 2 for double array, 3 for float array, 4 to exit");
			int ch = userEntry.nextInt();
			switch(ch)
			{
				case 1:
				{				
					System.out.println("Enter array size");
					int n = userEntry.nextInt();
					Integer intArray[] = new Integer[n];
					System.out.println("Elements?");
					for(int i=0;i<n;i++)
						intArray[i]=userEntry.nextInt();	
					System.out.println("Integer array is");
					display(intArray);
					break;
				}
				case 2:
				{
					System.out.println("Enter array size");
					int m = userEntry.nextInt();
					Double doubleArray[] = new Double[m];
					System.out.println("Elements?");
					for(int i=0;i<m;i++)
						doubleArray[i] = userEntry.nextDouble();				
					System.out.println("Double array is");
					display(doubleArray);
					break;
				}
				case 3:
				{
					System.out.println("Enter array size");
					int q = userEntry.nextInt();
					Float floatArray[] = new Float[q];
					System.out.println("Elements?");
					for(int i=0;i<q;i++)
						floatArray[i]=userEntry.nextFloat();
					System.out.println("Float array is");
					display(floatArray);
					break;
				}
				case 4:
				{
					System.exit(0);
				}
			}
			System.out.println("Want to go again? y/n");
			choice = userEntry.next().charAt(0);
		} while (choice == 'y');
	}
}
						
	 


