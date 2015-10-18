import java.util.*;

class AE2{
	static <T> void print(T[] a){
		System.out.print("Array contents: ");
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
		System.out.print("Integer array: ");
		print(i);
		
		System.out.print("Enter size of double array: ");
		Double[] d = new Double[s.nextInt()];
		System.out.print("Enter elements of double array: ");
		for(int x = 0;x<d.length;x++)
			d[x] = s.nextDouble();
		System.out.print("Double array: ");
		print(d);
	}
}
