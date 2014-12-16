
/*
 * Stack.java (Generics)
 * Victor Hugo Erminpour
 */

import java.util.EmptyStackException;
import java.lang.reflect.Array;

public class Stack <T> {

  private T[] elements;
  protected int stackPointer;
  private static final int SIZE = 1;

  @SuppressWarnings({"unchecked"})
  Stack() {
    this.elements = (T[]) new Object[SIZE];
    stackPointer = -1;
  }

  public void push(T data) {
// NR: why Array.getLength?  You can just call elements.length, right?
    if((stackPointer + 1) == Array.getLength(this.elements))
      expandStack();
    this.elements[++stackPointer] = data;
  }

  public T pop() {
    if(empty())
      throw new EmptyStackException();
  return this.elements[stackPointer--];
  }

  public T peek() {
    if(empty())
      throw new EmptyStackException();
  return this.elements[stackPointer];
  }

  /* helper method to expand stack size by 1 */
  @SuppressWarnings({"unchecked"})
  private void expandStack() {
    T[] newStack;
        
    newStack = (T[]) new Object[Array.getLength(this.elements) + 1];
    for( int i = 0; i < Array.getLength(this.elements); i++ )
      newStack[i] = this.elements[i];
    this.elements = newStack;
  }

  public boolean empty() {
    return stackPointer == -1;
  }

  public static void main(String[] args) {

    Stack<Integer> int_Stack = new Stack <Integer>();
    Stack<String> string_Stack = new Stack <String>();

    string_Stack.push("Foo");
    string_Stack.push("Bar");
    string_Stack.push("Baz");

    int_Stack.push(1);
    int_Stack.push(2);
    int_Stack.push(3);

    System.out.println("Integer Stack:");
    System.out.println("Top of Stack == " + int_Stack.peek());
    System.out.println("Pop Stack == " + int_Stack.pop());
    System.out.println("Pop Stack == " + int_Stack.pop());
    System.out.println("Pop Stack == " + int_Stack.pop() + "\n");

    System.out.println("String Stack:");
    System.out.println("Top of Stack == " + string_Stack.peek());
    System.out.println("Pop Stack == " + string_Stack.pop());
    System.out.println("Pop Stack == " + string_Stack.pop());
    System.out.println("Pop Stack == " + string_Stack.pop());
  }
}

// Score: 10/10
