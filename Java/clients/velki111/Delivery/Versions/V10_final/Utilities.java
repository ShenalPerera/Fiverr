import java.io.*;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Scanner;

public class Utilities {

    /**
     * This method prompt the message that given as parameter and get the user input. Then validate that input until user enters
     * valid input.
     * @param prompt    A string that contains the message to user
     * @return Int that represents the user option
     */
    public static int validNextInt(String prompt,int min, int max) {
        Scanner input = new Scanner(System.in);                 // Initialize the scanner
        // This will loop until user enter a number
        do {
            try {
                // This will keep looping until user enter valid range number
                do {
                    // Prompt the message to the user
                    System.out.print(prompt);
                    int number = Integer.parseInt(input.next());

                    if (validRange(number,min,max)){
                        return number;
                    }
                    System.out.println("Number is not in the range!\n");
                }while (true);

            }
            // Catch if the user enter non-integer value
            catch (NumberFormatException e) {
                System.out.println("\nEnter a number please.\n");
            }
        }  while (true);
    }


    /**
     * This method returns Yes if the booleanToConvert value is true. Returns No otherwise.
     *
     * @param booleanToConvert The boolean value that will be used to determine Y/N
     * @return Returns Yes if the booleanToConvert value is true. Returns No otherwise.
     */
    public static String booleanToYN(boolean booleanToConvert){
        return booleanToConvert ? "Yes" : "No";
    }


    /**
     * This method returns true if the charToConvert value is Y or y. Returns false in all other cases.
     *
     * @param charToConvert The char value that will be used to determine true/false.
     * @return Returns true if the charToConvert value is Y or y. Returns false otherwise.
     */
    public static boolean YNtoBoolean(char charToConvert){
        return ((charToConvert == 'y') || (charToConvert == 'Y'));
    }


    /**
     * This method takes in a string, passed as a parameter and valdiates whether it is less than or equal to
     * a specific length or not.
     *
     * @param strToCheck The string that will be checked to see if it is a specific length
     * @param maxLength The length that the string will be validated against
     * @return True if the string is less than or equal the max length and false otherwise.
     */
    public static boolean validateStringLength(String strToCheck, int maxLength){
        return strToCheck.length() <= maxLength;
    }


    /**
     * This method takes in a string, passed as a parameter and valdiates whether it is  equal to
     * a specific length or not.
     *
     * @param strToCheck The string that will be checked to see if it is a specific length
     * @param fixedLength The length that the string will be validated against
     * @return True if the string is  equal the fixed length and false otherwise.
     */
    public static boolean validateStringFixedLength(String strToCheck, int fixedLength){
        return strToCheck.length() == fixedLength;
    }

    /**
     * This method returns true if the numberToCheck is between min and max (both inclusive)
     *
     * @param numberToCheck The number whose range is being checked.
     * @param min The minimum range number to check against (inclusive)
     * @param max The maximum range number to check against (inclusive)
     * @return Returns true if the numberToCheck is between min and max (both inclusive), false otherwise.
     */
    public static boolean validRange(int numberToCheck, int min, int max) {
        return ((numberToCheck >= min) && (numberToCheck <= max));
    }



    /**
     * This method promt a message and get the user input (read the line)
     * And check if the string is in valid range {@link #validateStringLength(String, int) }
     * @param prompt A string contains the message that should be prompted
     * @return  String value of the user input
     */
    public static String validNextLine(String prompt,int validLength) {
        Scanner input = new Scanner(System.in); // initialize the Scanner
        // Wait until user enter valid string
        do {
            // Print the message
            System.out.print(prompt);

            // Get next line
            String nextLine = input.nextLine();

            //Check that value has not exceeded the limit
            if (validateStringLength(nextLine,validLength)){
                return nextLine;
            }
             //Else show a message to user
            else{
                System.out.printf("\nYour input exceed the limit of %s characters. Try again!\n",validLength);
            }


        }while (true);


    }


    /**
     * This method promt a message and get the user input (read the line)
     * And check if the string is in valid range {@link #validateStringFixedLength(String, int)}  }
     * @param prompt A string contains the message that should be prompted
     * @return  String value of the user input
     */
    public static String validFixedLenNextLine(String prompt, int fixedLength){
        Scanner input = new Scanner(System.in); // initialize the Scanner
        // Wait until user enter valid string
        do {
            // Print the message
            System.out.print(prompt);

            // Get next line
            String nextLine = input.nextLine();

            //Check that value has not exceeded the limit
            if (validateStringFixedLength(nextLine,fixedLength)){
                return nextLine;
            }
            //Else show a message to user
            else{
                System.out.printf("\nYour input Should have fixed limit of %s characters. Try again!\n",fixedLength);
            }


        }while (true);
    }


    /**
     *Method to check whether character is in the given array
     * @param c character to be checked
     * @param validCharacters valid characters
     * @return tru if found match otherwise false
     */
    public static boolean characterIsInArray(char c, char [] validCharacters){
        for (char validCharacter : validCharacters) {
            if (c == validCharacter) {
                return true;
            }
        }
        return false;
    }

    /**
     * This method will give a message to the user and get next character from the user
     * {@link #characterIsInArray(char, char[])}
     * @param prompt    Message that need to be showed to the user
     * @param validCharacters an array that represents the eligible characters
     * @return  Valid character that user entered
     */
    public static char validNextChar(String prompt,char [] validCharacters) {
        Scanner input = new Scanner(System.in);
        char c;
        do {
            System.out.print(prompt);
            c = Character.toUpperCase(input.next().charAt(0));
            if (characterIsInArray(c,validCharacters)){
                return c;
            }
            // Create the message that consist with the all valid characters
            System.out.print("Please enter ");

            // Print each valid characters that use eligible to enter
            for (char validCharacter : validCharacters) {
                System.out.printf("%c/", validCharacter);
            }
            System.out.println();
        }while (true);

    }


    /**
     *  This method returns a string that was passed as a parameter, truncated to a specific length(start pont to end point ), also
     *  passed as a parameter.  If the original String is less than the passed length(End -start), then the original string
     *  is just returned.
     *
     * @param stringToTruncate  The string that will be truncated to a specific length
     * @param start The start position to which to truncate the string to
     * @param length Upton what extend stronghold be truncated
     * @return The string truncated to a specific length
     */
    public static String truncateString(String stringToTruncate, int start,int length){
        if (stringToTruncate.length() <= length || start < 0  || start + length >= stringToTruncate.length() || length < 0) {
            return stringToTruncate;
        }
        else{
            return stringToTruncate.substring(start, start+length);
        }
    }

    /**
     * This function generate the current triggered time and convert it to the string
     * @return A string that represents the date
     */
    public static String getDate(){
        Calendar cal = Calendar.getInstance();
        SimpleDateFormat sdf = new SimpleDateFormat("dd-MMM-yyyy");
        return sdf.format(cal.getTime());
    }

    /**
     * This method will open the given (filename) file (if exits) as append mode and add the strToAppend to the file
     * And close the file stream
     * @param filename  Name of the file
     * @param strToAppend   String that should append
     */
    public static void appendStringToFile(String filename, String strToAppend){
        // Try to open a file
        try {

            // OPen the file in append mode
            BufferedWriter out = new BufferedWriter(
                    new FileWriter(filename, true));

            // Writing on output stream
            out.write(strToAppend);

            // Closing the connection
            out.close();
        }

        // Catch block to handle the exceptions
        catch (IOException e) {

            // Display message when exception occurs
            System.out.println("exception occurred" + e);
        }
    }


    /**
     * This method is used to get a scanner object which is created using file object for read. If the file is found then create the
     * File object and return that object by wrapping Scanner object. If not found then notfity the user and reun null to
     * indicate that file is not found
     * @param filename  path/ name of the file
     * @return  return the scanner object if file is not found return null
     */
    public static Scanner validateReadFile(String filename){
        // Try to open the file as scanner object
        try {
            // Create File object
            File myObj = new File(filename);

            // Return the file object if file exits
            return new Scanner(myObj);
        }
        // If file is not found notify the user
        catch (FileNotFoundException e) {
            System.out.println("File not found ! ");
        }
        // Return null if file is not found
        return null;
    }

    /**
     * This method wil split the string with given delimiter (as regex string) to String array
     * @param strToSplit    String that to be splitted
     * @param delimiter A string represents the regex of the delimiter
     * @return return a Array of string
     */
    public static String[] splitString(String strToSplit, String delimiter){
        return strToSplit.split(delimiter);
    }


}
