//
//	RandomCircle.java
//	Display a circle of random radius and it's radius, diam, circum, and area.
//
//	Created by Avikant Saini on 6/11/15
//

import java.awt.*;
import java.applet.*;
import java.awt.event.*;

/* <applet code="RandomCircle" width=640 height=640>
 * </applet>
 * */

public class RandomCircle extends Applet {

    private int circlesDrawn;

    private double radius, diameter, circumference, area;

    private Button redrawButton;

    private Label radiusLabel, diamaterLabel, circumferenceLabel, areaLabel;
    private Panel labelPanel;

    public RandomCircle () {

        redrawButton = new Button("Redraw");
        redrawButton.addKeyListener(new KeyAdapter() {
            @Override
            public void keyReleased(KeyEvent e) {
                super.keyReleased(e);
                if (e.getKeyCode() == KeyEvent.VK_SPACE) {
                    repaint();
                }
            }
        });
        redrawButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                setRadius(Math.random() * 100 + 100);
                ++circlesDrawn;
                repaint();
            }
        });

        radiusLabel = new Label("", Label.CENTER);
        diamaterLabel = new Label("", Label.CENTER);
        circumferenceLabel = new Label("", Label.CENTER);
        areaLabel = new Label("", Label.CENTER);

        labelPanel = new Panel(new GridLayout(4, 1));
        labelPanel.add(radiusLabel);
        labelPanel.add(diamaterLabel);
        labelPanel.add(circumferenceLabel);
        labelPanel.add(areaLabel);

        add(labelPanel);
        add(redrawButton);
    }

    @Override
    public void init () {
        super.init();
        setRadius(Math.random() * 100 + 100);
        circlesDrawn = 1;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public double getArea() {
        return Math.PI * radius * radius;
    }

    public double getDiameter() {
        return radius * 2;
    }

    public double getCircumference() {
        return 2 * Math.PI * radius;
    }

    @Override
    public void paint (Graphics g) {
        super.paint(g);
        g.setColor(new Color(0x3A5069));
        g.drawOval(40, 80, (int) getDiameter(), (int) getDiameter());
        radiusLabel.setText("Radius = " + String.format("%.2f", getRadius()));
        diamaterLabel.setText("Diameter = " + String.format("%.2f", getDiameter()));
        circumferenceLabel.setText("Circumference = " + String.format("%.2f", getCircumference()));
        areaLabel.setText("Area = " + String.format("%.2f", getArea()));
        showStatus("Circles drawn: " + circlesDrawn);
    }

}
