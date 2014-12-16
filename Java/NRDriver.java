
/*
* Victor Hugo Erminpour
* Driver.java
*/

import java.util.*;

public class NRDriver {

  public static void main(String[] args) {
    // f(x) = x^2 -2
    Polynomial p = new Polynomial(2);
    double root = MathUtils.NRGetRoot(5, p);
    System.out.println("Root = " + root);

  }
}

