public class Driver {
    /**
     * This method show the main menu to the user with help of the validNextInt function of the
     * {@link Utilities#validNextInt(String, int, int)}
     * @return return a validate integer from the user
     */
    public static int mainMenu(){
        String mainMenu = """
                1.\tCreate new Contract
                2.\tDisplay Summary of Contracts
                3.\tDisplay Summary of Contracts for Selected Month
                4.\tFind and Display Contract
                0.\tExit
                """ + "\nEnter your choice : ";
        return Utilities.validNextInt(mainMenu,0,4);
    }

    /**
     * This method will take (from the users)client name, package, data bundle, reference, period
     * and include international calls. Alternatively, the estimated minutes and data
     * (megabytes) can be entered and the program automatically selects the appropriate
     *
     * All inputs are validated using {@link Utilities} and {@link ContractUtility} classes' methods
     *<p>
     *     Client name is get and validated using {@link Utilities#validNextLine(String, int)} function. Then user is asked to Choose the mode
     *      of selecting the data bundle and package type. If user select automatic mode user is asked to enter the estimated data amount and package amount
     *      .These amounts are validate using {@link Utilities#validNextInt(String, int, int)}. Then selecting the package and data bundle are done
     *      using {@link ContractUtility#intToPackageT(int)} and {@link ContractUtility#intToDataT(int)} function respectively
     *</p>
     *<p>
     *    After the package and the data bundle is selected again check whether these duo is compatible. i.e. this contract is in the list.
     *    To do that {@link ContractUtility#isContractValid(PACKAGE, DATA)} function is used
     *</p>
     *
     * <p>
     *     To validate the the reference number ,period , to get the discount , get the date and to calculate the charge per month
     *     Below methods are used
     *     <ul>
     *         <li>reference number - {@link ContractUtility#validateRefNumber(String)}</li>
     *         <li>period           - {@link ContractUtility#validatePeriod(String, ContractT)}</li>
     *         <li>discount         - {@link ContractUtility#getDiscount(ContractT, int)}</li>
     *         <li>date             - {@link Utilities#getDate()}</li>
     *         <li>charge per month - {@link ContractUtility#calculateMonthlyCharge(PACKAGE, DATA, int, boolean, ContractT)}</li>
     *     </ul>
     *
     * </p>
     *
     * <p>
     *     Then the new object is created from the data. Also using the {@link ContractUtility#displayContract(String, String, String, PACKAGE, DATA, int, ContractT, int, int, boolean)}
     *     function display the currently created contract to the prompt
     * </p>
     *
     * <p>
     *     Then the data is written to the contracts.txt file using {@link ContractUtility#saveContract(Contract)} method.
     * </p>
     *<p>
     *     Alternatively for the displaying purpose {@link ContractUtility#displayContract(Contract)} function also can be used if the object is already
     *     created.
     *     {@code ContractUtility.displayContract(contract)}
     *</p>
     */
    public static void createContract(){
        // Get and validate the entered name (Should be limited for 25 characters)
        String clientName = Utilities.validNextLine("Enter your name : ",25);

        // Ask from user whether he wants to automate the package and data bundle selection
        char option = Utilities.validNextChar("Do you want to select Package and data bundle automatically (Y/N): ", new char[]{'Y', 'N'});

        PACKAGE packageT;
        DATA dataBundle;

        do {
            if (!Utilities.YNtoBoolean(option)){
                // Get the package and the data bundle by asking enter a number. Then use that number (index = number -1) to get the enum type
                packageT   = ContractUtility.intToPackageT(Utilities.validNextInt("Enter the package (1=Small, 2=Medium, 3=Large) : ",1,3));
                dataBundle = ContractUtility.intToDataT(Utilities.validNextInt("Enter the data bundle (1=Low, 2=Medium, 3=High and 4=Unlimited) : ",1,4));
            }
            else{
                int minutes = Utilities.validNextInt("Please enter estimated minutes(start from 0 min to 2000 min): ",0,2000);
                int dataAmount = Utilities.validNextInt("Please enter estimated data MB(start from 0): ",0, (int) Double.POSITIVE_INFINITY);

                // using utility select the package and the data bundle
                packageT = ContractUtility.selectPackage(minutes,dataAmount);
                dataBundle = ContractUtility.selectDataBundle(dataAmount);
            }

            // If the packages are compatible exit from the loop
            if (ContractUtility.isContractValid(packageT,dataBundle)){
                break;
            }
            else{
                System.out.println("\nPackage and the data bundle are not compatible please change the plan!");
            }
        }while (true);

        String refNumber = ContractUtility.validateRefNumber("Enter the reference number : ");

        //Get the type of the user by refNumber
        ContractT type = ContractUtility.getTypeByRefNumber(refNumber);

        // validate and get the period
        int period = ContractUtility.validatePeriod("Enter the period : ",type);

        // Get the status of the international calls
        boolean isAllowIntCalls = Utilities.YNtoBoolean(Utilities.validNextChar("Do you need allow International calls (Y/N): ", new char[]{'Y', 'N'}));

        // Calculate the date
        String date = Utilities.getDate();

        // Get the discount
        int discount = ContractUtility.getDiscount(type,period);

        // Get the monthly charge
        int chargePerMonth = ContractUtility.calculateMonthlyCharge(packageT,dataBundle,period,isAllowIntCalls,type);

        // create the object of the contract
        Contract contract = new Contract(packageT,dataBundle,date,period,isAllowIntCalls,refNumber,clientName,chargePerMonth,discount,type);

        // Display the data
        ContractUtility.displayContract(clientName,refNumber,date,packageT,dataBundle,period,type,discount,chargePerMonth,isAllowIntCalls);

        // save the object to contracts.txt
        ContractUtility.saveContract(contract);

    }

    /**
     * This method will get user and validate it using {@link Utilities#validNextInt(String, int, int)} function
     * Then call the {@link ContractUtility#getSummary(int)} with the given option
     *
     */
    public static void  displaySummary(){
        // get the user option
        int option = Utilities.validNextInt("Select the file\n1.\tmain (contracts.txt)\n2.\tarchive (archive.txt)\nEnter the option: ",1,2);
        ContractUtility.getSummary(option);
    }


    /**
     * Get the user input and validate it using {@link Utilities#validNextInt(String, int, int)} methods. Also get the ecpectedd month and validate
     * it using {@link Utilities#validFixedLenNextLine(String, int)} function.Then
     * Call the {@link ContractUtility#getSelectedMonthSummary(int, String)} function.
     */
    public static void displaySummaryOfSelectedMonth(){
        int option = Utilities.validNextInt("Select the file\n1.\tmain (contracts.txt)\n2.\tarchive (archive.txt)\nEnter the option: ",1,2);
        String month =ContractUtility.validateMonth("Enter the month (\"Jan\") : ");

        ContractUtility.getSelectedMonthSummary(option,month);
    }

    /**
     * This method will get the option to select the file from the user.   Then get the search term and validate both inputs.
     * {@link Utilities#validNextInt(String, int, int)} and {@link Utilities#validNextLine(String, int)} methods
     *
     * Then using {@link ContractUtility#findContract(int, String)} display the all results to the user
     */
    public static void findAndDisplay(){
        int option = Utilities.validNextInt("Select the file\n1.\tmain (contracts.txt)\n2.\tarchive (archive.txt)\nEnter the option: ",1,2);
        String searchTerm = Utilities.validNextLine("Please enter the reference number or name : ",25);

        ContractUtility.findContract(option,searchTerm);
    }

    /**
     * This method is the running the Driver method that handle the all the functions of the app.
     * <ul>
     *     <li>{@link #createContract()}</li>
     *     <li>{@link #displaySummary()}</li>
     *     <li>{@link #displaySummaryOfSelectedMonth()}</li>
     *     <li>{@link #findAndDisplay()}</li>
     * </ul>
     */
    public static void runApp(){
        int option;
        do {
            option = mainMenu();

            switch (option) {
                case 1 -> createContract();
                case 2 -> displaySummary();
                case 3 -> displaySummaryOfSelectedMonth();
                case 4 -> findAndDisplay();
            }

        }while(option != 0) ;

        System.out.println("Have a nice day!");
    }

}