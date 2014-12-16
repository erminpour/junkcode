
// Reorder.java
// by Victor Hugo Erminpour
import java.util.*;

public class Reorder {

  public static void printArray(int [] array, String arrayName) {
	// NR: this gives ugly output...
    // print array
    for(int count = 0; count < array.length; count++) {
      if(count == 0) {
        System.out.print(arrayName + "[ " + array[count] + ", ");
      }
      else if(count == (array.length-1)) {
        System.out.println(array[count] + " ]");
      }
      else {
        System.out.print(array[count] + ", ");
      }
    }
  }

  public static void reorder(int [] arr, int [] perm) {
    int tmp;
    // arr_new[i] = arr_old[perm[i]] 
    for (int index2=0; index2 < arr.length; index2++) {
      tmp = perm[index2];
      perm[index2] = arr[tmp];
    }
  }

  public static void main(String args[]) {

  //int arr[] = {0,4, -1, 1000};
  //int perm[] = {3,0,1,2};
  int arr[] = new int[(args.length-1)/2];
  int perm[] = new int[(args.length-1)/2];
  int index;

  // Parse commandline
  // NR: The specified symbol is &.  You can escape it in the shell.
  for(index=0; !args[index].equals("$"); index++) {
    arr[index] = Integer.parseInt(args[index]);
  }
  // skip '$'
  index++;
  for(int count = 0; count < ((args.length-1)/2); count++) {
    perm[count] = Integer.parseInt(args[index]);
    index++;
  }

  // Print parsed arrays
  printArray(arr, "arr");
  printArray(perm, "perm");

  reorder(arr, perm);
  printArray(perm, "arr_new");

  } // end main()
} // end Reorder 

// NR: 9/10
