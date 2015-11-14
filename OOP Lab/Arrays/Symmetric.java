import java.util.Scanner;
public class Symmetric {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the order of the Matrix: ");
        int n = sc.nextInt();
        int a[][] = new int[n][n];
        int i, j;
        String s = "";
        
        for (i = 0; i < n; ++i) {
            s += "\t";
            for (j = 0; j < n; ++j) {
                System.out.print("Enter a["+i+"]["+j+"] : ");
                a[i][j] = sc.nextInt();
                s += a[i][j] + "  ";
            }
            s += "\n";
        }

        boolean sym = true;
        for (i = 0; i < n; ++i){
            for (j = 0; j < n; ++j){
                if(a[i][j] != a[j][i])
                    sym = false;
                break;
            }
        }

        if (sym)
            System.out.println("\nThe Matrix:\n\n"+s+" is :\n\tSYMMERTRIC");
        else
            System.out.println("\nThe Matrix:\n\n" + s + " is :\n\tNOT SYMMETRIC");
    }
}
