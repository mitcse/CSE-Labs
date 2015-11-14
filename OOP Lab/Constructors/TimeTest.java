//
//  TimeTest.java
//  TimeTest
//
//  Created by Avikant Saini on 8/28/15.
//  Copyright © 2015 avikantz. All rights reserved.

import java.util.Scanner;
class Time {
	private int hh, mm, ss;
	private String id; // Identifier
	
	public Time () {
		this.hh = this.mm = this.ss = 0;
		this.id = "";
	}
	public Time (Time t) {
		this.hh = t.hh;
		this.mm = t.mm;
		this.ss = t.ss;
		this.id = t.id;
	}
	public Time (String id) {
		this.hh = this.mm = this.ss = 0;
		this.id = id;
	}
	
	public void setID (String id) {
		this.id = id;
	}
	
	// Initializing with total number of seconds.
	public Time (int ss) {
		initWithSeconds(ss);
	}
	public void initWithSeconds (int ss) {
		this.ss = ss;
		this.hh = this.ss / 3600;
		this.ss -= 3600 * this.hh;
		this.mm = this.ss / 60;
		this.ss -= 60 * this.mm;
	}
	
	// Get the total number of seconds in the sender.
	public int seconds () {
		return (this.ss + this.mm * 60 + this.hh * 3600);
	}
	
	// Input
	public void input () {
		Scanner sc = new Scanner (System.in);
		System.out.println("\tEnter \'" + this.id + "\': ");
		System.out.print("\tEnter hours   (hh) : ");
		this.hh = sc.nextInt();
		System.out.print("\tEnter minutes (mm) : ");
		this.mm = sc.nextInt();
		System.out.print("\tEnter seconds (ss) : ");
		this.ss = sc.nextInt();
		System.out.println();
		
		// Reinitializing incase the user inputs values > 60 for minutes and seconds
		this.initWithSeconds(this.seconds());
	}
	
	public void display () {
		System.out.print (id + " = " + ((this.hh < 10 && this.hh > 0) ? "0" : "") + this.hh + " : " + ((this.mm < 10 && this.mm > 0) ? "0" : "") + this.mm + " : " + ((this.ss < 10  && this.ss > 0) ? "0" : "") + this.ss + "\n");
	}
	
	// Add: initalize with the total number of seconds constructor
	public Time add (Time t2) {
		Time sum = new Time(this.seconds() + t2.seconds());
		return sum;
	}
	
	// Substract: initalize with the total number of seconds constructor
	public Time substract (Time t2) {
		Time difference = new Time(Math.abs(this.seconds() - t2.seconds()));
		return difference;
	}
	
	public Time biggerTime (Time t2) {
		Time t5;
		if (this.seconds() > t2.seconds())
			t5 = new Time(this.seconds());
		else
			t5 = new Time(t2.seconds());
		return t5;
	}
}

public class TimeTest {
	public static void main (String args[]) {
		
		Time t1 = new Time ("T1");
		t1.input();
		
		Time t2 = new Time (t1);
		t2.setID ("T2");
		t2.input();
		
		Time t3 = t1.add (t2);
		t3.setID (" Summation");
		
		Time t4 = t1.substract (t2);
		t4.setID ("Difference");
		
		Time t5 = t1.biggerTime (t2);
		t5.setID ("Bigger (T1, T2)");
		
		t1.display ();
		t2.display ();
		System.out.println ();
		t3.display ();
		t4.display ();
		System.out.println ();
		t5.display ();
	}
}