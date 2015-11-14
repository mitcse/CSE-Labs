//
//
//
//
//
//
//

import java.awt.*;
import java.awt.event.*;
import java.applet.*;
import javax.swing.*;

/*<object code="ClockX" width=640 height=640></object>*/

public class ClockX extends JApplet {

	JTextField textField;

	int width, height;

	Point center;
	Point minute;
	Point hour;

	int hours;
	int minutes;

	Point minutePoints[];
	Point hourPoints[];

	public ClockX () {

		width = 640;  
		height = 640; 

		center = new Point(320, 320);
		minute = new Point(320, 200);
		hour = new Point(320, 240);

		hourPoints = new Point[12];
		minutePoints = new Point[60];

		for (int i = 0; i < 12; ++i) {
			hourPoints[i] = new Point();
		}
	}

	public void init () {
		try {
			SwingUtilities.invokeAndWait(new Runnable () {
				@Override
				public void run () {
					viewDidLoad();
				}
			});
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}

	private void viewDidLoad () {
		setLayout(new BorderLayout());

		textField = new JTextField("");
		textField.addActionListener(new ActionListener () {
			@Override
			public void actionPerformed (ActionEvent e) {
				buildClock();
			}
		});

		add(textField, BorderLayout.NORTH);
	}

	public void buildClock () {
		String txt = textField.getText();
		String hourString = "", minuteString = "";
		int hr = 0, min = 0;
		try {
			hourString = txt.substring(0, 2);
			minuteString = txt.substring(3);
			hr = Integer.parseInt(hourString);
			min = Integer.parseInt(minuteString);
		}
		catch (NumberFormatException e) {
			System.out.println("NumberFormatException: " + e);
		} 
		catch (Exception e) {
			System.out.println("Exception: " + e);
		}
		hours = hr;
		minutes = min;
		repaint();
	}

	void drawWedge( double angle, int radius, Graphics g ) {  
      angle -= 0.5 * Math.PI;  
      int x = (int)( radius*Math.cos(angle) );  
      int y = (int)( radius*Math.sin(angle) );  
      angle += 2*Math.PI/3;  
      int x2 = (int)( 5*Math.cos(angle) );  
      int y2 = (int)( 5*Math.sin(angle) );  
      angle += 2*Math.PI/3;  
      int x3 = (int)( 5*Math.cos(angle) );  
      int y3 = (int)( 5*Math.sin(angle) );  
      g.drawLine( width/2+x2, height/2+y2, width/2 + x, height/2 + y );  
      g.drawLine( width/2+x3, height/2+y3, width/2 + x, height/2 + y );  
      g.drawLine( width/2+x2, height/2+y2, width/2 + x3, height/2 + y3 );  
   }

	public void paint (Graphics g) {
		super.paint(g);
		g.setColor(new Color(0x3A5069));
		drawWedge( 2*Math.PI * hours / 12, width/5, g );  
		g.setColor(new Color(0x69503A));
		drawWedge( 2*Math.PI * minutes / 60, width/3, g ); 
		g.setColor(new Color(0xBBBBBB));
		g.drawOval(160, 160, 300, 300);
	}
	
}