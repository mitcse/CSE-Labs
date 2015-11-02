//
//	TableApplet.java
//	Creating an applet that inputs a number and shows it's multiplication table.
//
//	Created by Avikant Saini on 2/11/15
//

import java.awt.*;
import java.io.*;
import java.applet.*;
import javax.swing.*;

/* 	<applet code="TableApplet" width=320 height=480>
	</applet>
*/

public class TableApplet extends Applet {

	int n;

	public void init () {
		setBackground(new Color(0xfcf9ee));
		setForeground(new Color(0x3a5069));
	}

	public void start () {
		String str = JOptionPane.showInputDialog("Enter the number");
		int nstr = 0;
		try {
			nstr = Integer.parseInt(str);
		}
		catch (Exception e) {
			nstr = 0;
		}
		finally {
			n = nstr;
		}
	}

	public void paint (Graphics g) {
		g.setColor(new Color(0x3a5069));
		g.drawRect(20, 20, 280, 420);
		g.setFont(new Font("SansSerif", Font.PLAIN, 24));

		g.drawString("Table of " + n, 60, 60);

		g.setFont(new Font("SansSerif", Font.PLAIN, 18));

		int xPos = 80, yPos = 100;

		for (int i = 1; i <= 10; ++i, yPos+=32) {
			g.drawString( n + " x " + i + " = " + n, xPos, yPos);
			g.drawLine(xPos - 40, yPos + 12, xPos + 200, yPos + 12);
		}

		showStatus("This is the status window!");
	}

}