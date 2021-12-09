package SampleFilesForIOwithFiles;
import java.util.Scanner;
public class ScannerWithStringInput {
   public static void main(String[] args) {
      String userInfo = "Amy Smith 19";
      Scanner inSS = new Scanner(userInfo); // inSS = input String Stream

      // Parse name and age values from string
      String firstName = inSS.next();
      String lastName = inSS.next();
      int userAge = inSS.nextInt();

      // Output parsed values
      System.out.println("First name: " + firstName);
      System.out.println("Last name: " + lastName);
      System.out.println("Age: " + userAge);
      inSS.close();
   }
}
