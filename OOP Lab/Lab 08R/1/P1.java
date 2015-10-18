import java.util.*;

class Multiplier{
	synchronized public static void multiply(int a, int b){
		for(int i=1;i<=b;i++){
			System.out.println(i+"*"+a+"="+i*a);
		}
	}
}
class Table5 extends Thread{
	Table5(){
		start();
	}
	
	public void run(){
		Multiplier.multiply(5,10);
	}
}

class Table7 extends Thread{
	Table7(){
		start();
	}
	
	public void run(){
		Multiplier.multiply(7,10);
	}
}

class Tables{
	public static void main(String args[]){
		Table5 t5 = new Table5();
		Table7 t7 = new Table7();
	}
}
