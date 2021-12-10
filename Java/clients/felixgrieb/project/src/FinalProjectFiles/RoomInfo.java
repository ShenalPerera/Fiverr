package FinalProjectFiles;

import java.awt.*;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *  Make a RoomInfo class to read the information from the user-provided tsv file.
 *  It should have 
 *      fields:
 *          A private arraylist to store the names of the rooms.
 *          A private 30 by 5 array named dims to store the information for the rooms.   
 *          A private string for the input file name.
 *          A private object for the Dimensions class.
 *      Methods:
 *          A constructor with a string parameter.
 *              Initialize the fields.
 *              Call the readInfo method to fill in the arraylists.
 *              Call the printAll method from the Dimensions class
 *                   with the names arraylist and dims array as arguments.      
 *          A readInfo method with no parameter
 *              Make a FileInputStream Scanner object using the file name field.  
 *                  (Be sure to close this before leaving the method.)
 *              Read each entry of the file.  The first entry will be stored in the room names
 *                  arraylist.  The next few entries will be stored into the dims array.
 *                  (NOTE:  the first six values will not be stored.  
 *                          The 7th value is the first room name.)
 *                  Each room array will store the following on a separate row for each 
 *                  room listed in the tsv file: 
 *                          The length.
 *                          The width.
 *                          The number of windows.
 *                          The number of doors.
 *                          The number of closets.
 */
public class RoomInfo {
    private ArrayList<String> roomNames;
    private double [][] dims ;
    private String fileName;
    private Estimates dimensions;


    public RoomInfo(String fileName) throws FileNotFoundException {
        this.fileName  = fileName;
        this. dims = new double[30][5];
        this.roomNames = new ArrayList<>();
        this.dimensions = new Estimates();
        readInfo();
        dimensions.printAll(dims,roomNames);
    }

    private void readInfo() throws FileNotFoundException {
        // Create file input Stream with the fileName
        FileInputStream fileByStream = new FileInputStream(this.fileName);

        // Scanner to get the file from the defined fileInputStream
        Scanner inFS = new Scanner(fileByStream);
        // Skip the first line
        inFS.nextLine();

        int n = 0;
        // Read the House Information
        while (inFS.hasNext()){
            this.roomNames.add(inFS.next());
            dims[n][0] = inFS.nextDouble();
            dims[n][1] = inFS.nextDouble();
            dims[n][2] = inFS.nextInt();
            dims[n][3] = inFS.nextInt();
            dims[n][4] = inFS.nextInt();
            n++;
        }



    }

}
