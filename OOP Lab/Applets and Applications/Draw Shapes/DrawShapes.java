//
//	DrawShapes.java
//	Draw shapes using a applet.
//
//	Created by Avikant Saini on 6/11/15
//

import java.awt.*;
import java.applet.*;
import java.awt.event.*;
import java.util.*;

/* <applet code="DrawShapes" width=848 height=480>
 * </applet>
 * */

 enum ShapeType {
    ShapeTypeOval,
    ShapeTypeArc,
    ShapeTypeRect,
    ShapeTypeRoundRect,
    ShapeTypeLine,
    ShapeTypeHexagon
}

public class DrawShapes extends Applet {

    Point currentPoint;

    Point startPoint, endPoint;
    ArrayList<Point> startPoints;
    ArrayList<Point> endPoints;

    ShapeType shapeType;
    ArrayList<ShapeType> shapeTypes;

    CheckboxGroup checkBoxGroup;

    final String kButtonTitles [] = {"Rectangle", "Rounded Rectangle", "Line", "Arc", "Oval", "Hexagon Bezier"};
    final ShapeType kShapeTypes [] = {ShapeType.ShapeTypeRect, ShapeType.ShapeTypeRoundRect, ShapeType.ShapeTypeLine, ShapeType.ShapeTypeArc, ShapeType.ShapeTypeOval, ShapeType.ShapeTypeHexagon};

    public DrawShapes () {

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
                shapeTypes.add(shapeType);
                repaint();
            }
        });

        addMouseMotionListener(new MouseMotionAdapter() {

            @Override
            public void mouseDragged(MouseEvent e) {
                endPoint = e.getPoint();
                currentPoint = e.getPoint();
                repaint();
            }

        });
        
    }

    @Override
    public void init () {
        super.init();

        startPoint = new Point(0, 0);
        endPoint = new Point(0, 0);

        currentPoint = new Point(0, 0);

        startPoints = new ArrayList<Point>();
        endPoints = new ArrayList<Point>();

        shapeType = ShapeType.ShapeTypeRect;
        shapeTypes = new ArrayList<ShapeType>();

        checkBoxGroup = new CheckboxGroup();

        for (int i = 0; i < 6; ++i) {
            Checkbox checkBox = new Checkbox(kButtonTitles[i], checkBoxGroup, i == 0);
            final int finalI = i;
            checkBox.addItemListener(new ItemListener() {
                @Override
                public void itemStateChanged(ItemEvent e) {
                    shapeType = kShapeTypes[finalI];
                }
            });
            add(checkBox);
        }

    }

    public String pointString (Point point) {
        return ("{ " + point.x + ", " + point.y + " }");
    }

    @Override
    public void paint (Graphics g) {
        super.paint(g);
        g.setColor(new Color(0xABABAB));
        drawShape(g, shapeType, startPoint, endPoint);
        showStatus("Mouse: Start: " + pointString(startPoint) + ", End: " + pointString(endPoint));
        for (int i = 0; i < startPoints.toArray().length; ++i) {
            Point startPoint = startPoints.get(i);
            Point endPoint = endPoints.get(i);
            g.setColor(new Color(0x3A5069));
            drawShape(g, shapeTypes.get(i), startPoint, endPoint);
        }
    }

    public void drawShape (Graphics g, ShapeType shapeType, Point startPoint, Point endPoint) {
        switch (shapeType) {
            case ShapeTypeRect: drawRect(g, startPoint, endPoint);
                break;
            case ShapeTypeRoundRect: drawRoundRect(g, startPoint, endPoint);
                break;
            case ShapeTypeLine: drawLine(g, startPoint, endPoint);
                break;
            case ShapeTypeArc: drawArc(g, startPoint, endPoint);
                break;
            case ShapeTypeOval: drawOval(g, startPoint, endPoint);
                break;
            case ShapeTypeHexagon: drawHexagon(g, startPoint, endPoint);
                break;
            default:
                break;
        }
    }

    public void drawRect (Graphics g, Point startPoint, Point endPoint) {
        g.drawRect(Math.min(startPoint.x, endPoint.x), Math.min(startPoint.y, endPoint.y), Math.abs(endPoint.x - startPoint.x), Math.abs(endPoint.y - startPoint.y));
    }

    public void drawRoundRect (Graphics g, Point startPoint, Point endPoint) {
        g.drawRoundRect(Math.min(startPoint.x, endPoint.x), Math.min(startPoint.y, endPoint.y), Math.abs(endPoint.x - startPoint.x), Math.abs(endPoint.y - startPoint.y), 24, 24);
    }

    public void drawLine (Graphics g, Point startPoint, Point endPoint) {
        g.drawLine(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
    }

    public void drawArc (Graphics g, Point startPoint, Point endPoint) {
        Point centerPoint = new Point((int)(startPoint.x + endPoint.x)/2, (int)(startPoint.y + endPoint.y)/2);
        int radius = (int)Math.sqrt(Math.pow(centerPoint.x - startPoint.x, 2) + Math.pow(centerPoint.y - startPoint.y, 2));
        Point arcStartPoint = new Point(centerPoint.x - radius, centerPoint.y - radius);
        int startAngle = (int)Math.toDegrees(Math.atan2(startPoint.y - centerPoint.y, startPoint.x - centerPoint.x));
        int endAngle = (int)Math.toDegrees(Math.atan2(endPoint.y - centerPoint.y, endPoint.x - centerPoint.x));
        g.drawArc(arcStartPoint.x, arcStartPoint.y, 2*radius, 2*radius, startAngle, endAngle);
    }

    public void drawOval (Graphics g, Point startPoint, Point endPoint) {
        g.drawOval(Math.min(startPoint.x, endPoint.x), Math.min(startPoint.y, endPoint.y), Math.abs(endPoint.x - startPoint.x), Math.abs(endPoint.y - startPoint.y));
    }

    public void drawHexagon (Graphics g, Point startPoint, Point endPoint) {
        int deav = (int)(endPoint.y - startPoint.y)/(endPoint.x + startPoint.x);
        int xPoints[] = {startPoint.x, startPoint.x + deav, startPoint.x + deav * 2, endPoint.x, endPoint.x - deav * 2, endPoint.x - deav};
        int yPoints[] = {startPoint.y, startPoint.y + deav, startPoint.y + deav * 2, endPoint.y, endPoint.y - deav * 2, endPoint.y - deav};
        int pointCount = 6;
        g.drawPolygon(xPoints, yPoints, pointCount);
    }

}

