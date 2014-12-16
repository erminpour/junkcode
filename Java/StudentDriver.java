
/*
* Victor Hugo Erminpour
* StudentDriver.java
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

    // sort Student array by GPA
    Arrays.sort(students);

    printBanner("SORTED (BY GPA):");
    printArray(students);

	// NR: But you were asked to use Arrays.sort to shuffle.
    // Shuffle the array
    Collections.shuffle(Arrays.asList(students));

    printBanner("SHUFFLED:");
    printArray(students);
  }
}

// Score: 8/10
