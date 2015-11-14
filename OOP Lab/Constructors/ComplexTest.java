//
//  ComplexTest.java
//  ComplexTest
//
//  Created by Avikant Saini on 8/28/15.
//  Copyright © 2015 avikantz. All rights reserved.

import java.util.Scanner;
class Complex {
	private double re;
	private double im;
	private String id; // For identifying
	
	// Constructors
	public Complex () {
		this.re = 0.0;
		this.im = 0.0;
	}
	public Complex (String id) {
		this.re = 0.0;
		this.im = 0.0;
		this.id = id;
	}
	public Complex (Complex c) {
		this.re = c.re;
		this.im = c.im;
		this.id = c.id;
	}
	public Complex (double re, double im) {
		this.re = re;
		this.im = im;
		this.id = "";
	}
	
	// Setters
	public void setReal (double re) {
		this.re = re;
	}
	public void setImaginary (double im) {
		this.im = im;
	}
	public void setID (String id) {
		this.id = id;
	}
	
	public void input () {
		Scanner sc = new Scanner (System.in);
		System.out.print("\n\tEnter Real (" + this.id + ") : ");
		this.re = sc.nextDouble();
		System.out.print("\n\tEnter Imaginary (" + this.id + ") : ");
		this.im = sc.nextDouble();
	}
	
	public void display () {
		System.out.print ("\t" + this.id + " = " + this.re + ((this.im < 0)?" ":" +") + this.im + "i.\n");
	}
	
	// add and substract
	public static Complex add (Complex a, Complex b) {
		Complex s = new Complex (a.re + b.re, a.im + b.im);
		return s;
	}
	public static Complex substract (Complex a, Complex b) {
		Complex d = new Complex (a.re - b.re, a.im - b.im);
		return d;
	}
	
	// Additional Methods for the glory of the Sontaran Empire
	public static Complex conjugate (Complex a) {
		Complex c = new Complex (a.re, - a.im);
		return c;
	}
	
	public static Complex multiply (Complex a, Complex b) {
		Complex p = new Complex (a.re * b.re - a.im * b.im, a.im * b.re + a.re * b.im);
		return p;
	}
	
	public static Complex divide (Complex a, Complex b) {
		Complex r = Complex.multiply (a, Complex.conjugate(b));
		double bxbc = (b.re * b.re + b.im * b.im);
		r.setReal (r.re/bxbc);
		r.setImaginary (r.im/bxbc);
		return r;
	}
}

public class ComplexTest {
	public static void main (String [] args) {
		Complex a = new Complex ("A");
		Complex b = new Complex (a);
		b.setID ("B");
		
		a.input();
		b.input();
		
		Complex s = Complex.add (a, b);
		s.setID ("A + B");
		
		Complex d = Complex.substract (a, b);
		d.setID ("A - B");
		
		Complex p = Complex.multiply (a, b);
		p.setID ("A x B");
		
		Complex r = Complex.divide (a, b);
		r.setID ("A / B");
		
		a.display ();
		b.display ();
		s.display ();
		d.display ();
		p.display ();
		r.display ();
	}
}