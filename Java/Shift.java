
/* 
*  Victor Hugo Erminpour
*  Shift.java
*/

import java.util.*;

public class Shift {

  private Worker workerOne;
  private Worker workerTwo;
  private String scheduleDate;

  Shift(Worker workerOne, Worker workerTwo, String scheduleDate) {
    this.workerOne = workerOne;
    this.workerTwo = workerTwo;
    this.scheduleDate = scheduleDate;
  }

  // toString()
  public String toString() {
    return (this.scheduleDate + " Worker1: " + this.workerOne + " Worker2: " 
            +  this.workerTwo);
  }
}

