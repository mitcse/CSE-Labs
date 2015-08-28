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
	private Scanner sc = new Scanner (System.in);
	
	public Time () {
		this.hh = this.mm = this.ss = 0;
		this.id = "";
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
	
	// To print the current time object
	@Override
	public String toString () {
		return (id + " = " + ((this.hh < 10 && this.hh > 0) ? "0" : "") + this.hh + " : " + ((this.mm < 10 && this.mm > 0) ? "0" : "") + this.mm + " : " + ((this.ss < 10  && this.ss > 0) ? "0" : "") + this.ss + "\n");
	}
	
	// Add: initalize with the total number of seconds constructor
	public static Time add (Time t1, Time t2) {
		Time sum = new Time(t1.seconds() + t2.seconds());
		return sum;
	}
	
	// Substract: initalize with the total number of seconds constructor
	public static Time substract (Time t1, Time t2) {
		Time difference = new Time(Math.abs(t1.seconds() - t2.seconds()));
		return difference;
	}
	
	public static Time biggerTime (Time t1, Time t2) {
		Time t5;
		if (t1.seconds() > t2.seconds())
			t5 = new Time(t1.seconds());
		else
			t5 = new Time(t2.seconds());
		return t5;
	}
}

public class TimeTest {
	public static void main (String args[]) {
		
		Time t1 = new Time ("T1");
		t1.input();
		
		Time t2 = new Time ("T2");
		t2.input();
		
		Time t3 = Time.add (t1, t2);
		t3.setID (" Summation");
		
		Time t4 = Time.substract (t1, t2);
		t4.setID ("Difference");
		
		Time t5 = Time.biggerTime (t1, t2);
		t5.setID ("Bigger (T1, T2)");
		
		System.out.println ("" + t1 + t2 + "\n" + t3 + t4 + "\n" + t5);
	}
}