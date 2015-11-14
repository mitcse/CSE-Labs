import java.util.Scanner;
public class Matrix {
    String id;
    int m, n;
    int mat[][];
    private Scanner sc;
    public Matrix (int m, int n) {
        this.m = m;
        this.n = n;
        this.mat = new int[m][n];
    }
    public Matrix (String id) {
        this.id = id;
        this.m = 0;
        this.n = 0;
        this.mat = new int[0][0];
        sc = new Scanner(System.in);
    }
    public void input () {
        System.out.print("Enter dimensions of the matrix " + id + " : ");
        this.m = sc.nextInt();
        this.n = sc.nextInt();
        this.mat = new int[m][n];
        System.out.println();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print("Enter a[" + i + "][" + j + "] : ");
                this.mat[i][j] = sc.nextInt();
            }
        }
    }

    @Override
    public String toString() {
        String str = "\nMatrix '" + this.id + "' : \n";
        for (int i = 0; i < this.m; i++) {
            str += "\t";
            for (int j = 0; j < this.n; j++) {
                str += this.mat[i][j] + "\t";
            }
            str += "\n";
        }
        return str;
    }

    public static Matrix add (Matrix a, Matrix b) {
        Matrix c = new Matrix(a.m, a.n);
        if (a.m == b.m && a.n == b.n) {
            for (int i = 0; i < a.m; i++) {
                for (int j = 0; j < a.n; j++) {
                    c.mat[i][j] = a.mat[i][j] + b.mat[i][j];
                }
            }
            return c;
        }
        else {
            System.err.println("901. DIMENSION ERROR");
        }
        return null;
    }
}
class MatrixAdd {
    public static void main(String[] args) {
        Matrix a = new Matrix("A");
        Matrix b = new Matrix("B");
        a.input();
        b.input();
        Matrix c = Matrix.add(a, b);
        c.id = "A+B";
        System.out.println("\n\n" + a + "\n" + b + "\n" + c);
    }
}
