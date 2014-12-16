
/* 
 * FindDup.java
 * Victor Hugo Erminpour
 */

import java.util.Set;
import java.util.HashSet;

public class FindDup {

  public static void main(String args[]) {
    Set<String> set = new HashSet<String>();

    for(String s: args)
      if(! set.add(s))
        System.out.println(s + " is a duplicate.");
  }
}

// Score: 10/10
