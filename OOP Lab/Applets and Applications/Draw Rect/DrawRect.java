//
//	DrawRect.java
//	Draw rectangles using a applet, display the area of the last rect.
//
//	Created by Avikant Saini on 6/11/15
//

import java.awt.*;
import java.applet.*;
import java.awt.event.*;
import java.util.*;

/* <applet code="DrawRect" width=848 height=480>
 * </applet>
 * */

public class DrawRect extends Applet {

    Point startPoint, endPoint;
    ArrayList<Point> startPoints, endPoints;

    public DrawRect () {

    	// For pressing and releasing
        addMouseListener(new MouseAdapter() {

            @Override
            public void mousePressed (MouseEvent e) {
                super.mousePressed(e);
                startPoint = e.getPoint();
            }

            @Override
            public void mouseReleased (MouseEvent e) {
                super.mouseReleased(e);
                endPoint = e.getPoint();
                startPoints.add(startPoint);
                endPoints.add(endPoint);
                repaint();
            }
        });


        // For the motion event
        addMouseMotionListener(new MouseMotionAdapter() {

            @Override
            public void mouseDragged (MouseEvent e) {
                endPoint = e.getPoint();
                repaint();
            }

        });
    }

    @Override
    public void init () {
        super.init();
        startPoint = new Point(0, 0);
        endPoint = new Point(0, 0);
        startPoints = new ArrayList<Point>();
        endPoints = new ArrayList<Point>();
    }

    @Override
    public void paint (Graphics g) {
        super.paint(g);
        g.setColor(new Color(0x868633));
        g.drawRect(Math.min(startPoint.x, endPoint.x), Math.min(startPoint.y, endPoint.y), Math.abs(endPoint.x - startPoint.x), Math.abs(endPoint.y - startPoint.y));
        showStatus("Area of latest rect = " + Math.abs((startPoint.y - endPoint.y)*(startPoint.x - endPoint.x)));
        for (int i = 0; i < startPoints.toArray().length; ++i) {
            Point startPoint = (Point)startPoints.get(i);
            Point endPoint = (Point)endPoints.get(i);
            g.setColor(new Color(0x3A5069));
            g.drawRect(Math.min(startPoint.x, endPoint.x), Math.min(startPoint.y, endPoint.y), Math.abs(endPoint.x - startPoint.x), Math.abs(endPoint.y - startPoint.y));
        }
    }

}
