// By Saket Singh

import java.util.*;
import java.io.*;

class Add1{
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter size of string array: ");
		int size = sc.nextInt();
		String[] arr = new String[size];
		sc.nextLine();
		for(int i = 0; i<size; i++){
			System.out.print("Enter at position "+ i + ": ");
			arr[i] = sc.nextLine();
		}
		
		System.out.print("Enter position 1: ");
		int p1 = sc.nextInt();
		System.out.print("Enter position 2: ");
		int p2 = sc.nextInt();
		
		A1.<String>swap(arr, p1, p2);
		for(int i = 0; i<size; i++){
			System.out.print(arr[i] +" -> ");
		}
		System.out.println();
	}
	
	
	public static <T> void swap(T[] a, int i, int j){
		T temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	} 
}
