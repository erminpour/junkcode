
/*
 * Hexagon.java
 * Victor Hugo Erminpour
 */

import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.util.*;

public class Hexagon extends Frame {

// NR: You use a lot of fixed values in this code.  That makes it hard to
// change the parameters, because even if you go back to change all the values,
// you have to figure out which values are related, and how. -1pt
  public void paint(Graphics g) {
// NR: No call to super.paint? -1pt

  Graphics2D ga = (Graphics2D)g;
  Polygon hexagon = new Polygon();
// NR: array is an undescriptive name. Any why the fixed length? -.5pt
  Shape array[] = new Shape[30*30];

  for (int i = 0; i < 6; i++) {
    hexagon.addPoint((int) (150 + 100 * Math.cos(i * 2 * Math.PI / 6)),
                     (int) (150 + 100 * Math.sin(i * 2 * Math.PI / 6)));
  }

  g.drawPolygon(hexagon);
  ga.setPaint(Color.red);

  int x=0;
  int y=0;
  int i=0;
  for(double coor1 = x; coor1 < 300; coor1+=10)
  { 
    for(double coor2 = y; coor2 < 300; coor2+=10)
    {
      if(hexagon.contains(coor1, coor2))
      {
// NR: Why store in the array?
        array[i] = new Ellipse2D.Double(coor1, coor2, 10.0d, 10.0d);
        ga.draw(array[i]);
        ga.setPaint(Color.green);
        ga.fill(array[i]);
        i++;
      }
    }
  }
}

  public static void main(String args[]) {
    Frame frame = new Hexagon();
    frame.addWindowListener(new WindowAdapter(){
      public void windowClosing(WindowEvent we){
        System.exit(0);
      }
    });
    frame.setSize(325, 275);
    frame.setVisible(true);
  }
}

// Score: 7.5/10
