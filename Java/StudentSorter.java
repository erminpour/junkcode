
// StudentSorter.java
// by Victor Hugo Erminpour
import java.util.*;

// Student String Comparator
class StudentStringComparator implements Comparator<String> {
  public int compare(String s1, String s2)
  {
    int intOne, intTwo;
    String[] one = ParserUtils.getTokens(s1);
    String[] two = ParserUtils.getTokens(s2);
    intOne = Integer.parseInt(one[2]);
    intTwo = Integer.parseInt(two[2]);

    if(intOne == intTwo){
      intOne = Integer.parseInt(one[3]);
      intTwo = Integer.parseInt(two[3]);
      if(intOne < intTwo)
        return -1;
      else
        return 1;
    }
    else {
      if(intOne < intTwo)
        return -1;
      else
        return 1;
    }
  }
}

public class StudentSorter {

  public static void main(String args[]) {
    // StudentSorter <filename>
    if(args.length != 1) {
      System.err.println("ERROR: Invalid argument count!");
      System.exit(1);
    }
    String filename = args[0];
    String[] fileContents = TextManipTools.readFileByLine(filename);

    // Sort the array using the Comparator
    Arrays.sort(fileContents, new StudentStringComparator());

    // Print out list
    for(String s:fileContents)
      System.out.println(s);

  } // end main()
} // end StudentSorter 

// Score: 10/10
