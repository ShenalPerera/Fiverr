package SampleFilesForIOwithFiles;
import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.IOException;

public class IOGrades {
   public static void main(String[] args) throws IOException {
      Scanner scnr = new Scanner(System.in);
      int n;
      double average;
      String grade = null;

      // For input of filename
      String infoFileName = null;
      // For input of StudentInfo
      FileInputStream infoStream = null;
      Scanner infoScanner = null;
      // For output of report
      String reportFileName = "files/report.txt";
      FileOutputStream reportStream = null;
      PrintWriter reportWriter = null;

      // Arrays for score data; assuming no more than 20
      String[] firstNames = new String[20];
      String[] lastNames = new String[20];
      int[] midterm1Scores = new int[20];
      int[] midterm2Scores = new int[20];
      int[] finalScores = new int[20];

      // For computing averages at end of program
      double midterm1Sum;
      double midterm2Sum;
      double finalSum;

      // Get the name of the student information file
      System.out.println("Enter the name of your student information file:\n(should be files/StudentInfo.tsv");
      infoFileName = scnr.nextLine();

      // Open the student information file
      infoStream = new FileInputStream(infoFileName);
      infoScanner = new Scanner(infoStream);

      // Read the student information
      n = 0;
      while(infoScanner.hasNext()) {
         lastNames[n] = infoScanner.next();
         firstNames[n] = infoScanner.next();
         midterm1Scores[n] = infoScanner.nextInt();
         midterm2Scores[n] = infoScanner.nextInt();
         finalScores[n] = infoScanner.nextInt();
         ++n;
      }

      // Close the student information file
      infoStream.close();

      // Open the report file for writing
      reportStream = new FileOutputStream(reportFileName);
      reportWriter = new PrintWriter(reportStream);

      // Output the data and letter grade for each student
      // (n is the value left from the previous loop)
      for (int i = 0; i < n; ++i) {

         // Compute the letter grade
         average = (midterm1Scores[i]
                    + midterm2Scores[i]
                    + finalScores[i]) / 3.0;
         if (average >= 90) {
            grade = "A";
         }
         else if (average >= 80) {
            grade = "B";
         }
         else if (average >= 70) {
            grade = "C";
         }
         else if (average >= 60) {
            grade = "D";
         }
         else {
            grade = "F";
         }

         // Output the data and letter grade
         reportWriter.printf("%-10s%-10s%d\t%d\t%d\t%s\n",
                             lastNames[i], firstNames[i],
                             midterm1Scores[i], midterm2Scores[i],
                             finalScores[i], grade);
      }

      // Compute the average for each exam
      midterm1Sum = 0.0;
      midterm2Sum = 0.0;
      finalSum = 0.0;
      for (int i = 0; i < n; ++i) {
         midterm1Sum += midterm1Scores[i];
         midterm2Sum += midterm2Scores[i];
         finalSum += finalScores[i];
      }

      reportWriter.printf("\nAverages: Midterm1 %.2f, Midterm2 %.2f, Final %.2f\n",
           midterm1Sum / n, midterm2Sum / n, finalSum / n);

      // Close the open files and scanners
      reportWriter.flush();
      reportStream.close();
      scnr.close();
      infoScanner.close();
   }
}