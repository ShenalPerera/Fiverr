package FinalProjectFiles;

import java.io.FileNotFoundException;
import java.util.Scanner;

/**
* In a file called WallEstimate.java, 
*   ask the user for the name of the information file for the house.  
*   The user should enter files/HouseInfo.tsv to use the file.  
*   A copy of this file is already stored in the files folder for this project. 
*   Make a RoomInfo object with a parameter for the file name.  
*   Print a message to the user telling the location and name of the output file.  
*   For example, 
*     Your output file is estimate.txt and can be found in the files folder.
 */
public class WallEstimate {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(System.in);
        String fileName;

        System.out.print("Enter the name of your house information file:\n(should be files/HouseInfo.tsv) : ");
        // Get the file name from the user
        fileName = scanner.nextLine();

        // Create the roomInfo object with the given filename
        RoomInfo roomInfo = new RoomInfo(fileName);

        System.out.println("Your output file is estimate.txt and can be found in the files folder");
    }
}
