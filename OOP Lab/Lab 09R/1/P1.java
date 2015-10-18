import java.util.*;

class Stack<T>{
	T[] a; 
	int top;
	Stack(int n){
		a = (T[]) new Object[n];
		top=-1;
	}
	void push(T o) throws Exception{
		if(top==a.length-1){
			throw new Exception("Stack overflow");
		}else{
			a[++top] = o;
		}
	}
	T pop() throws Exception{
		if(top==-1){
			throw new Exception("Stack underflow");
		}else{
			return a[top--];
		}
	}
	void display(){
		System.out.print("Stack contents: ");
		for(int i=0;i<=top;i++)
			System.out.print(a[i].toString() + " ");
		System.out.println();
	}
}

class Student{
	int rollNo;
	String name;
	public void input(Scanner s){
		System.out.print("Roll number: ");
		rollNo = s.nextInt();
		s.nextLine();
		System.out.println("Name: ");
		name = s.nextLine();
	}
	public String toString(){
		return "Student: { Roll number: " + rollNo + ", Name: " + name + "}";
	}
}

class Employee{
	int employeeNo;
	String name;
	public void input(Scanner s){
		System.out.print("Employee number: ");
		employeeNo = s.nextInt();
		s.nextLine();
		System.out.println("Name: ");
		name = s.nextLine();
	}
	public String toString(){
		return "Employee: { Employee number: " + employeeNo + ", Name: " + name + "}";
	}
}

class P1{
	public static void main(String args[]){
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the size of the student stack: ");
		Stack<Student> sS = new Stack(s.nextInt());
		System.out.print("Enter the size of the employee stack: ");
		Stack<Employee> eS = new Stack(s.nextInt());
		
		int stackType;
		do{
			System.out.print("Stack types:\n(1) Student\n(2) Employee\n(0) Exit\n");
			System.out.print("Enter stack type to operate on: ");
			stackType = s.nextInt();
			if(stackType==0){
				System.out.println("Exiting");
				break;
			}else if(stackType!=1 && stackType!=2){
				System.out.println("Unknown stack type!");
				continue;
			}
			int option;
			do{
				System.out.print("Options:\n(1) Push\n(2) Pop\n(3) Display\n(0) Done\n");
				System.out.print("Enter your option: ");
				option=s.nextInt();
				switch(option){
					case 0:
						break;
					case 1:
						try{
							if(stackType == 1){
								System.out.println("Enter student details to be pushed:");
								Student st = new Student();
								st.input(s);
								try{
									sS.push(st);
								}catch(Exception e){
									e.printStackTrace();
								}
							}else{
								System.out.println("Enter employee details to be pushed:");
								Employee em = new Employee();
								em.input(s);
								eS.push(em);
							}
						}catch(Exception e){
							e.printStackTrace();
						}
						break;
						case 2:
						try{
							if(stackType==1)
								System.out.println(sS.pop() + " popped from stack");
							else
								System.out.println(eS.pop() + " popped from stack");
						}catch(Exception e){
							e.printStackTrace();
						}
						break;
					case 3:
						if(stackType==1)
							sS.display();
						else
							eS.display();
						break;
					default:
						System.out.println("Unknown choice!");
				}
			}while(option!=0);
		}while(stackType!=0);
	}
}
