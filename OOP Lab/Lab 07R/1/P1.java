import java.util.*;

interface Stack{
	public void push(int x) throws Exception;
	public int pop() throws Exception;
}

class FixedStack implements Stack{
	private int a[];
	private int top;
	
	FixedStack(int n){
		top=-1;
		a = new int[n];
	}
	
	public void push(int x) throws Exception{
		if(top==a.length-1){
			throw new Exception("Stack overflow");
		}else{
			a[++top]=x;
		}
	}
	
	public int pop() throws Exception{
		if(top==-1){
			throw new Exception("Stack underflow");
		}else{
			return a[top--];
		}
	}
}

class DynamicStack implements Stack{
	private int a[];
	private int top;
	
	DynamicStack(){
		top=-1;
		a = new int[5];
	}
	
	public void push(int x){
		if(top==a.length-1){
			System.out.println("Doubling stack size");
			int b[] = new int[a.length*2];
			for(int i=0;i<a.length;i++)
				b[i] = a[i];
			a = b;
		}
		a[++top]=x;
	}
	
	public int pop() throws Exception{
		if(top==-1){
			throw new Exception("Stack underflow");
		}else{
			return a[top--];
		}
	}
}

class P1{
	public static void main(String args[]){
		Scanner s = new Scanner(System.in);
		
		int option;
		
		System.out.print("Enter the size of the fixed stack: ");
		FixedStack fs = new FixedStack(s.nextInt());
		do{
			System.out.print("Options:\n(1) Push\n(2) Pop\n(0) Move on to Dynamic stack\n");
			System.out.print("Your options: ");
			option = s.nextInt();
			switch(option){
				case 0:
					break;
				case 1:
					System.out.print("Enter an integer to push: ");
					try{
						fs.push(s.nextInt());
					}catch(Exception e){
						e.printStackTrace();
					}
					break;
				case 2:
					try{
						int x = fs.pop();
						System.out.print("Popped "+x+" from stack");
					}catch(Exception e){
						e.printStackTrace();
					}
					break;					
			}
		}while(option!=0);
		
		DynamicStack ds = new DynamicStack();
		do{
			System.out.print("Options:\n(1) Push\n(2) Pop\n(0) Exit\n");
			System.out.print("Your options: ");
			option = s.nextInt();
			switch(option){
				case 0:
					break;
				case 1:
					System.out.print("Enter an integer to push: ");
					ds.push(s.nextInt());
					break;
				case 2:
					try{
						int x = ds.pop();
						System.out.print("Popped "+x+" from stack");
					}catch(Exception e){
						e.printStackTrace();
					}
					break;					
			}
		}while(option!=0);
	}
}
