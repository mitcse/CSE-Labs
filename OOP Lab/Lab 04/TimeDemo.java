class TimeDemo
{

	int h, m, s;

	TimeDemo ()
	{
		System.out.println("Inside default constructor");
		h = 1;
		m = 10;
		s = 12;
		System.out.println("The values assigned are " +h + ":" +m + ":" +s);
	}

	TimeDemo (int hr, int min, int sec)
	{
		System.out.println("Inside parametrized constructor");
		h = hr;
		m = min;
		s = sec;
		System.out.println("The values assigned are " +h + ":" +m + ":" + s);
	}

	TimeDemo (TimeDemo t1)
	{
		System.out.println("Inside copy constructor");
		h = t1.h;
		m = t1.m;
		s = t1.s;
		System.out.println("The values assigned are " +h +":" +m + ":" + s);
	}

	void showTime()
	{
        	System.out.println("Time is " + ((this.h<10)?"0":"") + this.h + " hh " + ((this.m<10)?"0":"") + this.m + " mm " + ((this.s<10)?"0":"") + this.s + " ss");
    
	}

	public static void main(String args[])
	{
		TimeDemo t1 = new TimeDemo();
		t1.showTime();
		TimeDemo t2 = new TimeDemo(7, 21, 43);
		t2.showTime();
		TimeDemo t3 = new TimeDemo(t2);
		t3.showTime();
	}

}
