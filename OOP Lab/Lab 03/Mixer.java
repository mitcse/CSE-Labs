import java.util.Scanner;
public class Mixer {
	int arr[];
	int n;
	private Scanner sc = new Scanner (System.in);
	public Mixer(int n) {
		this.n = n;
		this.arr = new int[n];
	}
	public void accept() {
		System.out.print("Enter the length of the array: ");
		this.n = sc.nextInt();
		this.arr = new int[n];
		for (int i = 0; i < n; ++i) {
			System.out.print("\tEnter a[" + i + "]: ");
			this.arr[i] = sc.nextInt();
			if (i != 0) {
				while (this.arr[i-1] > this.arr[i]) {
					System.out.print("\tThe elements should be in ascending order, and should not be equal... Enter a[" + i + "] again : ");
					this.arr[i] = sc.nextInt();
				}	
			}
		}
	}
	public Mixer mix(Mixer A) {
		Mixer newMixer = new Mixer (A.n + this.n);
		int i;
		for (i = 0; i < this.n; ++i)
			newMixer.arr[i] = this.arr[i];
		for (i = 0; i < A.n; ++i) 
			newMixer.arr[this.n+i] = A.arr[i];
		return newMixer;
	}
	public void display() {
		System.out.println();
		for (int i = 0; i < this.n; ++i)
			System.out.print("\t"+this.arr[i]);
		System.out.println();
	}
	public static void main(String [] args) {
		Mixer A = new Mixer(0);
		Mixer B = new Mixer(0);
		System.out.println("Array 1:");
		A.accept();
		System.out.println("Array 2:");
		B.accept();
		Mixer C = A.mix(B);
		System.out.print("Array 1: ");
		A.display();
		System.out.print("Array 2: ");
		B.display();
		System.out.print("Array 1+2: ");
		C.display();
	}
}
