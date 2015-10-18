import java.util.*;

class Node<T>{
	T data;
	Node<T> next;
	Node(T data){
		this.data = data;
	}
	public String toString(){
		return data.toString();
	}
}

class List<T>{
	Node<T> head;
	public void insertAtFront(T data){
		if(head==null)
			head = new Node<T>(data);
		else{
			Node<T> newNode = new Node<T>(data);
			newNode.next = head;
			head = newNode;
		}
	}
	public void insertAtRear(T data){
		if(head==null)
			head = new Node<T>(data);
		else{
			Node<T> t = head;
			while(t.next!=null){
				t = t.next;
			}
			t.next = new Node<T>(data);
		}
	}
	public T delete(){
		T t = head.data;
		head = head.next;
		return t;
	}
	public void display(){
		System.out.print("List contents: ");
		Node<T> t = head;
		while(t != null){
			System.out.print(t + " ");
			t = t.next;
		}
		System.out.println();
	}
}

class P2{
	public static void main(String args[]){
		Scanner s = new Scanner(System.in);
		List<Integer> iL = new List<Integer>();
		List<Double> dL = new List<Double>();
		
		int listType;
		do{
			System.out.println("List types:\n(1) Integer\n(2) Double\n(0) Exit");
			System.out.println("Your option: ");
			listType = s.nextInt();
			if(listType==0){
				System.out.println("Exiting");
				break;
			}else if(listType!=1&&listType!=2){
				System.out.println("Unknown type!");
				continue;
			}
			int option;
			do{
				System.out.println("Options:\n(1) Inert at front\n(2) Insert at rear\n(3) Display\n(0) Back");
				System.out.println("Your option: ");
				option = s.nextInt();
				switch(option){
					case 0:
						break;
					case 1:
						if(listType==1){
							System.out.print("Enter integer to insert: ");
							iL.insertAtFront(s.nextInt());
						}else{
							System.out.print("Enter double to insert: ");
							dL.insertAtFront(s.nextDouble());
						}
						break;
					case 2:
						if(listType==1){
							System.out.print("Enter integer to insert: ");
							iL.insertAtRear(s.nextInt());
						}else{
							System.out.print("Enter double to insert: ");
							dL.insertAtRear(s.nextDouble());
						}
						break;
					case 3:
						if(listType==1){
							iL.display();
						}else{
							dL.display();
						}
						break;
				}
			}while(option!=0);
		}while(listType!=0);
	}
}
