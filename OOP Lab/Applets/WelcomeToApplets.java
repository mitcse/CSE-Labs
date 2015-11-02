//
//	WelcomeToApplets.java
//	Simple Applet demo program that welcomes you to applet programming.
//
//	Created by Avikant Saini on 2/11/15
//

import java.awt.*;
import java.applet.*;

/* <applet code = "WelcomeToApplets" width=720 height=400></applet>
*/

public class WelcomeToApplets extends Applet {

	public void init () {
		setBackground(new Color(0xfcf9ee));
		setForeground(new Color(0x3a5069));
	}

	public void start () {

	}

	public void paint (Graphics g) {
		g.setColor(new Color(0x3a5069));
		g.drawRect(20, 20, 680, 240);
		g.setFont(new Font("SansSerif", Font.PLAIN, 32));
		g.drawString("Welcome to Applet Programming!", 40, 140);

		showStatus("This is the status window!");
	}

}