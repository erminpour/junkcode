
/*
* Victor Hugo Erminpour
* MutableString.java
*/

import java.util.*;

public class MutableString {

  // NR: I discuss why a char array is not the best choice in my email to
  // students.
  // NR: variables and methods are not typically given names with a leading
  // uppercase letter; that's typically the style for classes.
  private char MutableStringBuffer[];
  private int MutableStringSize;

  // expand the size of the MutableStringBuffer
  private void expandMutableStringBuffer(int MutableStringSize) {
    if(MutableStringSize > this.MutableStringSize) {
      char newMutableStringBuffer[] = new char[MutableStringSize];

	  // NR: Good use of System.arraycopy; it's likely better implemented than
	  // a typical for-loop.
      System.arraycopy(this.MutableStringBuffer, 0, newMutableStringBuffer, 
                       0, MutableStringSize);

      this.MutableStringBuffer = newMutableStringBuffer;
      this.MutableStringSize = MutableStringSize;
    }
  }

  // Constructor()
  public MutableString() {
	// NR: I understand the desire to avoid resizing, but this is a huge cost
	// for an empty string!
    // Create a MutableString 1024 chars in length
    this(1024);
  }

  // Contructor(int MutableStringSize)
  public MutableString(int MutableStringSize) {
    // Create a new char[MutableStringSize];
    this.MutableStringBuffer = new char[MutableStringSize];
    this.MutableStringSize = MutableStringSize;
  }

  // Constructor(String str)
  public MutableString(String str) {
    this(str.length());
    this.set(str);
  }

  // toString()
  public String toString() {
    return new String(this.MutableStringBuffer, 0, MutableStringSize); 
  }

  // length()
  public int length() {
    return MutableStringSize;
  }

  // concat(String str)
  public MutableString concat(String str) {
    if(str.length() > 0) {
      int oldMutableStringSize = this.MutableStringSize;
      this.expandMutableStringBuffer((this.MutableStringSize + str.length()));
      str.getChars(0, str.length(), this.MutableStringBuffer, 
                   oldMutableStringSize); 
    }
  return this;
  }

  // set(String str)
  public MutableString set(String str) {
    if(str.length() > this.MutableStringSize) {
      this.expandMutableStringBuffer(str.length());
    }
    else {
      this.MutableStringSize = str.length();
    }
    str.getChars(0, MutableStringSize, this.MutableStringBuffer, 0);
  return this; 
  }
}

// As one of the more sophisticated students, you might think about whether the
// char array approach is a good implementation of MutableString.
// Score: 9.5/10
