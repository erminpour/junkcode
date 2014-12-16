
// Uppercase.java
// by Victor Hugo Erminpour
import java.util.*;

public class Uppercase {

  public static void main(String args[]) {

    if(args.length != 1) {
      System.err.println("ERROR: Invalid argument count!");
      System.exit(1);
    }
    String filename = args[0];
    String[] fileContents = TextManipTools.readFileByLine(filename);

	// What about if next letter comes after some blankspace?
    for (int index1=0; index1 < fileContents.length; index1++) {
      for(int index2=0; index2 < fileContents[index1].length(); index2++) {
        // If the char we're looking at is a '.', and the index 
        // is not equal to the size of the index minus 1, we've got a match.
        if(fileContents[index1].charAt(index2) == '.' && index2 != (fileContents[index1].length()-1)) {
          // We've found a period, transform the string to a char array
          // and replace the char after the period.  Then, set the original
          // string to the modified char array.
          char[] myString = fileContents[index1].toCharArray();
          myString[index2+1] = Character.toUpperCase(fileContents[index1].charAt(index2+1));
          fileContents[index1] = String.valueOf(myString);
        }
      }
    System.out.println(fileContents[index1]);
    }
  } // end main()
} // end Uppercase

// Score: 8/10
