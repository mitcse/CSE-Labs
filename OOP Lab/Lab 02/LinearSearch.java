import java.util.Scanner;
public class LinearSearch {
    public static void main (String [] args) {
        Scanner sc = new Scanner (System.in);
        System.out.print("Enter the length of the integer array: ");
        int n = sc.nextInt();
        System.out.println();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.print("\tEnter a["+i+"] : ");
            arr[i] = sc.nextInt();
        }
        System.out.print("\n\tEnter element to be searched: ");
        int x = sc.nextInt();
        int pos = linearSearch(arr, x);
        if (pos == -1)
            System.err.println("404. NOT FOUND");
        else
            System.out.println(x + " found at index " + pos);
    }
    static int linearSearch (int a[], int x) {
        for (int i = 0; i < a.length; i++) {
            if (x == a[i])
                return i;
        }
        return -1;
    }
}