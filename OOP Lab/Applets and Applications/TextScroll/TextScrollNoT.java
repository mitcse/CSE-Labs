//
//  TextScrollNoT.java
//  Java applet that scrolls a user inputted text isung a thread.
//
//  Created by Avikant Saini on 2/11/15
//

import java.awt.*; 
import java.applet.*; 
import javax.swing.*;

/*  <applet code="TextScrollNoT" width=420 height=180>
    </applet> 
*/

public class TextScrollNoT extends Applet {

    String text;
          
    public void init () { 
    	setBackground(new Color(0xfcf9ee));
    	setForeground(new Color(0x3a5069));
    } 
     
    public void start() {
    	text = JOptionPane.showInputDialog("Enter message to be displayed");
    	text = "\t" + text + "\t";
    	while (true) { 
			repaint();
			char ch = text.charAt(0); 
			text = text.substring(1, text.length()) + ch; 
		}
    } 
     
    public void paint(Graphics g) { 
		g.setColor(new Color(0x3a5069));
		g.setFont(new Font("SansSerif", Font.PLAIN, 20));
		g.drawString(text, 20, 90); 
    } 
     
}  