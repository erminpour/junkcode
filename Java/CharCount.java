
// CharCount.java
// by Victor Hugo Erminpour
import java.util.*;

public class CharCount {

  public static void main(String args[]) {

    if(args.length != 2) {
      System.err.println("ERROR: Invalid argument count!");
      System.exit(1);
    }
    // If the first args String has more one character, error out.
    if(args[0].length() > 1) {
      System.err.println("ERROR: Invalid search char argument!");
      System.exit(1);
    }
    // Convert the first character of the string to uppercase
    // and assign to searchChar.
    char searchChar = Character.toUpperCase(args[0].charAt(0));
    System.out.println("searchChar = " + searchChar);

    String filename = args[1];
    String[] fileContents = TextManipTools.readFileByLine(filename);
    int counter=0;

    for (int index1=0; index1 < fileContents.length; index1++) {
      //System.out.println(fileContents[index1].toUpperCase());
      for(int index2=0; index2<fileContents[index1].length(); index2++) {
        if(fileContents[index1].toUpperCase().charAt(index2) == searchChar) {
          // We've found the searchChar in the uppercase String.
          // Increment the counter.
          counter++;
        }
      }
    }
    System.out.println("The character '" + searchChar + "' or '" +
                       Character.toLowerCase(searchChar) + "' found " + 
                       counter + " time(s).");
  } // end main()
} // end CharCount

// Score: 10/10
