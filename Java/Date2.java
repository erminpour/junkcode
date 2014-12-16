
// Date2.java
// by Victor Hugo Erminpour
import java.util.*;
import java.text.*;

public class Date2 {

  public static long numberOfDays(Calendar startDate, Calendar endDate) {  
    Calendar date = (Calendar) startDate.clone();  
    long numberOfDays = 0;  

    while (date.before(endDate)) {  
      date.add(Calendar.DAY_OF_MONTH, 1);  
      numberOfDays++;  
    }
    return numberOfDays;  
  }  

  public static void main(String args[]) {

    if(args.length != 2) {
      System.err.println("ERROR: Invalid argument count!");
      System.err.println("Usage: Date1 <MM/DD/YYYY> <MM/DD/YYYY>");
      System.exit(1);
    }

    Calendar cDate1, cDate2;

    cDate1=Calendar.getInstance();
    cDate2=Calendar.getInstance();

    try {
      DateFormat formatter; 
      Date date1, date2; 

      formatter = new SimpleDateFormat("mm-dd-yyyy");
      date1 = (Date)formatter.parse(args[0].replace( '/','-' )); 
      date2 = (Date)formatter.parse(args[1].replace( '/','-' )); 

      cDate1.setTime(date1);
      cDate2.setTime(date2);
    }
    catch (ParseException e)
    {
      System.out.println("Exception :"+e);
    }
    System.out.println("Number of days = " + numberOfDays(cDate1, cDate2));
  } // end main()
} // end Date2 

// Score: 10/10

