package SampleFilesForIOwithFiles;
import java.util.Scanner;
import java.io.FileInputStream;
import java.io.IOException;

public class FileReadNums {
   public static void main (String[] args) throws IOException {
      FileInputStream fileByteStream = null; // File input stream
      Scanner inFS = null;                   // Scanner object
      int fileNum1;                          // Data value from file
      int fileNum2;                          // Data value from file

      // Try to open file
      System.out.println("Opening file numFile.txt.");
      // Put your file in the src folder for this project
      // The file can be elsewhere, but it's easier to work with here.
      fileByteStream = new FileInputStream("files/numFile.txt"); 
      inFS = new Scanner(fileByteStream);
      
      // File is open and valid if we got this far 
      // (otherwise exception thrown)
      // numFile.txt should contain two integers, else problems
      System.out.println("Reading two integers.");
      fileNum1 = inFS.nextInt();
      fileNum2 = inFS.nextInt();

      // Output values read from file
      System.out.println("num1: " + fileNum1);
      System.out.println("num2: " + fileNum2);
      System.out.println("num1+num2: " + (fileNum1 + fileNum2));

      // Done with file, so try to close it
      System.out.println("Closing file numFile.txt.");
      fileByteStream.close(); // close() may throw IOException if fails
      inFS.close();
   }
}