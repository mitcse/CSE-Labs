import java.util.Scanner;

class Time
{
	int h, m, s;

	void getTime(int hr, int min, int sec)
	{
		this.h = hr;
		this.m = min;
		this.s = sec;
	}

	void showTime()
	{
		if (this.h < 10)
		{
			h = Integer.toString(h);
			h = "0" +h;
		}
		if (this.m < 10)
		{
			m = Integer.toString(m);
			m = "0" +m;
		}
		if (this.s < 10)
		{
			s = Integer.toString(s);
			s = "0" +s;
		}
		System.out.println("Time is " +this.h+ ":" +this.m+ ":" +this.s);
	}

	Time makeTime(Time t2)
	{
		Time t3 = new Time();
		t3.s = (this.s + t2.s)%60;
		t3.m = ((this.m + t2.m) + ((this.s + t2.s)/60))%60;
		t3.h = ((this.h + t2.h) + ((this.m + t2.m)/60))%60;
		return t3;
	}

	Time lostTime(Time t2)
	{
		Time t4 = new Time();
		t4.s = this.s - t2.s;
		t4.m = this.m - t2.m;
		t4.h = this.h - t2.h;
		return t4;
	}

	Time whichTime(Time t2)
	{
		if (this.h > t2.h)
		{
			return this;
		}
		else if (t2.h > this.h)
		{
			return t2;
		}
		else
		{
			if (this.m > t2.m)
			{
				return this;
			}
			else if (t2.m > this.m)
			{
				return t2;
			}
			else
			{
				if (this.s > t2.s)
				{
					return this;
				}
				else if (t2.s > this.s)
				{
					return t2;
				}
				else
				{
					return this;
				}
			}
		}
	}
}

class TimeTest
{
	public static void main(String args[])
	{
		Scanner userEntry = new Scanner(System.in);
		int hr1, min1, sec1, hr2, min2, sec2;
		System.out.println("Enter hours, minutes and seconds");
		hr1 = userEntry.nextInt();
		min1 = userEntry.nextInt();
		sec1 = userEntry.nextInt();

		Time t1 = new Time();

		t1.getTime(hr1, min1, sec1);

		t1.showTime();

		System.out.println("Enter second time");
		Time t2 = new Time();

		hr2 = userEntry.nextInt();
		min2 = userEntry.nextInt();
		sec2 = userEntry.nextInt();

		t2.getTime(hr2, min2, sec2);

		t2.showTime();

		Time t3 = new Time();
		Time t4 = new Time();
		Time t5 = new Time();

		t3 = t1.makeTime(t2);
		t4 = t1.lostTime(t2);
		t5 = t1.whichTime(t2);

		System.out.println("Added time");
		t3.showTime();
		System.out.println("Time difference");
		t4.showTime();
		System.out.println("Big time ");
		t5.showTime();
	}
}
