
/*
* Victor Hugo Erminpour
* Polynomial.java
*/

import java.util.*;

public class Polynomial implements Derives {

  private int n;

  Polynomial(int n) {
    this.n = n;
  }

  public double getVal(double x) {
    // f(x) = x^n - 2
    return (Math.pow(x,this.n) - 2);
  }
  public double getDVal(double x) {
    // f'(x) = (n)x^(n-1)
    return (this.n * Math.pow(x, (this.n-1)));
  }
}

