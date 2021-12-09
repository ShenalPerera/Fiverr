package SampleFilesForIOwithFiles;
import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.IOException;

public class IOGradesMultDimArray {
   public static void main(String[] args) throws IOException {
      Scanner scnr = new Scanner(System.in);
      int n;
      String[][] name = new String[20][2];
      int[][] scores = new int[20][3];
      // Get the name of the student information file 
      //     -- could just enter file name in the second line down so you don't have to enter it each time.
      System.out.println("Enter the name of your student information file:\n(should be files/StudentInfo.tsv");
      Scanner infoScanner = new Scanner(new FileInputStream(scnr.nextLine()));
      scnr.close();
      // Read the student information from the file
      n = 0;
      while(infoScanner.hasNext()) {
         name[n][0] = infoScanner.next();
         name[n][1] = infoScanner.next();
         scores[n][0] = infoScanner.nextInt();
         scores[n][1] = infoScanner.nextInt();
         scores[n][2] = infoScanner.nextInt();
         ++n;
      }
      // Close the open input stream
      infoScanner.close();
      // Open the report file for writing
      PrintWriter filePrinter = new PrintWriter(new FileOutputStream("files/report.txt"));
      double average = 0;
      String grade = null;
      // (n is the value left from the previous loop)
      for (int i = 0; i < n; ++i) {

         // Compute the letter grade
         average = (scores[i][0]
                    + scores[i][1]
                    + scores[i][2]) / 3.0;
         if (average >= 90) grade = "A";
         else if (average >= 80) grade = "B";
         else if (average >= 70) grade = "C";
         else if (average >= 60) grade = "D";
         else grade = "F";

         // Output the data and letter grade
         filePrinter.printf("%-10s%-10s%d\t%d\t%d\t%s\n",
            name[i][0], name[i][1], scores[i][0], scores[i][1], scores[i][2], grade);
      }
      // Compute the average for each exam
      double midterm1Average = 0.0;
      double midterm2Average = 0.0;
      double finalAverage = 0.0;
      for (int i = 0; i < n; i++) {
         midterm1Average += scores[i][0] / n;
         midterm2Average += scores[i][1] / n;
         finalAverage += scores[i][2] / n;
      }
      // Output the averages
      filePrinter.printf("\nAverages: Midterm1 %.2f, Midterm2 %.2f, Final %.2f\n",
           midterm1Average, midterm2Average , finalAverage);
      // Close the open output stream
      filePrinter.close();
   }
}