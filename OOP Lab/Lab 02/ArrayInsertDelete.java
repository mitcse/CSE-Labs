import java.util.Scanner;
public class ArrayInsertDelete {
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

        System.out.print("\n\t1. Insert an element\n\t2. Delete an element\n\t3. Anything else for exit.\nEnter your choice: ");
        char ch = sc.next().charAt(0);
        while (ch == '1' || ch == '2') {
            switch (ch) {
                case '1': {
                    System.out.print("\nYou chose... Insert.\n\tEnter element to insert: ");
                    int x = sc.nextInt();
                    System.out.print("\tEnter index to insert '" + x + "' : ");
                    System.out.println();
                    int pos = sc.nextInt();
                    while (pos > n || pos < 0) {
                    	System.err.print("Index out of bounds error. Try again.\n\tEnter index to insert '" + x + "' : ");
                    	pos = sc.nextInt();
                    }
                    int arrcopy[] = new int[n];
                    copyArray(arr, arrcopy, false);
                    arr = new int[++n];
                    copyArray(arrcopy, arr, false);
                    insertElement(arr, x, pos);
                    System.out.println("\nAfter Insertion: ");
                    break;
                }
                case '2': {
                    System.out.print("\nYou chose... Delete.\n\tEnter index of element to be deleted: ");
                    int pos = sc.nextInt();
                    while (pos > n || pos < 0) {
                    	System.err.print("Index out of bounds error. Try again.\n\tEnter index to deleted: ");
                    	pos = sc.nextInt();
                    }
                    int arrcopy[] = new int[n];
                    copyArray(arr, arrcopy, true);
                    deleteElement(arrcopy, pos);
                    arr = new int[--n];
                    copyArray(arrcopy, arr, true);
                    System.out.println("\nAfter Deletion: ");
                    break;
                }
                default: {
                    System.exit(0);
                }
            }
            printArray(arr);
            System.out.print("\n\t1. Insert an element\n\t2. Delete an element\n\t3. Anything else for exit.\nEnter your choice: ");
            ch = sc.next().charAt(0);
        }
    }
    static void copyArray (int from[], int to[], boolean del) {
        for (int i = 0; i < ((del)?to.length:from.length); i++) {
            to[i] = from[i];
        }
    }
    static void insertElement (int a[], int x, int pos) {
        for (int i = a.length-2; i >= pos && pos < a.length; i--) {
            a[i+1] = a[i];
        }
        a[pos] = x;
    }
    static void deleteElement (int a[], int pos) {
        for (int i = pos; i < a.length-1; i++) {
            a[i] = a[i+1];
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
