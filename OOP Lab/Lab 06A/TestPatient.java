import java.util.*;

class Patient{
	String name;
	int age;
	int hos_no;
	int getAge(){
		return age;
	}

	int getNo(){
		return hos_no;
	}
	
	String getName(){
		return name;
	}

	void setAge(int age){
		this.age = age;
	}

	void setName(String name){
		this.name = new String(name);
	}

	void setNo(int hos_no){
		this.hos_no = hos_no;
	}

	void dispPatient(){
		System.out.println("Name: " + getName());
		System.out.println("Age: " + getAge());
		System.out.println("Hospital number: " + getNo());
	}

	Patient(String name, int age, int hos_no){
		setName(name);
		setAge(age);
		setNo(hos_no);
	}
	
}

class inpatient extends Patient{
	String DeptName, roomType;
	GregorianCalendar AdmissionDate;	
	String getDeptName(){
		return DeptName;
	}	

	String getRoomType(){
		return roomType;
	}

	GregorianCalendar getAD(){
		return AdmissionDate;
	}

	void setDeptName(String DeptName){
		this.DeptName = new String(DeptName);
	}

	void setRoomType(String type){
		this.roomType = new String(type);
	}

	void setAD(GregorianCalendar date){
		this.AdmissionDate = new GregorianCalendar(date.get(Calendar.YEAR), date.get(Calendar.MONTH), date.get(Calendar.DATE));
	}	

	void dispinpatient(){
		super.dispPatient();
		System.out.println("Department: " + getDeptName());
		System.out.println("Room type: " + getRoomType());
		System.out.println("Date of admission: " + AdmissionDate.get(Calendar.DATE) + "/" + AdmissionDate.get(Calendar.MONTH) + "/" + AdmissionDate.get(Calendar.YEAR));

	}

	inpatient(String name, int age, int hos_no, String DeptName, String RoomType, GregorianCalendar AdmissionDate){
		super(name, age, hos_no);
		setDeptName(DeptName);
		setRoomType(RoomType);
		setAD(AdmissionDate);
	}
}

class Billing extends inpatient{
	GregorianCalendar DischargeDate;	
	GregorianCalendar getDD(){
		return DischargeDate;
	}
	void setDD(GregorianCalendar date){
		this.DischargeDate = new GregorianCalendar(date.get(Calendar.YEAR), date.get(Calendar.MONTH), date.get(Calendar.DATE));
	}	

	void Amount(){
		super.dispinpatient();
		System.out.println("Date of discharge: " + DischargeDate.get(Calendar.DATE) + "/" + DischargeDate.get(Calendar.MONTH) + "/" + DischargeDate.get(Calendar.YEAR));

		int flag = 0;
		double amount = 0;
		int nDays = ((DischargeDate.get(Calendar.YEAR)-super.AdmissionDate.get(Calendar.YEAR))*365) + ((DischargeDate.get(Calendar.MONTH)-super.AdmissionDate.get(Calendar.MONTH))*30) + ((DischargeDate.get(Calendar.DATE)-super.AdmissionDate.get(Calendar.DATE))*1);
		do{
		if(super.roomType.equals("Special")){
			flag = 1;		
			amount = nDays * 1200;
		}
		else if(super.roomType.equals("SemiSpecial")){
			amount = nDays * 600;
			flag = 1;
		}

		else if(super.roomType.equals("General")){
			flag = 1;		
			amount = nDays * 150;
		}
		else{
			System.out.println("Wrong room type! Enter again.");
			Scanner sc = new Scanner(System.in);
			String again  = sc.nextLine();
			super.setRoomType(again);
		}
		}while(flag == 0);
	System.out.println("Amount is: " + amount);
	}

	Billing(String name, int age, int hos_no, String DeptName, String RoomType, GregorianCalendar AdmissionDate, GregorianCalendar DischargeDate){
		super(name, age, hos_no, DeptName, RoomType, AdmissionDate);
		setDD(DischargeDate);
	}	
}

class TestPatient{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String name;
		int age, hos_no;
		String DeptName, RoomType;
		int y, m, d;
		GregorianCalendar AdmissionDate, DischargeDate;
		System.out.print("Enter name: ");
		name = sc.nextLine();
		System.out.print("Enter age: ");
		age = sc.nextInt();
		System.out.print("Enter hospital number: ");
		hos_no = sc.nextInt();
		System.out.print("Enter dept. name: ");
		DeptName = sc.nextLine();
		DeptName = sc.nextLine();
		System.out.print("Enter Room Type: ");
		RoomType = sc.nextLine();
		System.out.print("Enter admission date (year, month, date): ");
		y = sc.nextInt();
		m = sc.nextInt();
		d = sc.nextInt();
		AdmissionDate = new GregorianCalendar(y, m, d);

		System.out.print("Enter discharge date (year, month, date): ");
		y = sc.nextInt();
		m = sc.nextInt();
		d = sc.nextInt();
		DischargeDate = new GregorianCalendar(y, m, d);

		Billing p_d = new Billing(name, age, hos_no, DeptName,RoomType, AdmissionDate,DischargeDate);
		System.out.println();		
		p_d.Amount();
	}

}


