import java.util.Scanner;

class Stack
{

    private int tos;
    private int stack[];
    public final int UNDERFLOW = -2147483648;    // INT_MIN

    Stack ()
    {
        tos = -1;
        stack = new int [0];
    }

    Stack (int size)
    {
        this.tos = -1;
        this.stack = new int [size];
    }

    boolean isFull ()
    {
        return (this.tos == this.stack.length - 1);
    }

    boolean isEmpty ()
    {
        return (this.tos == -1);
    }

    void push (int ele)
    {
        if (this.isFull())
        {
            System.err.println("Stack Overflow");
            return;
        }
        this.stack[++this.tos] = ele;
    }
    int pop ()
    {
        if (this.isEmpty())
        {
            System.err.println("Stack Underflow");
            return UNDERFLOW;
        }
        return this.stack[this.tos--];
    }
    void display ()
    {
        System.out.println("Stack now is");
        for (int i = 0; i <= this.tos; ++i)
            System.out.println(this.stack[i]);
        System.out.println();
    }
    

    public static void main (String [] args)
    {
        Scanner userEntry = new Scanner (System.in);
        System.out.println("Enter the number of elements");
        int size = userEntry.nextInt();
        
        Stack stack = new Stack (size);
        
        char choice;

        do
        {
            System.out.println("Enter 1 to push, 2 to pop, 3 to show, 0 to exit program");
            choice = userEntry.next().charAt(0);
            if (choice == '1')
            {
                System.out.println("Enter element to be added");
                int ele = userEntry.nextInt();
                stack.push(ele);
                stack.display();
            }
            else if (choice == '2')
            {
                int item = stack.pop();
                if (item != stack.UNDERFLOW)
                {
                    System.out.println("Deleted element is " + item);
                    stack.display();
                }
            }
            else if (choice == '3')
            {
                stack.display();
            }
            else
                System.exit(0);
        } while (choice == '1' || choice == '2' || choice == '3');
    }
}