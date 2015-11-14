 //
//	ExchangeTest.java
//	Inclusive of 
//
//	Created by Avikant Saini on 10/17/15
//

class GArray <Type> {

	public static <Type> void exchange (Type [] arr, int a, int b) {
		
		Type temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
			
	}
	
	public static <Type> void display (Type [] arr) {
		
		for (Type obj: arr)
			System.out.print("\t" + obj);
		System.out.println();
		
	}
	
}

public class ExchangeTest {

	public static void main (String [] args) {
	
		Integer intArray[] = {1, 2, 4, 5, 7, 8};
		Double doubleArray[] = {11.23, 65.36, 53.21};
		String stringArray[] = {"Herp", "Derp", "Land", "Yolo"};
		
		System.out.println("\n\tInitally: ");
		GArray.display(intArray);
		GArray.display(doubleArray);
		GArray.display(stringArray);
		
		System.out.println("\n\tSwapping indices '1' and '2': ");
		
		GArray.exchange(intArray, 1, 2);
		GArray.exchange(doubleArray, 1, 2);
		GArray.exchange(stringArray, 1, 2);
		
		GArray.display(intArray);
		GArray.display(doubleArray);
		GArray.display(stringArray);
	
	}

}
