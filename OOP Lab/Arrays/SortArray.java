import java.util.Scanner;
public class SortArray {
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
        System.out.println("\nOriginally : ");
        printArray(arr);

        System.out.print("\n\t1. Ascending Order\n\t2. Descending Order\n\t3. Anything else for exit.\nEnter your choice: ");
        char ch = sc.next().charAt(0);
        switch (ch) {
            case '1': {
                System.out.println("You chose... Ascending.");
                sortArray(arr, true);
                break;
            }
            case '2': {
                System.out.println("You chose... Descending.");
                sortArray(arr, false);
                break;
            }
            default : {
                System.exit(0);
            }
        }

        System.out.println("\nAfter sorting: ");
        printArray(arr);
    }
    static void sortArray (int a[], boolean ascending) {
        for (int i = 0; i < a.length; ++i) {
            for (int j = 0; j < a.length - 1 - i; ++j) {
                if (ascending ^ (a[j] < a[j+1])) {
                    int temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
    }
    static void printArray (int a[]) {
        System.out.println();
        for (int i = 0; i < a.length; i++) {
            System.out.print("\t"+a[i]);
        }
        System.out.println();
    }
}
