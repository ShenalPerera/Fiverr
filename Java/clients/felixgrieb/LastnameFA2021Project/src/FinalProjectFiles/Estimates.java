package FinalProjectFiles;
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
    
}
