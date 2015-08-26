import java.util.Scanner;
class Time {
    private int h, m, s;
    
    public Time () {
        this.h = 0;
        this.m = 0;
        this.s = 0;
    }
    
    void inputTime(String id) { // Getting a particular Time
        Scanner sc = new Scanner (System.in);
        System.out.println("Enter \'" + id + "\': ");
        System.out.print("\tEnter hours   (HH) : ");
        this.h = sc.nextInt();
        System.out.print("\tEnter minutes (MM) : ");
        this.m = sc.nextInt();
        System.out.print("\tEnter seconds (SS) : ");
        this.s = sc.nextInt();
        System.out.println();
        this.s = this.s + 60*this.m + 3600*this.h;
        this.h = this.s/3600;
        this.s -= 3600*this.h;
        this.m = this.s/60;
        this.s -= 60*this.m;
    }

    void showTime(String id) { // Displaying time
        System.out.println(id + ":\t" + ((this.h<10 && this.h>0)?"0":"") + this.h + " : " + ((this.m<10 && this.m>0)?"0":"") + this.m + " : " + ((this.s<10  && this.s>0)?"0":"") + this.s + ".\n");
    }

    Time makeTime(Time t2) { // Adding Time 't2' to current object
        Time t3 = new Time();
        t3.s = this.s + t2.s + 60*(this.m + t2.m) + 3600*(this.h + t2.h);
        t3.h = t3.s/3600;
        t3.s -= 3600*t3.h;
        t3.m = t3.s/60;
        t3.s -= 60*t3.m;
        return t3;
    }

    Time lostTime(Time t2) { // Subtracting Time ’t2’ form current object
        Time t4 = new Time();
        t4.s = this.s - t2.s + 60*(this.m - t2.m) + 3600*(this.h - t2.h);
        t4.h = t4.s/3600;
        t4.s -= 3600*t4.h;
        t4.m = t4.s/60;
        t4.s -= 60*t4.m;
        return t4;
    }

    Time whichTime(Time t2) {
        if (this.h > t2.h) // Compare Hours
            return this;
        else if (t2.h > this.h)
            return t2;
            
        else { // Compare minutes
            if (this.m > t2.m)
                return this;
            else if (t2.m > this.m)
                return t2;
                
            else { // Compare seconds
                if (this.s > t2.s)
                    return this;
                else if (t2.s > this.s)
                    return t2;
                    
                else // Equal...
                    return this;
            }
        }
    }
}

public class TimeTest {
	public static void main(String args[]) {
        Scanner userEntry = new Scanner(System.in);

        Time t1 = new Time();
        t1.inputTime("T1");
        t1.showTime("T1");
        
        Time t2 = new Time();
        t2.inputTime("T2");
        t2.showTime("T2");

        Time t3 = new Time();
        Time t4 = new Time();
        Time t5 = new Time();

        t3 = t1.makeTime(t2);
        t4 = t1.lostTime(t2);
        t5 = t1.whichTime(t2);

        t3.showTime("T1 + T2");
        t4.showTime("T1 - T2");
        t5.showTime("Bigger (T1, T2)");
    }
}