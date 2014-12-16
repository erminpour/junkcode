
/*
* Victor Hugo Erminpour
* MathUtils.java
*/

import java.util.*;

public class MathUtils {

  private static boolean closeEnough(double a, double b) {
    return (Math.abs(a-b) < Math.abs(b * 0.0001));
  }

  //Newton-Raphson Algorithm
  static double NRGetRoot(double x, Derives derived) {

	// NR: Output like this means you can't use NRGetRoot in contexts where you
	// don't want to print to System.out.
    System.out.println("Guessing: " + x);

    double newGuess = (x - (derived.getVal(x) / derived.getDVal(x)));

    if (closeEnough(newGuess, x))
      return newGuess;
    else
      return NRGetRoot(newGuess, derived);
  }
}

// Score: 10/10
