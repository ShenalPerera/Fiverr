package SampleFilesForIOwithFiles;
import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.ArrayList;

public class IOGradesArraylistWithArray {
   public static void main(String[] args) throws IOException {
      int n = 0;
      Scanner scnr = new Scanner(System.in);
      String[][] name = new String[20][2];
      int[][] scores = new int[20][3];
      ArrayList<String[]> names = new ArrayList<>();
      ArrayList<int[]> allScores = new ArrayList<>();
      // Get the name of the student information file 
      //     -- could just enter file name in the second line down so you don't have to enter it each time.
      System.out.println("Enter the name of your student information file:\n(should be files/StudentInfo.tsv");
      Scanner infoScanner = new Scanner(new FileInputStream(scnr.nextLine()));
      scnr.close();
      // Read the student information from the file
      while(infoScanner.hasNext()) {
         name[n][0] = infoScanner.next();
         name[n][1] = infoScanner.next();
         scores[n][0] = infoScanner.nextInt();
         scores[n][1] = infoScanner.nextInt();
         scores[n][2] = infoScanner.nextInt();
         names.add(name[n]);// an ArrayList containing the first and last name arrays
         allScores.add(scores[n]);// an ArrayList containing the 3 scores arrays
         n++;
      }
      // Close the open input stream
      infoScanner.close();
      // Open the report file for writing
      PrintWriter filePrinter = new PrintWriter(new FileOutputStream("files/report.txt"));
      double average = 0;
      String grade = null;
      // (n is the value left from the previous loop)
      for (int i = 0; i < allScores.size(); i++){
         // Compute the letter grade`
         average = (allScores.get(i)[0] + allScores.get(i)[1] + allScores.get(i)[2]) / 3.0;

         if (average >= 90) grade = "A";
         else if (average >= 80) grade = "B";
         else if (average >= 70) grade = "C";
         else if (average >= 60) grade = "D";
         else grade = "F";

         // Output the data and letter grade
         filePrinter.printf("%-10s%-10s%d\t%d\t%d\t%s\n",
         names.get(i)[0], names.get(i)[1], allScores.get(i)[0], allScores.get(i)[1], allScores.get(i)[2], grade);
         
      }
      // Compute the average for each exam
      double midterm1Average = 0.0;
      double midterm2Average = 0.0;
      double finalAverage = 0.0;
      for (int[] scr: allScores) {
         midterm1Average += scr[0] / allScores.size();
         midterm2Average += scr[1] / allScores.size();
         finalAverage += scr[2] / allScores.size();
      }
      // Output the averages
      filePrinter.printf("\nAverages: Midterm1 %.2f, Midterm2 %.2f, Final %.2f\n",
           midterm1Average, midterm2Average , finalAverage);
      // Close the open output stream
      filePrinter.close();
   }
}