
/* 
*  Victor Hugo Erminpour
*  Student.java
*/

import java.util.*;

public class Student implements java.lang.Comparable {

  private String firstName;
  private String lastName;
  private int studentID;
  private float gpa;

  // Constructor(String firstName, String lastName, int studentID, float gpa)
  Student(String firstName, String lastName, int studentID, float gpa) {
    this.firstName = firstName;
    this.lastName = lastName;
    this.studentID = studentID;
    this.gpa = gpa;
  }

  // toString()
  public String toString() {
    return (this.firstName + "\t" + this.lastName + "\t" + this.studentID + 
            "\t" + this.gpa);
  }

  // getFirstName()
  public String getFirstName() {
    return this.firstName;
  }
  // setFirstName()
  public void setFirstName(String str) {
    this.firstName = str;
  }

  // getLastName()
  public String getLastName() {
    return this.lastName;
  }
  // setLastName()
  public void setLastName(String str) {
    this.lastName = str;
  }

  // getStudentID()
  public int getStudentID() {
    return this.studentID;
  }
  // setStudentID()
  public void setStudentID(int studentID) {
    this.studentID = studentID;
  }

  // getGPA()
  public float getGPA() {
    return this.gpa;
  }
  // setGPA()
  public void setGPA(float gpa) {
    this.gpa = gpa;
  }

  // compareTo() (Java Comparable)
  public int compareTo(Object object) {
    // cast Student class to generic Object
    Student studentOne = (Student) object;

    // sort by GPA
    if(studentOne.gpa > this.gpa)
      return 1;
    else
      return 0;
  }
}

