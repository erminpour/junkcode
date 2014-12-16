
/*
* Victor Hugo Erminpour
* StudentDriver.java (Bubble Sort)
*/

import java.util.*;

public class StudentDriver {

  public static void printArray(Student[] students) {
    for(Student s : students)
      System.out.println(s);
  }

  public static void printBanner(String str) {
    System.out.println("-------------------------");
    System.out.println(str);
    System.out.println("-------------------------");
  }

  public static void main(String args[]) {

    // create array of Students
    Student students[] = {
      new Student("John", "Doe", 1, 3.00F),
      new Student("Jane", "Doe", 2, 3.50F),
      new Student("Seymour", "Butz", 3, 1.00F),
      new Student("Dan", "Druff", 4, 3.20F),
      new Student("Willie", "Makeit", 5, 3.30F),
    };

    printBanner("UNSORTED:");
    printArray(students);

    // sort Student array by lastName
    Sorter.bubbleSort(students);

    printBanner("BUBBLE SORTED (BY LAST NAME):");
    printArray(students);
  }
}

