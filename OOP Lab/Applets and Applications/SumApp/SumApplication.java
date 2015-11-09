import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class SumApplication {

    JTextField field1, field2;
    JButton computeButton;
    JLabel labelSum;

    public SumApplication () {

        JFrame frame = new JFrame("Number Operations");
        frame.setSize(600, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new FlowLayout());

        field1 = new JTextField("");
        field2 = new JTextField("");

        JPanel fieldPanel = new JPanel(new GridLayout(3, 1));

        computeButton = new JButton("Compute");

        computeButton.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                double a = 0.0, b = 0.0;
                double sum = 0.0;
                try {
                    a = Double.parseDouble(field1.getText());
                    b = Double.parseDouble(field2.getText());
                    sum = a + b;

                }
                catch (Exception e1) {  }
               
                finally {
                    labelSum.setText("  " + a + "\n+ " + b + "\n= " + sum);
                }
            }
        });

        fieldPanel.add(field1);
        fieldPanel.add(field2);
        fieldPanel.add(computeButton);

        labelSum = new JLabel("", JLabel.CENTER);

        frame.add(fieldPanel);
        frame.add(labelSum);

        frame.setVisible(true);

    }

    public static void main (String[] args) {

        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new SumApplication();
            }
        });

    }

}
