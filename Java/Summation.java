
// Summation.java
// by Victor Hugo Erminpour
import java.util.*;

public class Summation {

  public static void main(String args[]) {

    if(args.length != 2) {
      System.err.println("ERROR: Invalid argument count!");
      System.exit(1);
    }

    int minval, maxval, sum;
    minval = maxval = sum = 0;

    try {
      minval = Integer.parseInt(args[0]);
      maxval = Integer.parseInt(args[1]);
    }
    catch (NumberFormatException e) {
      System.err.println("ERROR: Please enter valid numbers!");
      System.exit(1);
    }

    System.out.println("minval = " + minval);
    System.out.println("maxval = " + maxval);

	// What about out-of-order argumnets?
    for(int index = minval; index <= maxval; index++) {
      sum += index;
    }
    System.out.println("Sum = " + sum);

  } // end main()
} // end Summation

// Score: 10 / 10

