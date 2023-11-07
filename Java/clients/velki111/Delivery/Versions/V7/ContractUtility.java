import java.util.Scanner;

public class ContractUtility {

    /**
     * This array represents the chart of the monthly rate of the package
     * Each row represent the Package while each row represents the Data bundle
     * <img src = "./img.png">
     */
    public static int [][] monthlyRates = {
                                            {500, 700, 900},
                                            {650, 850, 1050},
                                            {850, 1050, 1250,2000}
                                          };


    /**
     * Calculate the amount of the discount that contract has
     * <ul>
     *     <li>Business customer receive a 10% discount and must take at least a 12-month
     * contract.</li>
     *     <li>Charity customers receive a 30% discount for any length of contract</li>
     *     <li>Non-business customers taking a 12 or 18-month contract receive a 5% discount</li>
     *     <li>Non-business customers taking 24-month contract receive a 10% discount</li>
     * </ul>
     *
     */
    public static int getDiscount(ContractT type, int period){
        int discount = 0;

        switch (type){
            case NORMAL:
                // Handle the different periods of Normal type contracts
                if (period >= 12 && period <= 18){
                    discount = 5;
                }

                else if (period == 24) {
                    discount = 10;
                }

                break;
            case Business:
                // Sets the business contract if and only period is greater or equal to 12 months
                if (period >= 12){
                    discount = 10;
                }
                break;

            case Charity:
                discount = 30;
                break;

        }
        return discount;
    }


    /**
     * This function gets the monthly rate from the table (2d array) from the index by using models.PACKAGE  and models.DATA types values
     * Then apply the discount and apply the taxes for the international calls status
     * @param packageT  Package type of the contract
     * @param dataBundle   selected data bundle of the contract
     * @return  return the monthly total charge
     */
    public static int getMonthlyRate(PACKAGE packageT, DATA dataBundle){
        int charge;
        // Try to get the packages rate from the array. If the values give out of bound then pass a message to user
        try {
            charge = monthlyRates[packageT.ordinal()][dataBundle.ordinal()];
        }
        catch (ArrayIndexOutOfBoundsException e){
            System.out.println("Large Package only have the Unlimited feature");
            return 0;
        }
        return charge;
    }


    /**
     * This function wil get the details and according to the package and the data bundle it will get the
     * relevant monthly rate using {@link #getMonthlyRate(PACKAGE, DATA)} function. Then using {@link #getDiscount(ContractT, int)}
     * method get the relevant discount. Then updated the total charge per month (truncate the decimal parts) after apply the
     * discount. Then check whether it is allowed international calls and increase the price with the tax and return  if not return the total price
     * @param packageT  Type of the package
     * @param dataBundle    type of the data bundle
     * @param period    duration of the contract
     * @param isAllowIntCalls   A booelan to indicate whether it is allowed international call (true if allowed false otherwise)
     * @param type  Type of the contract (Business,Non-business or charity)
     * @return return the charge per month after all discounts and taxes are applied
     */
    public static int calculateMonthlyCharge(PACKAGE packageT, DATA dataBundle,int period, boolean isAllowIntCalls,ContractT type){
        // Get the monthly rate from the table
        int charge = getMonthlyRate(packageT,dataBundle);

        // Calculate the discount
        int discount = getDiscount(type,period);

        // update the discounted value
        charge = (int)(charge - (charge * (discount)/100.00));     // cast it to int

        // Check international calls are allowed
        if (isAllowIntCalls){
            return (int)(charge + (charge * 0.15));
        }

        return charge;
    }


    /**
     * Function to check the Data package and the data bundle are compatible. If there is entry for package and the data bundle
     * then return true. If not compatible return false
     * @param packageT Package type of the Contract
     * @param dataBundle Data bundle of the Contract
     * @return  return true if package and data have an entry false otherwise
     */
    public static boolean isPackageValid(PACKAGE packageT, DATA dataBundle){
        // Small and Medium packages can not have Unlimited data plan
        if (packageT == PACKAGE.Small || packageT == PACKAGE.Medium){
            return dataBundle != DATA.Unlimited;
        }
        return true;
    }


    /**
     * This function will get an object of the contract and print the details based on that object's attributes
     * @param contract Contract object
     */
    public static void displayContract(Contract contract){
        // Print the margins
        System.out.println("+---------------------------------------------+");
        System.out.printf("|%46s\n","|");

        // print the Customer name with margin
        System.out.printf("|%9s: %-25s%10s\n","Customer",contract.getClientName(),"|");

        // new line
        System.out.printf("|%46s\n","|");

        // print the package ,date,period ,data reference number
        System.out.printf("|%9s: %-13s\tDate: %-12s|\n","Ref",contract.getRefNumber(),contract.getDate());
        System.out.printf("|%9s: %-13s\tData: %-12s|\n","Package",getPackage(contract.getPackageSize()),getDataBundle(contract.getDataBundle()));
        System.out.printf("|%9s: %s %-10s\tType: %-12s|\n","Period",contract.getPeriod(),"Months",contract.getType());

        System.out.printf("|%46s\n","|");

        // Check the discount is applied or not and get the desired string
        String discount = contract.getDiscount() == 0.0 ? "None" : (int)(contract.getDiscount()) + "%";

        System.out.printf("|%9s: %-8s%11s: %-12s|\n","Discount", discount,"Intl.  calls", Utilities.booleanToYN(contract.isAllowIntCalls()));

        System.out.printf("|%46s\n","|");

        String discounted = contract.getDiscount() == 0.0 ? "          " : "Discounted";

        System.out.printf("|      %s Monthly Charge: \u00A3%-11.2f|\n",discounted,contract.getChargePerMonth()/100.0);

        System.out.printf("|%46s\n","|");
        System.out.println("+---------------------------------------------+");
    }


    /**
     * This an overloaded method of displayContract. In the {@link #displayContract(Contract)} method prints details using an object of the
     * contract class while this method explicit get the parameters from outside
     * @param clientName    A string represents name of the client
     * @param refNumber reference number of the client
     * @param date date of the contract is created
     * @param packageT Type of the package
     * @param dataBundle Type of the data bundle
     * @param period duration of the contract
     * @param type Type of the customer
     * @param _discount discount
     * @param chargePerMonth Total charge after the discounts and tazes are applied
     * @param isAllowIntCalls Status of the international calls
     */
    public static void displayContract(String clientName,String refNumber,String date,PACKAGE packageT, DATA dataBundle,int period,ContractT type,int _discount,int chargePerMonth,boolean isAllowIntCalls){
        // Print the margins
        System.out.println("+---------------------------------------------+");
        System.out.printf("|%46s\n","|");

        // print the Customer name with margin
        System.out.printf("|%9s: %-25s%10s\n","Customer",clientName,"|");

        // new line
        System.out.printf("|%46s\n","|");

        // print the package ,date,period ,data reference number
        System.out.printf("|%9s: %-13s\tDate: %-12s|\n","Ref",refNumber,date);
        System.out.printf("|%9s: %-13s\tData: %-12s|\n","Package",getPackage(packageT),getDataBundle(dataBundle));
        System.out.printf("|%9s: %s %-10s\tType: %-12s|\n","Period",period,"Months",type);

        System.out.printf("|%46s\n","|");

        // Check the discount is applied or not and get the desired string
        String discount = _discount == 0.0 ? "None" : _discount + "%";

        System.out.printf("|%9s: %-8s%11s: %-12s|\n","Discount", discount,"Intl.  calls", Utilities.booleanToYN(isAllowIntCalls));

        System.out.printf("|%46s\n","|");

        String discounted = _discount == 0.0 ? "          " : "Discounted";

        System.out.printf("|      %s Monthly Charge: \u00A3%-11.2f|\n",discounted,chargePerMonth/100.0);

        System.out.printf("|%46s\n","|");
        System.out.println("+---------------------------------------------+");
    }


    /**
     * This message will return a string that indicates the databudle
     * @param dataBundle models.DATA type that represents the data bundle
     * @return A string that indicate the data bundle
     */
    public static String getDataBundle(DATA dataBundle){
        String postfix = "";

        // Add a postfix for each data bundle that indicate the capacity of the data amount
        switch (dataBundle){
            case Low -> postfix = " (1GB)";
            case Medium -> postfix = " (4GB)";
            case High -> postfix = " (8GB)";
            case Unlimited -> postfix = "";
        }
        return dataBundle + postfix;
    }


    /**
     * This message will return a string that indicates the package
     * @param packageT models.PACKAGE type that represents the data package
     * @return A string that indicate the package
     */
    public static String getPackage(PACKAGE packageT){
        String postfix = "";

        // Add a postfix for each data bundle that indicate the capacity of the data amount
        switch (packageT){
            case Small -> postfix = " (300)";
            case Medium -> postfix = " (600)";
            case Large -> postfix = " (1200)";
        }
        return packageT + postfix;
    }


    /**
     * This method will get a number between 1 - 3 (inclusive both end) and return the relevant package for that number
     * <ui>
     *     <li>1 = Small</li>
     *     <li>2 = Medium</li>
     *     <li>3 = Large</li>
     * </ui>
     * @param number An integer between inclusive 1 to 3
     * @return A package data type that assign to the number
     */
    public static PACKAGE intToPackageT(int number){
        return PACKAGE.values()[number -1];     // Use that index (number -1) to get the value of index in PACKAGE enum
    }


    /**
     * This method will get a number between 1 - 4 (inclusive both end) and return the relevant DATA for that number
     * <ui>
     *     <li>1 = Low</li>
     *     <li>2 = Medium</li>
     *     <li>3 = High</li>
     *     <li>4 = Unlimited</li>
     * </ui>
     * @param number An integer between inclusive 1 to 3
     * @return A Data type  that assign to the number
     */
    public static DATA intToDataT(int number){
        return DATA.values()[number-1];
    }


    /**
     * This method will get the estimated data in megabytes and select the most suitable data package.
     * In here If the estimated data amount is exceed more than 1 GB with standard data bundle(1GB, 4GB, 8GB, Unlimited)
     * then this method select next upper bound data bundle. And the data amount exceed more than 8Gb package then set it to Unlimited
     * ex:-
     *      <ui>
     *          <li>More than 11 999 MB = Unlimited</li>
     *          <li>5000 MB <= data <= 11 999MB -> HIGH</=></li>
     *          <li>2000 MB <= data <= 4999 MB -> MEDIUM</=></li>
     *          <li>less than 1999MB = LOW</li>
     *
     *      </ui>
     *
     * @param data estimated data amount
     * @return  return the relevant data bundle that matches with estimated amount of data
     */
    public static DATA selectDataBundle(int data){
        // Set unlimited if it exceeds more than 4 GB of High bundle
        if (data - 8000 >= 4000){
            return DATA.Unlimited;
        }

        // return High if it exceeds more than 1 GB of Medium data bundle
        else if (data - 4000 >= 1000 ){
            return DATA.High;
        }

        // return Medium if it exceeds more than 1 GB of Low data bundle
        else if (data - 1000 >= 1000 ){
            return DATA.Medium;
        }

        // Lower than 1999 MB will give Low bundle
        else{
            return DATA.Low;
        }

    }


    /**
     * This method will give relevant Package. If the data bundle is already selected as unlimited Package automatically set to
     * the large. Then each margin if the minutes exceeds more than 200 minutes selected upper next margin.
     * @param mins Estimated minutes
     * @param data Estimated data amount
     * @return  relevant selected package
     */
    public static PACKAGE selectPackage(int mins, int data){
        if (selectDataBundle(data) == DATA.Unlimited){
            return PACKAGE.Large;
        }
        else if (mins - 600 > 200){
            return PACKAGE.Large;
        }
        else if (mins - 300 > 200){
            return PACKAGE.Medium;
        }
        else{
            return PACKAGE.Small;
        }


    }


    /**
     * This method will get and validate the reference number is in given length using {@link Utilities#validFixedLenNextLine(String, int)}
     * Then it checks the middle three characters are numbers , first two leading characters are letters and lst character is B or N
     * If not until user enter a valid reference number it will prompt to the user
     * @param prompt Message that should be displayed to the user
     * @return  return the validated reference number as a String
     */
    public static String validateRefNumber(String prompt){

        do {
            String refNumber =  Utilities.validFixedLenNextLine(prompt,6);
            String numbers = Utilities.truncateString(refNumber,2,3);
            String first2Letters = Utilities.truncateString(refNumber,0,2);

            try {
                // TRy to convert string numbers to int. If the numbers does not contain integers it will give error
                Integer.parseInt(numbers);
                // Check if the first2Letters are alphabetic and last character is B or N
                if (first2Letters.matches("[a-zA-Z]+") && (refNumber.charAt(5) == 'B' || refNumber.charAt(5) == 'N')){
                    return refNumber;
                }
                // Print error message
                System.out.println("Reference number must have 2 leading characters and B or N at the last");

            }
            catch (NumberFormatException e){
                System.out.println("Reference number you entered is invalid!");
            }
        }while (true);
    }


    /**
     * This function get A string that should be prompted and type of the contract. Then it gets the user input and validate the range
     * using {@link Utilities#validNextInt(String, int, int)} function. Then it is looping until user enters a valid period.
     * It initially checks given period is 1-month and the type of the user if Non-business. If that is the case return the period. If Business
     * customer select a 1-month contract prompt user to error message. Then check given period is in valid 1,12,18 or 24. If not print a erro
     * message.
     * @param prompt    A string that contains the message that need to show to the user
     * @param type      contract type
     * @return  validated period
     */
    public static int validatePeriod(String prompt,ContractT type){
        // Keep asking until enter a valid period
        do {
            int period = Utilities.validNextInt(prompt,1,24);
            // Only the non-business and charity customers can take 1-month contract
            if (period == 1 && type != ContractT.Business){
                return period;
            }
            // Prompt the user an error message when Business customer try to get 1-month contract
            else if (period == 1){
                System.out.println("Business customers must have at least 12 months contract");
            }

            // check given period is in the following list
            else if (period == 12 || period == 18 || period == 24){
                return period;
            }
            // Print the error message when subscription is not in the list
            else{
                System.out.println("Please select available options (1-month, 12-months, 18-months, 24-months");
            }
        }while (true);
    }


    /**
     * This method return the type of the user by checking the reference number. Last character of the refNumber
     * is B for Business and N for normal customers.
     * @param refNumber A string that represents the reference number
     * @return return the relevant type of the user
     */
    public static ContractT getTypeByRefNumber(String refNumber){
        char lastLetter = refNumber.charAt(5);
        return switch (lastLetter) {
            case 'B' -> ContractT.Business;
            case 'N' -> ContractT.NORMAL;
            default -> ContractT.Charity;
        };
    }


    /**
     * This method will get the contact as an argument. According to that details it will create a string line using {}
     * That string will append to the "contracts.txt" file
     * @param contract The object that contains the details
     */
    public static void saveContract(Contract contract){
        String strToAppend = contract.toString();
        Utilities.appendStringToFile("contracts.txt",strToAppend);
    }


    public static void getSummary(int option){
        // In case of option is invalid this is the default file path
        String filename = null;

        // Check the user option and update the relevant file name
        if(option == 1){
            filename = "contracts.txt";
        }
        else if(option == 2){
            filename = "archive.txt";
        }

        Scanner myReader = Utilities.validateReadFile(filename);

        if (myReader != null){
            // Total number of contracts
            int total = 0;

            // Total number of contracts with high or unlimited data bundle
            int highOrUnlimited = 0;

            int totalChargePerMonth = 0;

            // Counts per month hold in the array with size 12. Each index represents the month. Jan = 0, Feb = 1, ... Dec = 11
            int [] contractsPerMonth  = new int[12];

            // Temp variable to hold the moth
            String tempMonth;

            // Read line until the EOF found
            while (myReader.hasNextLine()) {
                // Get the line to a string as split tokens
                String[] tokens =Utilities.splitString( myReader.nextLine(),"\t");

                tempMonth = Utilities.truncateString(tokens[0],3,3);

                System.out.println(tempMonth);
            }
        }
    }
}
