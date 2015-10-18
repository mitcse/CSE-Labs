import java.util.*;


class SeatsFilledException extends Exception{
	SeatsFilledException(){
		super("Exception: Seats filled!");
	}
}

class Student{
	static final int maxCount=25;
	static int count;
	private String name;
	private int regNo;
	private int year;
	
	Student(int year) throws SeatsFilledException{
		if(count>=maxCount)
			throw new SeatsFilledException();
		else{
			count++;
			this.year = year;
		}
	}
	
	public void input(){
		System.out.println("Enter the student details: ");
		Scanner s = new Scanner(System.in);
		System.out.print("Name: ");
		name = s.nextLine();
		regNo = (year%100)*100+count;
	}
	public void display(){
		System.out.println("Student details:");
		System.out.println("Name: "+name+", Join year: "+year+", Registration number: "+regNo);
	}
}

class P3{
	public static void main(String args[]){
		Scanner s = new Scanner(System.in);
		System.out.print("Enter the year of joining: ");
		int year = s.nextInt();
		
		Student[] a = new Student[Student.maxCount];
		int option;
		do{
			System.out.print("\nOptions:\n(1) Create new Entry\n(2) Display all entries\n(0) Exit\n");
			System.out.print("Your option: ");
			option = s.nextInt();
			switch(option){
				case 0:
					break;
				case 1:
					try{
						Student st = new Student(year);
						st.input();
						a[Student.count-1] = st;
					}catch(SeatsFilledException e){
						e.printStackTrace();
					}
					break;
				case 2:
					for(Student st:a)
						st.display();
					break;
			}
		}while(option!=0);
		System.out.println("Exiting");
	}
}
