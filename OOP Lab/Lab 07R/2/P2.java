import java.util.*;
import java.io.*;

class Employee{
	String name;
	Integer age;
	Double salary;
	Float takeHomeSalary;
	Character grade;
	
	public void input(){
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter the details of the Employee: ");
		try{
			System.out.print("Name: ");
			name = bf.readLine();
			System.out.print("Grade: ");
			grade = (char)bf.read();
		}catch(IOException e){
			e.printStackTrace();
		}
		Scanner s = new Scanner(System.in);
		System.out.print("Age: ");
		age = s.nextInt();
		System.out.print("Salary: ");
		salary = s.nextDouble();
		System.out.print("Take home salary: ");
		takeHomeSalary = s.nextFloat();
	}
	
	public void display(){
		System.out.println("Employee details:");
		System.out.println("Name: "+name + ", Age: "+age + ", Salary: "+salary+", Take home salary: "+takeHomeSalary + ", Grade: "+grade);
	}
}

class P2{
	public static void main(String args[]){
		Scanner s = new Scanner(System.in);
		Employee e = new Employee();
		e.input();
		e.display();
	}
}
