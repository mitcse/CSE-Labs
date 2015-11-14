//
//	NumberOperations.java
//	Input two floating point numbers from the user, and calculate their +, -, *, /, % using a swing application.
//
//	Created by Avikant Saini on 5/11/15
//

import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class NumberOperations {

    JTextField field1, field2;

    JButton computeButton;

    JLabel labelSum, labelDifference, labelRemainder, labelProduct, labelModulo;

    public NumberOperations () {

        JFrame frame = new JFrame("Number Operations");
        frame.setSize(600, 400);
        frame.setBackground(new Color(0xFCF9EE));
        frame.setResizable(false);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        frame.setLayout(new GridLayout(2, 1));

        field1 = new JTextField("");
        field1.setHorizontalAlignment(JTextField.CENTER);

        field2 = new JTextField("");
        field2.setHorizontalAlignment(JTextField.CENTER);

        JPanel fieldPanel = new JPanel(new GridLayout(3, 1));

        computeButton = new JButton("Compute");

        computeButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                double a = 0.0, b = 0.0;
                double sum = 0.0, diff = 0.0, prod = 0.0, rem = 0.0, modu = 0.0;
                try {
                    a = Double.parseDouble(field1.getText());
                    b = Double.parseDouble(field2.getText());

                    sum = a + b;
                    diff = a - b;
                    prod = a * b;
                    rem = a / b;
                    modu = a % b;
                }
                catch (NumberFormatException e1) {
                    JOptionPane.showMessageDialog(null, "Number Format Exception: " + e1 + ".", "Error", JOptionPane.ERROR_MESSAGE);
                }
                catch (ArithmeticException e1) {
                    JOptionPane.showMessageDialog(null, "Airthmetic Exception: " + e1 + ".", "Error", JOptionPane.ERROR_MESSAGE);
                }
                finally {
                    labelSum.setText("  " + String.format("%.4f", a) + "\n+ " + String.format("%.4f", b) + "\n= " +  String.format("%.4f", sum));
                    labelDifference.setText("  " + String.format("%.4f", a) + "\n- " +  String.format("%.4f", b) + "\n= " +  String.format("%.4f", diff));
                    labelProduct.setText("  " + String.format("%.4f", a) + "\n* " +  String.format("%.4f", b) + "\n= " +  String.format("%.4f", prod));
                    labelRemainder.setText("  " + String.format("%.4f", a) + "\n/ " +  String.format("%.4f", b) + "\n= " +  String.format("%.4f", rem));
                    labelModulo.setText("  " + String.format("%.4f", a) + "\n% " +  String.format("%.4f", b) + "\n= " +  String.format("%.4f", modu));
                }
            }
        });

        fieldPanel.add(field1);
        fieldPanel.add(field2);
        fieldPanel.add(computeButton);

        labelSum = new JLabel("", JLabel.CENTER);
        labelDifference = new JLabel("", JLabel.CENTER);
        labelProduct = new JLabel("", JLabel.CENTER);
        labelRemainder = new JLabel("", JLabel.CENTER);
        labelModulo = new JLabel("", JLabel.CENTER);

        JPanel labelPanel = new JPanel(new GridLayout(5, 1));

        labelPanel.add(labelSum);
        labelPanel.add(labelDifference);
        labelPanel.add(labelProduct);
        labelPanel.add(labelRemainder);
        labelPanel.add(labelModulo);

        frame.add(fieldPanel);
        frame.add(labelPanel);

        frame.setVisible(true);

    }

    public static void main (String[] args) {

        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new NumberOperations();
            }
        });

    }

}
