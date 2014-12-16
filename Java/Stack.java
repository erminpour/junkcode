
/*
 * Victor Hugo Erminpour
 * Stack.java
 */

/* Stack abstract class */
public abstract class Stack{
    protected int stackPointer;
    protected Object[] data;
    public abstract void push(Object o);
    public abstract Object pop();
    public abstract Object peek();
    public boolean empty(){ return stackPointer == -1; }
}

