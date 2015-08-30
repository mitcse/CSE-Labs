import java.util.Scanner;
class NumInWords {
    static void printNumberInWord (int n) {
        // Cause we've got to use the if-else-if ladder for the glory of Satan...
        if (n == 0)
            System.out.print("ZERO");
        else if (n == 1)
            System.out.print("ONE");
        else if (n == 2)
            System.out.print("TWO");
        else if (n == 3)
            System.out.print("THREE");
        else if (n == 4)
            System.out.print("FOUR");
        else if (n == 5)
            System.out.print("FIVE");
        else if (n == 6)
            System.out.print("SIX");
        else if (n == 7)
            System.out.print("SEVEN");
        else if (n == 8)
            System.out.print("EIGHT");
        else if (n == 9)
            System.out.print("NINE");
        else
            return;
    }
    public static void main (String [] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number (0-9): ");
        int n = sc.nextInt();
        printNumberInWord(n);
    }
}