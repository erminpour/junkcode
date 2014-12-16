
/*
 * ListTest.java
 * Victor Hugo Erminpour
 */

import java.util.*;

public class ListTest {

  private int numElements;

  ListTest() {
    this.setNum(1000);
  }

  public void setNum(int num) {
    this.numElements = num;
  }

  public int getNum() {
    return this.numElements;
  }

  public void initList(List list) {
    for(int i = 0; i < this.numElements; i++)
      list.add(i);
  }

  void runTests(HashSet set) {

    System.out.println("-------------" + set.getClass().getSimpleName() 
                     + "-------------\n" + "numElements = " 
                     + this.numElements);
    // contains()
    long stopWatch = System.currentTimeMillis();
    for (int i = 0; i < this.numElements; i++) {
      set.contains(i);
    }
    stopWatch = (System.currentTimeMillis() - stopWatch);
    System.out.println("BOL : \t contains() = \t" + stopWatch + "\n");
  }

  void runTests(List list) {

    System.out.println("-------------" + list.getClass().getSimpleName() 
                     + "-------------\n" + "numElements = " 
                     + this.numElements);

    // Beginning of List
    // add()
    long stopWatch = System.currentTimeMillis();
    for (int i = 0; i < this.numElements; i++) {
      list.add(0, new Object());
      list.remove(0);
    }
    stopWatch = (System.currentTimeMillis() - stopWatch);
    System.out.println("BOL : \t add() = \t" + stopWatch);

    // get()
    stopWatch = System.currentTimeMillis();
    for (int i = 0; i < this.numElements; i++) {
      list.get(0);
    }
    stopWatch = (System.currentTimeMillis() - stopWatch);
    System.out.println("BOL : \t get() = \t" + stopWatch + "\n");

    // Middle of List
    // add()
    stopWatch = System.currentTimeMillis();
    for (int i = 0; i < this.numElements; i++) {
      list.add(this.numElements / 2, new Object());
      list.remove(this.numElements / 2);
    }
    stopWatch = (System.currentTimeMillis() - stopWatch);
    System.out.println("MOL : \t add() = \t" + stopWatch);

    stopWatch = System.currentTimeMillis();
    for (int i = 0; i < this.numElements; i++) {
      list.get(this.numElements / 2);
    }
    stopWatch = (System.currentTimeMillis() - stopWatch);
    System.out.println("MOL : \t get() = \t" + stopWatch + "\n");

    // End of List
    // add()
    stopWatch = System.currentTimeMillis();
    for (int i = 0; i < this.numElements; i++) {
      list.add(new Object());
      list.remove(this.numElements);
    }
    stopWatch = (System.currentTimeMillis() - stopWatch);
    System.out.println("EOL : \t add() = \t" + stopWatch);

    // get()
    stopWatch = System.currentTimeMillis();
    for (int i = 0; i < this.numElements; i++) {
      list.get((this.numElements-1));
    }
    stopWatch = (System.currentTimeMillis() - stopWatch);
    System.out.println("EOL : \t get() = \t" + stopWatch + "\n");

  }

  public static void main(String arrayListgs[]) {

    ListTest test = new ListTest();
    List arrayList = new ArrayList();

    // ArrayList and LinkedList add()/get() performance

    // 1,000 elements
    test.initList(arrayList);
    test.runTests(arrayList);
    test.runTests(new LinkedList(arrayList));

    // 10,000 elements
    test.setNum(10000);
    test.initList(arrayList);
    test.runTests(arrayList);
    test.runTests(new LinkedList(arrayList));

    // 100,000 elements
    test.setNum(100000);
    test.initList(arrayList);
    test.runTests(arrayList);
    test.runTests(new LinkedList(arrayList));

    // HashSet contains() performance

    // 1,000 elements
    test.setNum(1000);
    test.initList(arrayList);
    test.runTests(new HashSet(arrayList));

    // 10,000 elements
    test.setNum(10000);
    test.initList(arrayList);
    test.runTests(new HashSet(arrayList));

    // 100,000 elements
    test.setNum(100000);
    test.initList(arrayList);
    test.runTests(new HashSet(arrayList));
  }
}

// Score: 10/10
