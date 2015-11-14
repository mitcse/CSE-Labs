import java.util.Scanner; 
public class ReverseArray {
    public static void main (String [] args) {
        Scanner sc = new Scanner (System.in);
        System.out.print("Enter the length of the integer array: ");
        System.out.println();
        int n = sc.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.print("\tEnter a["+i+"] : ");
            arr[i] = sc.nextInt();
        }
        System.out.println("\nOriginally : ");
        printArray(arr);
        for (int i = 0; i < n/2; i++) {
            int temp = arr[i];
            arr[i] = arr[n-1-i];
            arr[n-1-i] = temp;
        }
        System.out.println("\nAfter reversing: ");
        printArray(arr);
    }
    static void printArray (int a[]) {
        System.out.println();
        for (int i = 0; i < a.length; i++) {
            System.out.print("\t"+a[i]);
        }
        System.out.println();
    }
}
