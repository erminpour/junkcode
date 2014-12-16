
/* 
* Victor Hugo Erminpour
* MutableStringDriver.java
*/

import java.util.*;

public class MutableStringDriver {
  public static void main(String args[]) {

    MutableString myMutableString = new MutableString("Hello Mutable String");
    System.out.println(myMutableString);

    myMutableString.set("Foo Bar");
    System.out.println(myMutableString);

    myMutableString.concat(" Baz");
    System.out.println(myMutableString);
  }
}

