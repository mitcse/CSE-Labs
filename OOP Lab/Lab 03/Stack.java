import java.util.Scanner;

public class Stack {

    private int tos;
    private int stack[];
    public final int UNDERFLOW = -2147483648;

    public Stack () {
        tos = -1;
        stack = new int [0];
    }

    public Stack (int size) {
        this.tos = -1;
        this.stack = new int [size];
    }

    public boolean isFull () {
        if (this.tos == this.stack.length - 1)
            return true;
        return false;
    }

    public boolean isEmpty () {
        if (this.tos == -1)
            return true;
        return false;
    }

    public void push (int item) {
        if (this.isFull()) {
            System.err.println("STACK OVERFLOW");
            return;
        }
        this.stack[++this.tos] = item;
    }
    public int pop () {
        if (this.isEmpty()) {
            System.err.println("STACK UNDERFLOW");
            return UNDERFLOW;
        }
        return this.stack[this.tos--];
    }
    public void display () {
        System.out.println("\n\tCurrent Stack:");
        for (int i = 0; i <= this.tos; ++i)
            System.out.print("\t"+this.stack[i]);
        System.out.println();
    }
    

    public static void main (String [] args) {
        Scanner sc = new Scanner (System.in);
        System.out.print("\n\tEnter the number of elements in the stack: ");
        int size = sc.nextInt();
        
        Stack stack = new Stack (size);
        
        char choice;

        do {
            System.out.print("\n\t1. Push an element.\n\t2. Pop an element.\n\t3. Display current stack.\n\tAnything else for exit.\nEnter your choice: ");
            choice = sc.next().charAt(0);
            if (choice == '1') {
                System.out.print("\n\tEnter element to be pushed: ");
                int item = sc.nextInt();
                stack.push(item);
                stack.display();
            }
            else if (choice == '2') {
                int item = stack.pop();
                if (item != stack.UNDERFLOW) {
                    System.out.println("\n\tPopped item: " + item);
                    stack.display();
                }
            }
            else if (choice == '3') {
                stack.display();
            }
            else
                System.exit(0);
        } while (choice == '1' || choice == '2' || choice == '3');
    }
}