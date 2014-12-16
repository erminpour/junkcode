
/*
 * Victor Hugo Erminpour
 * StackImpl.java
 */

import java.util.EmptyStackException;

public class StackImpl extends Stack {

  private static final int SIZE = 1;

  StackImpl() {
    data = new Object[SIZE];
    stackPointer = -1;
  }

  public void push(Object o) {
    if((stackPointer + 1) == data.length)
      expandStack();
    data[++stackPointer] = o;
  }

  public Object pop() {
    if(empty())
      throw new EmptyStackException();
  return data[stackPointer--];
  }

  public Object peek() {
    if(empty())
      throw new EmptyStackException();
  return data[stackPointer];
  }

  /* helper method to expand stack size by 1 */
  private void expandStack() {
    Object[] newStack;
        
    newStack = new Object[data.length + 1];
    for( int i = 0; i < data.length; i++ )
      newStack[i] = data[i];
      data = newStack;
  }

  public static void main(String[] args) {
    StackImpl stack = new StackImpl();
    stack.push("Foo");
    stack.push("Bar");
    stack.push("Baz");

    System.out.println("Top of Stack == " + (String)stack.peek());
    System.out.println("Pop Stack == " + (String)stack.pop());
    System.out.println("Pop Stack == " + (String)stack.pop());
    System.out.println("Pop Stack == " + (String)stack.pop());
  }
}

// NR: Excellent!
// Score: 10/10
