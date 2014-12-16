
/* 
 * Victor Hugo Erminpour
 * Histogram.java
 */ 

import javax.swing.*;
import java.awt.*;
import java.awt.geom.*;
import java.awt.event.*;

public class Histogram extends JFrame {

  double[] data;
  int num_bins;

  Histogram(double[] data, int num_bins) {
    /* setup JFrame */
    Container cp = getContentPane();
    setSize(400,400);
    setVisible(true);

    WindowListener wndCloser = new WindowAdapter() {
      public void windowClosing(WindowEvent e) {
        System.exit(0);
      }
    };
    addWindowListener(wndCloser);
  
// NR: Try array.clone.  Or Arrays.copyOf
    this.num_bins = num_bins;
    this.data = new double[data.length];
    for(int i=0; i<data.length; i++)
      this.data[i] = data[i];
  }

// NR: data are actually data-points, not histogram counts.
  public void paint(Graphics g) {
    super.paint(g);

    int width = 50;

    for (int x=20, y=250,i=0; i < this.data.length; i++, x+=50) {
      g.setColor(Color.red);
      g.fillRect(x, y-(int)this.data[i], width, (int)this.data[i]);

      g.setColor(Color.black);
      g.drawRect(x, y-(int)this.data[i], width, (int)this.data[i]);
    }
  }

  public static void main(String[] args) {
    double n[] = {10, 75, 15, 77, 52, 26, 62};
    Histogram gui = new Histogram(n, 10);
  }
}


// Score: 8/10
