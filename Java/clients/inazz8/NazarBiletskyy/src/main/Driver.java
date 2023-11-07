package main;

import controllers.AppStoreAPI;
import controllers.DeveloperAPI;
import models.*;
import utils.ScannerInput;

// Main class (Driver)
public class Driver {

    //TODO Some skeleton code has been given to you.
    //     Familiarise yourself with the skeleton code...run the menu and then review the skeleton code.
    //     Then start working through the spec.

    // Create the instance of DeveloperApi
    private DeveloperAPI developerAPI = new DeveloperAPI();
    // Create the instance(object) of AppStoreAPI
    private AppStoreAPI appStoreAPI = new AppStoreAPI();

    // Define the main method
    public static void main(String[] args) {
        new Driver().start();   // In the main method , start() method of the Diver class is called
    }

    // Start method

    /**
     * In here loading the data and running the main menu method happen
     */
    public void start() {
        loadAllData();  // Load the data by caaling the loadAllData() method
        runMainMenu();  // run the main method by invoking the runMainMenu() method
    }

    // MainMenu method
    private int mainMenu() {
        // This will print the message (Menu) to user
        System.out.println("""
                 -------------App Store------------
                |  1) Developer - Management MENU  |
                |  2) App - Management MENU        |
                |  3) Reports MENU                 |
                |----------------------------------|
                |  4) Search                       |
                |  5) Sort                         |
                |----------------------------------|
                |  6) Recommended Apps             |
                |  7) Random App of the Day        |
                |  8) Simulate ratings             |
                |----------------------------------|
                |  20) Save all                    |
                |  21) Load all                    |
                |----------------------------------|
                |  0) Exit                         |
                 ----------------------------------""");
        // Get the input from using utility functions and validate it. according to thr validity return a number
        return ScannerInput.validNextInt("==>> ");
    }

    /**
     * runMainMenu method
     */
    private void runMainMenu() {
        int option = mainMenu();    // Get the number that will return from the mainMenu() method(User's selected number)
        // While the option is not equal to 0 this will run
        while (option != 0) {
            // Define switch to branch the each functions accrdoing to user option
            switch (option) {
                case 1 -> runDeveloperMenu();   // 1 => will call the runDeveloperMenu() method
                case 2 -> runAppStoreMenu();    // 2 will call the runAppStoreMenu() method
                case 3 -> runReportsMenu();     // 3 will call the runReportsMenu()
                case 4 -> searchAppsBySpecificCriteria(); // 4 will call the searchAppsBySpecificCriteria()
                //case 5 -> sortApps();
                case 6 -> showRecommendedApps(); // 6 will call the showRecommendedApps()
                case 7 -> showRandomAppOfTheDay(); // 7 will call the showRandomAppOfTheDay()
                case 8 -> simulateRatings(); // 8 will call the simulateRatings()
                case 9 -> saveAllData(); // 9 will call the saveAllData()
                case 10 -> loadAllData(); // 10 will call the loadAllData()
                default -> System.out.println("Invalid option entered: " + option); // if the given option is not above list this will
                // jump to default branch and it will print invalid message
            }
            ScannerInput.validNextLine("\n Press the enter key to continue");   // wait until user press enter
            option = mainMenu();    // again get the user input by showing the main menu(above method)
        }
        exitApp();  // When exit from the while loop exit app function is called
    }

    /**
     * This function save the current data before exit . After the saving is happen then print the Exiting message and exit from the program
     */
    private void exitApp() {
        saveAllData();
        System.out.println("Exiting....");
        System.exit(0); // This line will exit the program
    }

    //--------------------------------------------------
    //  Developer Management - Menu Items
    //--------------------------------------------------
    private int developerMenu() {
        // Show the sub menu of developerMenu
        System.out.println("""
                 -------Developer Menu-------
                |   1) Add a developer       |
                |   2) List developer        |
                |   3) Update developer      |
                |   4) Delete developer      |
                |   0) RETURN to main menu   |
                 ----------------------------""");
        return ScannerInput.validNextInt("==>> ");  // get and validate the user input for developerMenu option
    }

    // Function to handle the developer menu and user input for this menu
    private void runDeveloperMenu() {
        int option = developerMenu();   // get the int value that return from theabove function(ussr input)
        while (option != 0) {           // exit when only user enter 0
            switch (option) {           // handle the each cases accoring to value of the option
                case 1 -> addDeveloper();   // 1 will call the addDeveloper()
                case 2 -> System.out.println(developerAPI.listDevelopers());    // 2 will display the list of developers
                case 3 -> updateDeveloper();    // 3 will call the updateDeveloper()
                case 4 -> deleteDeveloper();    // 4 WILL call the deleteDeveloper()
                // except 1,2,3and 4 other option will give invalid message
                default -> System.out.println("Invalid option entered" + option);
            }

            ScannerInput.validNextLine("\n Press the enter key to continue"); // press enter
            option = developerMenu();// Get the user input for next round
        }
    }


    private void addDeveloper() {
        // get the string from the user for name of the developer
        String developerName = ScannerInput.validNextLine("Please enter the developer name: ");
        // get the string from the user for website of the developer
        String developerWebsite = ScannerInput.validNextLine("Please enter the developer website: ");

        // add the developer to the list in the developerAPI and check the status in the if statement
        if (developerAPI.addDeveloper(new Developer(developerName, developerWebsite))) {
            System.out.println("Add successful");   // if above condition return true print the add is successful
        } else {
            System.out.println("Add not successful");   // else false message
        }
    }


    private void updateDeveloper() {
        // List the all developers details in the start
        System.out.println(developerAPI.listDevelopers());

        // get the developer from the given name
        Developer developer = readValidDeveloperByName();
        // if no developer found by name check the website
        if (developer != null) {
            String developerWebsite = ScannerInput.validNextLine("Please enter new website: "); // if  developer found by name check the website
            if (developerAPI.updateDeveloperWebsite(developer.getDeveloperName(), developerWebsite)) // update and check the status
                System.out.println("Developer Website Updated");    // print the message if consition is true
            else
                System.out.println("Developer Website NOT Updated");    // othesr wise false
        } else
            System.out.println("Developer name is NOT valid");  // if the developer not found return this message
    }

    /**
     * Function to delete the developer
     */
    private void deleteDeveloper() {
        // Get the developer name from the user
        String developerName = ScannerInput.validNextLine("Please enter the developer name: ");
        // And check remove from the list by name will not equal to null (Means developer deleted)
        if (developerAPI.removeDeveloper(developerName) != null) {
            System.out.println("Delete successful");    // print the successful message
        } else {
            System.out.println("Delete not successful");    // else return false message
        }
    }

    /**
     * function to get developer by name
     * @return
     */
    private Developer readValidDeveloperByName() {
        // get the name from th user
        String developerName = ScannerInput.validNextLine("Please enter the developer's name: ");
        // Check the status of the list of that name in the developer Api object
        if (developerAPI.isValidDeveloper(developerName)) {
            return developerAPI.getDeveloperByName(developerName);  // if true return the developer
        } else {
            return null;    // false means not found ==> return null
        }
    }


    private void runAppStoreMenu() {
        // print the menu and take the user input into the choice
        int choice = ScannerInput.validNextInt("""
                -------App Store Menu Menu-----
                |  1) Add an app              |
                |  2) Update an app           |
                |  3) Delete app              |
                |  0) Return to main menu     |
                ------------------------------
                ==>>  """);

        // check choice is not zero
        if (choice != 0) {
            switch (choice) {
                case 1 -> addApp(); // if choice is 1 addApp() will be called
                //case 2 -> updateApp();
                case 3 -> deleteApp();  // if 3 deleteApp() will be called
                default -> System.out.println("Invalid choice : " + choice);    // invalid number except 1 - 3
            }
        }
    }

    /**
     * Function to add an app
     */
    private void addApp() {
        // Get the user input by showinf the app category to user
        int choice = ScannerInput.validNextInt("""
                -------Adding an app-----------
                |  1) Add Education app       |
                |  2) Add Productivity app    |
                |  3) Add GameApp             |
                |  0) Return to main menu     |
                ------------------------------
                ==>>  """);

        // check user choose 0 if not go to the branch
        if (choice != 0) {
            switch (choice) {
                case 1 -> addEducationApp();    // 1 will call addEducationApp()
                case 2 -> addProductivityApp(); // 2 will call addProductivityApp()
                // case 3 -> addGameApp();
                default -> System.out.println("Invalid choice entered: " + choice); // default values except 1 -3
            }
        }
    }
    // Add education app method
    private void addEducationApp() {
        // Get the app from the list. And ask for the developwer name and the app name, size , version, rating and the cost from the user and according to that details create the app using constructor
        EducationApp edu1 = new EducationApp(developerAPI.getDeveloperByName(ScannerInput.validNextLine("DEVELOPER NAME?")), ScannerInput.validNextLine("APP NAME?"),
                ScannerInput.validNextInt("APP SIZE?"), ScannerInput.validNextDouble("APP VERSION?"), ScannerInput.validNextInt("AGE RATING?"),
                ScannerInput.validNextDouble("APP COST?"));
        appStoreAPI.addApp(edu1);   // add that newly created app (edu1) to the appStorAPI using add app method
    }

    private void addProductivityApp() {
        /**
         * Load the app by developer name. And get the size ,version and rating from the user and according to that create the
         * productive app using its constructor
         */
        ProductivityApp prod1 = new ProductivityApp(developerAPI.getDeveloperByName(ScannerInput.validNextLine("DEVELOPER NAME?")), ScannerInput.validNextLine("APP NAME?"),
                ScannerInput.validNextInt("APP SIZE?"), ScannerInput.validNextDouble("APP VERSION?"), ScannerInput.validNextInt("AGE RATING?")
        );
        appStoreAPI.addApp(prod1);  // add that app into appStoreAPI
    }
    private void deleteApp() {
        // list the all apps and its details
        System.out.println(appStoreAPI.listAllApps());
        // call the delete by index method in apStoreAPI class and will return the app.
        App deletedApp = appStoreAPI.deleteAppByIndex(ScannerInput.validNextInt("NAME OF APP TO DELETE?"));
        if (deletedApp == null) {   // check whther that returned value is null
            System.out.println("FAILURE");  // null means not successful
        } else {
            System.out.println("SUCCESS");  // else print the successful message
        }
    }

    /**
     * This function will show submenu if user input zero jump to main menu
     */
    private void runReportsMenu() {
        // get the user input by sgowing submenu
        int choice = ScannerInput.validNextInt("""
                -------Reports Menu------------
                |  1) Apps overview           |
                |  2) Developers Overview     |   
                |  0) Return to main menu     |
                ------------------------------
                ==>>  """);

        if (choice != 0) {  // checl user not entered zero
            switch (choice) {
                case 1 -> appsOverview();   // if user entered 1 then appsOverview() will be called
                case 2 -> developerOverview(); // 2 will call developerOverview()
                default -> System.out.println("Invalid choice entered: " + choice); // except 1 and 2 will print error message
            }
        }
    }

    private void appsOverview() {
        // get the user input by showing menu
        int choice = ScannerInput.validNextInt("""
                ------------------------------------
                Which app store report do you want? |                      |
                |  1) Education apps                |
                |  2) Game apps                     |
                |  3) Productivity apps             |
                |  0) RETURN to main menu           |
                -------------------------------------
                ==>>  """);

        if (choice != 0) {  // if user entered non-zero jump to the branch
            switch (choice) {
                case 1 -> educationAppReport(); // 1 will call the educationAppReport()
                case 2 -> gameAppReport(); //2 will call the gameAppReport()
                case 3 -> productivityAppReport(); // 3 will call the productivityAppReport()
                default -> System.out.println("Invalid choice entered: " + choice); // print the error message for invalid numbers
            }
        }
    }

    private void educationAppReport() {
        System.out.println(appStoreAPI.listAllEducationApps()); // print the details of educational apps using listAllEducationApps()
    }
    private void gameAppReport() {
        System.out.println(appStoreAPI.listAllGameApps()); // print the details of game apps using listAllGameApps()
    }
    private void productivityAppReport() {
        System.out.println(appStoreAPI.listAllProductivityApps());  // print the details of productive apps using listAllGameApps()
    }

    private void developerOverview() {
        // get the user input by showing the menu
        int choice = ScannerInput.validNextInt("""
                ------------------------------------
                View developer report on            |
                |  1) All Developers                |
                |  2) Specific Developer            |
                -------------------------------------
                ==>>  """);

        if (choice != 0) {  // check choice is not zero
            switch (choice) {
                case 1 -> allDeveloperReport(); // if choice is 1 then allDeveloperReport() will be called
                case 2 -> specificDeveloperReport(); // if choice is 2 then specificDeveloperReport() will be called
                default -> System.out.println("Invalid choice entered: " + choice); // eroor message for invalid input
            }
        }
    }
    // method to print the all details of the developer
    private void allDeveloperReport() {
        System.out.println(developerAPI.listDevelopers());  // print the details of the developers using  listDevelopers()
    }

    // method to print the specific developer details
    private void specificDeveloperReport() {
        // get the developer by user input name
        Developer dev1 = developerAPI.getDeveloperByName(ScannerInput.validNextLine("DEVELOPER NAME?"));
        // prin the details of that developer (dev1)
        System.out.println(dev1);
    }

    // Searching method in different ways
    private void searchAppsBySpecificCriteria() {
        // show the menu to user
        System.out.println("""
                What criteria would you like to search apps by:
                  1) App Name
                  2) Developer Name
                  3) Rating (all apps of that rating or above
                  4) Search RecommendedApps)""");
        // get the input from the user
        int option = ScannerInput.validNextInt("==>> ");
        if (option != 0) {  // check option is not 0
            switch (option) {
                case 1 -> searchAppsByName();   // if option is 1 then searchAppsByName() will be called
                case 2 -> searchAppsByDeveloper(); // if option is 2 then searchAppsByDeveloper() will be called
                case 3 -> searchAppsEqualOrAboveAStarRating(); // if option is 3 then searchAppsEqualOrAboveAStarRating() will be called
                case 4 -> searchRecommendedApps(); //  4 will call the searchRecommendedApps()
                default -> System.out.println("Invalid option"); // error message for invalid (except 1-4)
            }
        }
    }


    private void searchAppsByName() {
        System.out.println(appStoreAPI.listAllAppsByName // print the app details
                (ScannerInput.validNextLine("APP NAMES?")));    // app is get from the user input name

    }

    private void searchAppsByDeveloper() {
        // get the name of the developer by user
        // then load the app from the appStoreAPI list and print the details
        System.out.println(appStoreAPI.listAllAppsByChosenDeveloper(developerAPI.getDeveloperByName
                (ScannerInput.validNextLine("DEVELOPER NAME?"))));

    }

    private void searchRecommendedApps() {
        // print the all recommended apps by using listAllRecommendedApps() method
        System.out.println(appStoreAPI.listAllRecommendedApps());

    }

    private void searchAppsEqualOrAboveAStarRating() {
        // get the star ratinf from the user
        // and from that value load the all aps above or eqaul ro that rating using listAllAppsAboveOrEqualAGivenStarRating method
        System.out.println(appStoreAPI.listAllAppsAboveOrEqualAGivenStarRating(
                (ScannerInput.validNextInt("STAR RATING?"))));
    }

    private void showRecommendedApps() {
        // print the details of all recommended apps using  listAllRecommendedApps() method
        System.out.println(appStoreAPI.listAllRecommendedApps());
    }

    private void showRandomAppOfTheDay() {
        System.out.println(appStoreAPI.randomApp()); // get random app by using randomApp() method an print details
    }

    //--------------------------------------------------
    // TODO UNCOMMENT THIS COMPLETED CODE as you start working through this class
    //--------------------------------------------------
    // method to simulate the ratings
    private void simulateRatings() {

        if (appStoreAPI.numberOfApps() > 0) {   // check appStoreAPI has one or more apps
            System.out.println("Simulating ratings...");    // print the message
            appStoreAPI.simulateRatings();  // call the simulateRatings() method
            System.out.println(appStoreAPI.listSummaryOfAllApps()); // print the details using listSummaryOfAllApps()
        } else {
            System.out.println("No apps");  // if list is empty in the appStoreAPI object this message will be printed
        }
    }


    //--------------------------------------------------
    //  Persistence Menu Items
    //--------------------------------------------------

    private void saveAllData() {
        try {
            appStoreAPI.save(); // try to save the data in the appStoreAPI
            developerAPI.save();    // try to save the data in the developerAPI
        } catch (Exception e) {     // if above one of two give error
            System.err.println("Error writing to file: " + e); // print this message + exception
        }
    }

    // load the data
    private void loadAllData() {
        try {
            appStoreAPI.load(); // try to loa the data
            developerAPI.load();
        } catch (Exception e) {
            System.err.println("Error reading from file: " + e);    // if error happens in loading error message will print
        }
    }

}