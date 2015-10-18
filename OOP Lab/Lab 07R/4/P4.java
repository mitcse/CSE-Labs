import java.util.*;

interface Series{
	public int getNext();
	public void reset();
	public void setStart(int start);
}

class ByTwos implements Series{
	private int start;
	private int current;
	private static final int step=2;
	
	public void setStart(int start){
		this.start = start;
		current=start;
	}
	public int getNext(){
		return current+=step;
	}
	public void reset(){
		current=start;
	}
}
class P4{
	public static void main(String args[]){
		Scanner s = new Scanner(System.in);
		
		ByTwos by2 = new ByTwos();
		
		int option;
		do{
			System.out.println("Options:\n(1) Set start\n(2) Display next\n(3) Reset\n(0) Exit");
			System.out.print("Your option: ");
			option = s.nextInt();
			switch(option){
				case 0:
					break;
				case 1:
					System.out.print("Enter the starting position: ");
					by2.setStart(s.nextInt());
					break;
				case 2:
					System.out.println("Next element is: "+by2.getNext());
					break;
				case 3:
					System.out.println("Series reset");
					by2.reset();
					break;
			}
		}while(option!=0);
		System.out.println("Exiting");
	}
}
