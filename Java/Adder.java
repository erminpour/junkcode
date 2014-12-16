
// Adder.java
// by Victor Hugo Erminpour
import java.util.*;

public class Adder {

  // small usage helper method
  static void usageMsg(String msg) {
    System.err.println(msg);
    System.err.println("Usage: <number1> <op> <number2>");
  }

  public static void main(String args[]) {

    String cmd = "NULL";
    int firstVal, secondVal;
    firstVal = secondVal = 0;

    for(;;){
      System.out.print("ADDER>> ");
      cmd = ParserUtils.getKeyInput();
      System.out.println(cmd);

      if(cmd.equals("exit")) {
        System.out.println("Goodbye!");
        System.exit(0);
      }

      String[] tokens = ParserUtils.getTokens(cmd);
      if(tokens.length !=3) {
        usageMsg("ERROR: You must enter exactly three options.");
        continue;
      }
      try {
        firstVal = Integer.parseInt(tokens[0]);
        secondVal = Integer.parseInt(tokens[2]);
      }
      catch (NumberFormatException e) {
        usageMsg("ERROR: Please enter valid numbers!");
        continue;
      }

      // Addition
      if(tokens[1].equals("+")) {
        System.out.println((firstVal+secondVal));
        continue; 
      }

      // Subtraction
      if(tokens[1].equals("-")) {
        System.out.println((firstVal-secondVal));
        continue; 
      }

      // Multiplication
      if(tokens[1].equals("*")) {
        System.out.println((firstVal*secondVal));
        continue; 
      }

      // Division
      if(tokens[1].equals("/")) {
        System.out.println((firstVal/secondVal));
        continue; 
      }
      // Modulus
      if(tokens[1].equals("%")) {
        System.out.println((firstVal%secondVal));
        continue; 
      }
      // If we're here, Error
      usageMsg("ERROR: Invalid Input!");
      continue; 

    } // end for(;;)
  } // end main()
} // end Adder 

// Score: 10/10
