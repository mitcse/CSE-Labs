import java.util.*;

interface Series{
	int getNext();
	void reset();
	void setStart(int n);
}

class ByTwos implements Series{
	int start;	
	int term;	
	public int getNext(){
		term += 2;
		return term;		
	}

	public void reset(){
		term = start;
	}

	public void setStart(int n){
		start = n;
		term = start;
	}

	ByTwos(){
		System.out.println("Set to 0 by default. ");
		setStart(0);
	}
}

class ByTwoTest{
	public static void main(String[] args){
		Series s = new ByTwos();
		Scanner sc = new Scanner(System.in);
		int ch = 0;	
		while(ch!=4){
			System.out.print("1. Get next\n2. Reset to start\n3. Change start value\n4. Exit\nEnter: ");
			ch = sc.nextInt();
			switch(ch){
				case 1:
					System.out.println("Next element: " + s.getNext());
					break;
				case 2: 
					System.out.println("Resetting to start!");
					s.reset(); break;
				case 3:
					System.out.println("Enter start value: ");	
					int st = sc.nextInt();
					s.setStart(st);
					break;
				case 4: System.exit(0);


			}

		}


	}

}
