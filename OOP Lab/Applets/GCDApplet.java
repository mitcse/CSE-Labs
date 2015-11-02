//
//	GCDApplet.java
//	Creating an applet that takes two numbers from parameter tag and calculates their GCD.
//
//	Created by Avikant Saini on 2/11/15
//

import java.awt.*;
import java.io.*;
import java.applet.*;

/* 	<applet code="GCDApplet" width=640 height=180>
	<param name=numa value=1800>
	<param name=numb value=27>
	</applet>
*/

public class GCDApplet extends Applet {

	int numa;
	int numb;

	public void init () {
		setBackground(new Color(0xfcf9ee));
		setForeground(new Color(0x3a5069));
	}

	public void start () {
		String stra = getParameter("numa");
		String strb = getParameter("numb");
		try {
			if (stra != null)
				numa = Integer.parseInt(stra);
			else
				numa = 0;
			if (strb != null)
				numb = Integer.parseInt(strb);
			else
				numb = 0;
		}
		catch (Exception e) {
			e.printStackTrace();
			numa = numb = 0;
		}
	}

	private int calculateGCD (int a, int b) {
		if (b > a)
			return calculateGCD(b, a);
		if (b == 0)
			return a;
		return calculateGCD(b, a%b);
	}

	public void paint (Graphics g) {
		g.setColor(new Color(0x3a5069));
		g.drawRect(20, 20, 600, 140);
		g.setFont(new Font("SansSerif", Font.PLAIN, 24));

		if (numa == 0 && numb == 0) {
			showStatus("Both numbers are invalid");
			g.drawString("GCD = 0", 60, 90);
		}
		else if (numa == 0) {
			showStatus("First number is invalid");
			g.drawString("GCD = 0", 60, 90);
		}
		else if (numb == 0) {
			showStatus("Second number is invalid");
			g.drawString("GCD = 0", 60, 90);
		}
		else {
			g.drawString("GCD of " + numa + " and " + numb + " = " + calculateGCD(numa, numb), 60, 60);
			showStatus("GCD calculated successfully.");
		}

	}

}