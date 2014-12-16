
// ReverseEcho.java
// by Victor Hugo Erminpour
import java.util.*; //NR: Don't import what you don't need

public class ReverseEcho {
  public static void main(String args[]) {
    // Check to see if we have input on the commandline
    if(args.length > 0) {
      for(int index = (args.length-1); index >=0; index--)
        System.out.print(args[index] + " ");
      System.out.println("");
    }
    else
    {
      System.out.println("No input.");
    }
  }
}

// Score: 10/10
