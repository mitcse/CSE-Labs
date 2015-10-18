import java.util.*;

class AE1{
	public static <T> void swap(T[] a, int x, int y){
		T temp = a[x];
		a[x] = a[y];
		a[y] = temp;
	}
	public static <T> void display(T[] a){
		for(T x:a)
			System.out.print(x+" ");
		System.out.println();
	}
	public static void main(String args[]){
		Scanner s = new Scanner(System.in);
		
		System.out.print("Enter size of integer array: ");
		Integer[] i = new Integer[s.nextInt()];
		System.out.print("Enter elements of integer array: ");
		for(int x = 0;x<i.length;x++)
			i[x] = s.nextInt();
		System.out.print("Enter elements of integer array to swap: ");
		swap(i, s.nextInt(), s.nextInt());
		System.out.print("Swapped integer array: ");
		display(i);
		
		System.out.print("Enter size of double array: ");
		Double[] d = new Double[s.nextInt()];
		System.out.print("Enter elements of double array: ");
		for(int x = 0;x<d.length;x++)
			d[x] = s.nextDouble();
		System.out.print("Enter elements of double array to swap: ");
		swap(d, s.nextInt(), s.nextInt());		
		System.out.print("Swapped double array: ");
		display(d);
	}
}
