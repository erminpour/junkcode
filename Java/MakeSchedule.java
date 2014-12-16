
/* 
*  Victor Hugo Erminpour
*  MakeSchedule.java
*/

import java.util.*;
import java.text.SimpleDateFormat;

public class MakeSchedule {

  private static void parseCalendarDate(String startDate, Calendar cStartDate, 
                                        String endDate, Calendar cEndDate) {
    String []tmp = startDate.split("/");
    int month = Integer.parseInt(tmp[0]);
    int day = Integer.parseInt(tmp[1]);
    int year = Integer.parseInt(tmp[2]);
    cStartDate.set(year, month, day);

    // setup second date
    tmp = endDate.split("/");
    month = Integer.parseInt(tmp[0]);
    day = Integer.parseInt(tmp[1]);
    year = Integer.parseInt(tmp[2]);
    cEndDate.set(year, month, day);
  }

  private static int calcNumDaysInSchedule(Calendar startDate, 
                                           Calendar endDate) {

    // Get the represented date in milliseconds
    long milis1 = startDate.getTimeInMillis();
    long milis2 = endDate.getTimeInMillis();

    // Calculate difference in milliseconds
    long diff = milis2 - milis1;
         
    // Return difference in days
    return (int) (diff / (24 * 60 * 60 * 1000));
  }

  public static void main(String args[]) {

    if(args.length !=4) {
      System.out.println("Usage: MakeSchedule <n> <m> <beginDate> <endDate>\n" 
                         + "n == total number of workers\n" +
                         "m == number of workers per shift");
      System.exit(1);
    }

    int n = Integer.parseInt(args[0]);
    int m = Integer.parseInt(args[1]);

    Calendar cStartDate = Calendar.getInstance();
    Calendar cEndDate = Calendar.getInstance();
 
    parseCalendarDate(args[2], cStartDate, args[3], cEndDate);
    int numDays = calcNumDaysInSchedule(cStartDate, cEndDate); 

    int minNumDays = (n/m);
    if (n % 2 != 0)
      minNumDays++;

    if (numDays < minNumDays ) {
      System.err.println("ERROR: You need at least " + minNumDays + 
                         " days for the schedule"); 
      System.exit(1);
    }

    // Setup workers
    Worker[] workers = new Worker[n];
    for(int count=0; count < n; count++) {
      workers[count] = new Worker(count);;
    }
    // Setup schedule
    Shift[] shift = new Shift[numDays];
    
	// NR: This doesn't enforce workers sharing weekends fairly.
    SimpleDateFormat formatter = new SimpleDateFormat("MM/dd/yy");
    int workerCount1=0;
    int workerCount2=0;
    for (int count = 0; count < numDays; count++) {

      if(workerCount1 == (n-1))
        workerCount1=0;
      else
        workerCount1++;

      if(workerCount2 == 0)
        workerCount2 = (n-1);
      else
        workerCount2--;

      shift[count] = new Shift( workers[workerCount1], workers[workerCount2] , 
                                formatter.format(cStartDate.getTime()));
      cStartDate.add(Calendar.DAY_OF_YEAR, 1);
      System.out.println(shift[count]);
    }
  }
}

// Score: 5 extra credit points
