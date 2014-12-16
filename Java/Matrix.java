
// Matrix.java
// by Victor Hugo Erminpour
import java.util.*;

public class Matrix {

  // print a supplied matrix with name (String)
  public static void printMatrix(int[][] matrix, String matrixName) {

    int rows = matrix.length;
    int columns = matrix[0].length;

    System.out.println(matrixName + "[" + rows + "][" + columns + "] = ");

    for (int count1 = 0; count1 < rows; count1++) {
      System.out.print("[");

      for (int count2 = 0; count2 < columns; count2++) {
        System.out.print(" " + matrix[count1][count2] + ",");
      }
      System.out.println("]");
    }
  }

  // multiply two matrices
  public static int[][] matrixMultiply(int[][] matrix1, int[][] matrix2) {

    int matrix1Rows = matrix1.length;
    int matrix1Columns = matrix1[0].length;

    int matrix2Rows = matrix2.length;
    int matrix2Columns = matrix2[0].length;

    int[][] newMatrix = new int[matrix1Rows][matrix2Columns];

    // Multiply the two Matrices
    for (int count1 = 0; count1 < matrix1Rows; count1++)
      for (int count2 = 0; count2 < matrix2Columns; count2++)
        for (int count3 = 0; count3 < matrix1Columns; count3++)
        newMatrix[count1][count2] += matrix1[count1][count3] * matrix2[count3][count2];

    return newMatrix;
  }

  public static void main(String args[]) {

    System.out.println("What is the Matrix??");

    int matrixOne[][] = {
      { 9, 0, 9 },
      { 9, 10, 9 },
    };
    int matrixTwo[][] = {
      { 4, 2 },
      { 3, 0 },
      { 1, 2 },
    };
    // print out the first two matrices
    printMatrix(matrixOne, "matrixOne");
    printMatrix(matrixTwo, "matrixTwo");

    // calculate the results and print out the new Matrix
    int matrixResult[][] = matrixMultiply(matrixOne, matrixTwo);
    printMatrix(matrixResult, "matrixResult");

  } // end main()
} // end Matrix 

// Score: 10/10
