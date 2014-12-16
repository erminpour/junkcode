
// Date1.java
// by Victor Hugo Erminpour
import java.util.*;

public class Date1 {

  // Check to see if supplied year is a leap year
  public static boolean isLeapYear(int year) {
    // Divisible by 4?
    if (year % 4 == 0) {
      // Divisible by 4 but not 100?  Leap Year.
      if (year % 100 != 0) {
        return true;
      }
      // Divisible by 4 and 100 and 400? Leap Year.
      else if (year % 400 == 0) {
        return true;
      }
      // Divisible by 4 and 100 but not 400? Not a Leap Year.
      else {
        return false;
      }
    }
    // Not divisible by 4. Not a Leap Year.
    else {
        return false;
    }
  }

  // Return the number of days in a month
  public static int getDaysInMonth(int month, int year) {
        int days = 0;

        if(month == 1  ||  // January
           month == 3  ||  // March
           month == 5  ||  // May
           month == 7  ||  // July
           month == 8  ||  // August
           month == 10 ||  // October
           month == 12)    // December
            days = 31;
        else if(month == 4 ||  // April
                month == 6 ||  // June
                month == 9 ||  // September
                month == 11)   // November
            days = 30;
        else if(month == 2) {  // February
            if(isLeapYear(year))
                days = 29;
            else
                days = 28;
        }

        return days;
  }

  // Return number of days till end of month
  public static int getDaysUntilEndOfMonth(int month, int day, int year)
  {
    int numDaysInMonth;
    numDaysInMonth = getDaysInMonth(month, year);

    if(day == 1)
      return numDaysInMonth;

    return (numDaysInMonth - day);
  }

  // Return number of days since begining of month
  public static int getDaysSinceBeginingOfMonth(int month, int day, int year)
  {
    int numDaysInMonth;
    numDaysInMonth = getDaysInMonth(month, year);

    if(day == numDaysInMonth)
      return 0;

    return (numDaysInMonth + day);
  }


  // Return number of days till end of year
  public static int getDaysUntilEndOfYear(int month, int day, int year)
  {
    int numDaysInYear = 0;
    while(month <= 12) {
      numDaysInYear += getDaysUntilEndOfMonth(month, day, year);
      month ++;
      day = 1;
    }

    return numDaysInYear;
  }


  // Calculate number of days between two dates
  public static long numberOfDays(String date1, String date2) {
    String [] Date1 = date1.split("/");
    String [] Date2 = date2.split("/");

    long numberOfDays = 0;
    int Day1 = Integer.parseInt(Date1[1]);
    int Day2 = Integer.parseInt(Date2[1]);
    int Month1 = Integer.parseInt(Date1[0]);
    int Month2 = Integer.parseInt(Date2[0]);
    int Year1 = Integer.parseInt(Date1[2]);
    int Year2 = Integer.parseInt(Date2[2]);

    // Check to see that Date1 is before Date2
    if((Year1 > Year2) || ((Month1 > Month2) && (Year1 == Year2)) || ((Day1 > Day2) && (Month1 == Month2)) ) {
      System.err.println("Error: " + date1 + " is later than " + date2);
      System.exit(1); 
    }

    while( Year1 < Year2) {
            numberOfDays += getDaysUntilEndOfYear(Month1, Day1, Year1);
            Year1++;
            Month1 = 1;
            Day1 = 1;
        }

    while(Month1 < Month2) {
        numberOfDays += getDaysUntilEndOfMonth(Month1, Day1, Year1);
        Month1++;
        Day1 = 1;
    }

	// NR: What about the days?!
//    if(Day1 < Day2)
  //      numberOfDays += Day2;

    return numberOfDays;
  }  // end numberOfDays

  public static void main(String args[]) {
    // Check commandline args
    if(args.length != 2) {
      System.err.println("ERROR: Invalid argument count!");
      System.err.println("Usage: Date1 <MM/DD/YYYY> <MM/DD/YYYY>");
      System.exit(1);
    }
    System.out.println("Number of Days = " + numberOfDays(args[0], args[1]));
  } // end main()
} // end Date1 

// Score: 8/10
