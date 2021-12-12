package FinalProjectFiles;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;

/**
 * Make an Estimates class to calculate all of the necessary values and 
 * print a table to a file for a customer.  
 * This class does most of the work for this project.
 *      Fields:
 *          A private PrintWriter object -- initialize in constructor.
 *          Private double fields for 
 *              wallArea, ceilingArea, wallPaint, ceilingPaint, and drywall.
 *      Methods:
 *          Constructor method.  
 *              Initialize the  PrintWriter object as FileOutputStream 
 *                  using the file name estimates.txt into the folder called files.
 *          A printAll method with an array and an arraylist as parameters. 
 *              Accumulate the totals in the fields as you’re iterating through the rows.   
 *              Call the tableHeader method.
 *              Calculate the individual room totals and print all table entries. 
 *                  The square footage of the wall area. 
 *                  The square footage of the ceiling area. 
 *                  The number of gallons of wall paint.
 *                  The number of gallons of ceiling paint.
 *                  The total number of sheets of drywall. Round this up for each room.
 *              Call the totals method.
 *              Be sure to close the  PrintWriter object before leaving the method.
 *          A tableHeader method. 
 *              This will print the centered table headers and a line under the headers.
 *          A totals method. 
 *              This prints a line to separate the table and 
 *              the totals in the relevant locations.
 * RELEVANT FORMULAS:
 *      Square footage of wall = 
 *          [2 x (length + width)  + 2 x (2.5 + 6)] x 8 // perimeter times height
 *          - number_of_closets x 2 x 5 x 6.5 // area of doors of closets in room and in closet
 *          - number_of_windows x 3 x 5 // area of windows
 *          - number_of_doors x 3 x 6.5 // area of doors
 *      Square footage of ceiling = (length x width) + number_of_closets x (2.5 x 6)
 *      Gallons of wall paint = Square footage of wall / 400 // don’t round until total
 *      Gallons of ceiling paint = Square footage of ceiling / 400 // don’t round until total
 *      Number of sheets of drywall = 
 *          roundup [2 x (length + width) / 4  
 *                  - 0.75 x (number_of_windows + number_of_doors) 
 *                  -  number_of_closets ]
 *          + number_of_closets x roundup [2 x (2.5 +6) / 4 - 1] 
 */
public class Estimates {
    private PrintWriter filePrinter;
    private double wallArea ;
    private double ceilingArea;
    private double wallPaint;
    private double ceilingPaint;
    private double drywall;

    // Constructor method
    public Estimates() throws FileNotFoundException {
        this.filePrinter = new PrintWriter(new FileOutputStream("files/estimates.txt"));
    }


    // printAll method
    public void printAll(double [][] dims , ArrayList<String> roomNames){
        tableHeader();

        for (int i =0; i < roomNames.size(); i++){
            double length , width, windows, doors, closets;
            double wallArea, ceilingArea,wallPaint,ceilingPaint,dryWall;

            // Extract the dimensions from the dims array
            length = dims[i][0];
            width  = dims[i][1];
            windows= dims[i][2];
            doors  = dims[i][3];
            closets= dims[i][4];

            //Calculate the relevant fields

            // Wall area
            wallArea = (2 * (length + width)  + 2 * (2.5 + 6)) * 8 -
                    (closets * 2 * 5 * 6.5) - (windows * 3 * 5) - (doors * 3 * 6.5);

            // Ceiling Area
            ceilingArea = (length * width) + closets * (2.5 * 6);

            // Wall paint
            wallPaint = wallArea / 400 ;

            // Ceiling paint
            ceilingPaint = ceilingArea /400;

            // dry wall
            dryWall = Math.round(( 2 * (length + width)/4 - 0.75 * (windows + doors) - closets))
                    + closets * Math.round((2 * (2.5 +6) / 4 - 1)) ;

            String roomName = roomNames.get(i);

            this.wallArea = this.wallArea + wallArea;
            this.ceilingArea = this.ceilingArea + ceilingArea;
            this.wallPaint = this.wallPaint + wallPaint;
            this.ceilingPaint = this.ceilingPaint + ceilingPaint;
            this.drywall = this.drywall + dryWall;

            filePrinter.printf("%-10s\t%-10.2f\t%-13.2f\t%-10s\t%-13s\t%-15s\n",
                    roomName,wallArea,ceilingArea,Math.round(wallPaint),Math.round(ceilingPaint),(int)dryWall);
        }
        this.wallPaint = (Math.round(this.wallPaint));
        this.ceilingPaint = Math.round(this.ceilingPaint);
        total();
        filePrinter.close();
    }


    private void tableHeader(){
        filePrinter.printf("%-10s\t%-10s\t%-13s\t%-10s\t%-13s\t%-15s\n",
                "Room Name","Wall Area","ceiling area","wall paint","ceiling paint","sheets of drywall");
        filePrinter.print("_____________________________________________________________________________________\n");

    }

    private void total(){
        filePrinter.printf("\n%-10s\t%-10.2f\t%-13.2f\t%-10s\t%-13s\t%-15s\n","Total",wallArea,ceilingArea,(int)wallPaint,(int)ceilingPaint,(int)drywall);

    }


}
