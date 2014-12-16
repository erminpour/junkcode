
/*
* Victor Hugo Erminpour
* Sorter.java
*/

public class Sorter {
  // Bubble Sort using MyComparable interface
  public static void bubbleSort(MyComparable[] array) {
    int n = array.length;
    MyComparable [] tmpArray = new MyComparable[array.length];
    for (int pass=1; pass < n; pass++) {
      for (int i=0; i < n-pass; i++) {
        if (array[i].compareTo(array[i+1]) > 0) {
          tmpArray[i] = array[i];
          array[i] = array[i+1];
          array[i+1] = tmpArray[i];
        }
      }
    }
  }
}

// Score: 9.5/10
