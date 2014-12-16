
/* 
*  Victor Hugo Erminpour
*  Worker.java
*/

import java.util.*;

public class Worker {

  private int workerID;

  Worker(int workerID) {
    this.workerID = workerID;
  }

  // toString()
  public String toString() {
    return ("w" + this.workerID);
  }

  // getWorkerID()
  public int getWorkerID() {
    return this.workerID;
  }
  // setWorkerID()
  public void setWorkerID(int workerID) {
    this.workerID = workerID;
  }
}

