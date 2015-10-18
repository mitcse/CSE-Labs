import java.util.*;

class Matrix{
	private int a[][];
	Matrix(int n, int m){
		a = new int[n][m];
	}
	int[] getRow(int i){
		return a[i];
	}
	public void input(Scanner s){
		System.out.println("Input values into the matrix: ");
		for(int i=0;i<a.length;i++)
			for(int j=0;j<a[i].length;j++)
				a[i][j]=s.nextInt();
	}
}

class RowSum implements Runnable{
	int[] a;
	int s;
	RowSum(int a[]){
		this.a = a;
		s=0;
	}
	public void run(){
		for(int x:a)
			s+=x;
	}
}

class Main{
	public static void main(String args[]){
		Scanner s = new Scanner(System.in);
		System.out.println("Enter the number of rows and columns: ");
		int row,col;
		row = s.nextInt();
		col = s.nextInt();
		Matrix m = new Matrix(row,col);
		m.input(s);
		RowSum[] r = new RowSum[row];
		Thread t[] = new Thread[row];
		for(int i=0;i<row;i++){
			r[i] = new RowSum(m.getRow(i));
			t[i] = new Thread(r[i]);
			t[i].start();
		}
		try{
			int sum = 0;
			for(int i=0;i<row;i++){
				t[i].join();
				sum+=r[i].s;
				System.out.println("Sum of row "+(i+1)+" elements: "+r[i].s);
			}
			System.out.println("Sum of all elements: "+sum);
		}catch(InterruptedException e){
			e.printStackTrace();
		}
	}
}
