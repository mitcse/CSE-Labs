//
//  TextScrollS.java
//  Java applet that scrolls a user inputted text isung a thread.
//
//  Created by Avikant Saini on 14/11/15
//

import java.awt.*; 
import java.applet.*; 
import javax.swing.*;

public class TextScrollS implements Runnable {

	String text;

	JLabel textLabelN, textLabel, textLabelS;
		  
	public TextScrollS () {
		JFrame frame = new JFrame("TextScrollS");
		frame.setSize(600, 400);
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		frame.setLayout(new BorderLayout());

		textLabel = new JLabel("", JLabel.CENTER);
		textLabel.setFont(new Font("SansSerif", Font.PLAIN, 32));
		frame.add(textLabel, BorderLayout.CENTER);

		textLabelN = new JLabel("", JLabel.CENTER);
		textLabelN.setFont(new Font("SansSerif", Font.PLAIN, 32));
		frame.add(textLabelN, BorderLayout.NORTH);

		textLabelS = new JLabel("", JLabel.CENTER);
		textLabelS.setFont(new Font("SansSerif", Font.PLAIN, 32));
		frame.add(textLabelS, BorderLayout.SOUTH);

		text = JOptionPane.showInputDialog("Enter message to be displayed");
		text = "\t" + text + "\t";

		Thread t = new Thread(this); 
		t.start(); 
	}
	 
	public void run() {
		char ch; 
		try { 
			while (true) { 
				textLabel.setText(text);
				textLabelN.setText(text);
				textLabelS.setText(text);
				Thread.sleep(250); 
				ch = text.charAt(0); 
				text = text.substring(1, text.length()) + ch; 
			} 
		} 
		catch (InterruptedException e) { 
			e.printStackTrace(); 
		} 
	}
	 
	public static void main (String [] args) {
		try {
			SwingUtilities.invokeLater(new Runnable () {
				@Override
				public void run () {
					new TextScrollS();
				}
			});
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}

}  