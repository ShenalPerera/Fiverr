package main;

import controllers.AppStoreAPI;
import controllers.DeveloperAPI;
import models.*;
import utils.ScannerInput;


public class Driver {

    //TODO Some skeleton code has been given to you.
    //     Familiarise yourself with the skeleton code...run the menu and then review the skeleton code.
    //     Then start working through the spec.

    private DeveloperAPI developerAPI = new DeveloperAPI();
    private AppStoreAPI appStoreAPI = new AppStoreAPI();

    public static void main(String[] args) {
        new Driver().start();
    }

    public void start() {
        loadAllData();
        runMainMenu();
    }

    private int mainMenu() {
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
        return ScannerInput.validNextInt("==>> ");
    }

    private void runMainMenu() {
        int option = mainMenu();
        while (option != 0) {
            switch (option) {
                case 1 -> runDeveloperMenu();
                case 2 -> runAppStoreMenu();
                case 3 -> runReportsMenu();
                case 4 -> searchAppsBySpecificCriteria();
                //case 5 -> sortApps();
                case 6 -> showRecommendedApps();
                case 7 -> showRandomAppOfTheDay();
                case 8 -> simulateRatings();
                case 9 -> saveAllData();
                case 10 -> loadAllData();
                default -> System.out.println("Invalid option entered: " + option);
            }
            ScannerInput.validNextLine("\n Press the enter key to continue");
            option = mainMenu();
        }
        exitApp();
    }

    private void exitApp() {
        saveAllData();
        System.out.println("Exiting....");
        System.exit(0);
    }

    //--------------------------------------------------
    //  Developer Management - Menu Items
    //--------------------------------------------------
    private int developerMenu() {
        System.out.println("""
                 -------Developer Menu-------
                |   1) Add a developer       |
                |   2) List developer        |
                |   3) Update developer      |
                |   4) Delete developer      |
                |   0) RETURN to main menu   |
                 ----------------------------""");
        return ScannerInput.validNextInt("==>> ");
    }

    private void runDeveloperMenu() {
        int option = developerMenu();
        while (option != 0) {
            switch (option) {
                case 1 -> addDeveloper();
                case 2 -> System.out.println(developerAPI.listDevelopers());
                case 3 -> updateDeveloper();
                case 4 -> deleteDeveloper();
                default -> System.out.println("Invalid option entered" + option);
            }
            ScannerInput.validNextLine("\n Press the enter key to continue");
            option = developerMenu();
        }
    }

    private void addDeveloper() {
        String developerName = ScannerInput.validNextLine("Please enter the developer name: ");
        String developerWebsite = ScannerInput.validNextLine("Please enter the developer website: ");

        if (developerAPI.addDeveloper(new Developer(developerName, developerWebsite))) {
            System.out.println("Add successful");
        } else {
            System.out.println("Add not successful");
        }
    }

    private void updateDeveloper() {
        System.out.println(developerAPI.listDevelopers());
        Developer developer = readValidDeveloperByName();
        if (developer != null) {
            String developerWebsite = ScannerInput.validNextLine("Please enter new website: ");
            if (developerAPI.updateDeveloperWebsite(developer.getDeveloperName(), developerWebsite))
                System.out.println("Developer Website Updated");
            else
                System.out.println("Developer Website NOT Updated");
        } else
            System.out.println("Developer name is NOT valid");
    }

    private void deleteDeveloper() {
        String developerName = ScannerInput.validNextLine("Please enter the developer name: ");
        if (developerAPI.removeDeveloper(developerName) != null) {
            System.out.println("Delete successful");
        } else {
            System.out.println("Delete not successful");
        }
    }

    private Developer readValidDeveloperByName() {
        String developerName = ScannerInput.validNextLine("Please enter the developer's name: ");
        if (developerAPI.isValidDeveloper(developerName)) {
            return developerAPI.getDeveloperByName(developerName);
        } else {
            return null;
        }
    }

    private void runAppStoreMenu() {
        int choice = ScannerInput.validNextInt("""
                -------App Store Menu Menu-----
                |  1) Add an app              |
                |  2) Update an app           |
                |  3) Delete app              |
                |  0) Return to main menu     |
                ------------------------------
                ==>>  """);

        if (choice != 0) {
            switch (choice) {
                case 1 -> addApp();
                //case 2 -> updateApp();
                case 3 -> deleteApp();
                default -> System.out.println("Invalid choice : " + choice);
            }
        }
    }


    private void addApp() {
        int choice = ScannerInput.validNextInt("""
                -------Adding an app-----------
                |  1) Add Education app       |
                |  2) Add Productivity app    |
                |  3) Add GameApp             |
                |  0) Return to main menu     |
                ------------------------------
                ==>>  """);

        if (choice != 0) {
            switch (choice) {
                case 1 -> addEducationApp();
                case 2 -> addProductivityApp();
                // case 3 -> addGameApp();
                default -> System.out.println("Invalid choice entered: " + choice);
            }
        }
    }

    private void addEducationApp() {
        EducationApp edu1 = new EducationApp(developerAPI.getDeveloperByName(ScannerInput.validNextLine("DEVELOPER NAME?")), ScannerInput.validNextLine("APP NAME?"),
                ScannerInput.validNextInt("APP SIZE?"), ScannerInput.validNextDouble("APP VERSION?"), ScannerInput.validNextInt("AGE RATING?"),
                ScannerInput.validNextDouble("APP COST?"));
        appStoreAPI.addApp(edu1);
    }

    private void addProductivityApp() {
        ProductivityApp prod1 = new ProductivityApp(developerAPI.getDeveloperByName(ScannerInput.validNextLine("DEVELOPER NAME?")), ScannerInput.validNextLine("APP NAME?"),
                ScannerInput.validNextInt("APP SIZE?"), ScannerInput.validNextDouble("APP VERSION?"), ScannerInput.validNextInt("AGE RATING?")
        );
        appStoreAPI.addApp(prod1);
    }
    private void deleteApp() {
        System.out.println(appStoreAPI.listAllApps());
        App deletedApp = appStoreAPI.deleteAppByIndex(ScannerInput.validNextInt("NAME OF APP TO DELETE?"));
        if (deletedApp == null) {
            System.out.println("FAILURE");
        } else {
            System.out.println("SUCCESS");
        }
    }

    private void runReportsMenu() {
        int choice = ScannerInput.validNextInt("""
                -------Reports Menu------------
                |  1) Apps overview           |
                |  2) Developers Overview     |   
                |  0) Return to main menu     |
                ------------------------------
                ==>>  """);

        if (choice != 0) {
            switch (choice) {
                case 1 -> appsOverview();
                case 2 -> developerOverview();
                default -> System.out.println("Invalid choice entered: " + choice);
            }
        }
    }

    private void appsOverview() {
        int choice = ScannerInput.validNextInt("""
                ------------------------------------
                Which app store report do you want? |                      |
                |  1) Education apps                |
                |  2) Game apps                     |
                |  3) Productivity apps             |
                |  0) RETURN to main menu           |
                -------------------------------------
                ==>>  """);

        if (choice != 0) {
            switch (choice) {
                case 1 -> educationAppReport();
                case 2 -> gameAppReport();
                case 3 -> productivityAppReport();
                default -> System.out.println("Invalid choice entered: " + choice);
            }
        }
    }

    private void educationAppReport() {
        System.out.println(appStoreAPI.listAllEducationApps());
    }
    private void gameAppReport() {
        System.out.println(appStoreAPI.listAllGameApps());
    }
    private void productivityAppReport() {
        System.out.println(appStoreAPI.listAllProductivityApps());
    }

    private void developerOverview() {
        int choice = ScannerInput.validNextInt("""
                ------------------------------------
                View developer report on            |
                |  1) All Developers                |
                |  2) Specific Developer            |
                -------------------------------------
                ==>>  """);

        if (choice != 0) {
            switch (choice) {
                case 1 -> allDeveloperReport();
                case 2 -> specificDeveloperReport();
                default -> System.out.println("Invalid choice entered: " + choice);
            }
        }
    }
    private void allDeveloperReport() {
        System.out.println(developerAPI.listDevelopers());
    }

    private void specificDeveloperReport() {
        Developer dev1 = developerAPI.getDeveloperByName(ScannerInput.validNextLine("DEVELOPER NAME?"));
        System.out.println(dev1);
    }


    private void searchAppsBySpecificCriteria() {
        System.out.println("""
                What criteria would you like to search apps by:
                  1) App Name
                  2) Developer Name
                  3) Rating (all apps of that rating or above
                  4) Search RecommendedApps)""");
        int option = ScannerInput.validNextInt("==>> ");
        if (option != 0) {
            switch (option) {
                case 1 -> searchAppsByName();
                case 2 -> searchAppsByDeveloper();
                case 3 -> searchAppsEqualOrAboveAStarRating();
                case 4 -> searchRecommendedApps();
                default -> System.out.println("Invalid option");
            }
        }
    }

    private void searchAppsByName() {
        System.out.println(appStoreAPI.listAllAppsByName
                (ScannerInput.validNextLine("APP NAMES?")));

    }

    private void searchAppsByDeveloper() {
        System.out.println(appStoreAPI.listAllAppsByChosenDeveloper(developerAPI.getDeveloperByName
                (ScannerInput.validNextLine("DEVELOPER NAME?"))));

    }

    private void searchRecommendedApps() {
        System.out.println(appStoreAPI.listAllRecommendedApps());

    }

    private void searchAppsEqualOrAboveAStarRating() {
        System.out.println(appStoreAPI.listAllAppsAboveOrEqualAGivenStarRating(
                (ScannerInput.validNextInt("STAR RATING?"))));
    }

    private void showRecommendedApps() {
        System.out.println(appStoreAPI.listAllRecommendedApps());
    }

    private void showRandomAppOfTheDay() {
        System.out.println(appStoreAPI.randomApp());
    }

    //--------------------------------------------------
    // TODO UNCOMMENT THIS COMPLETED CODE as you start working through this class
    //--------------------------------------------------
    private void simulateRatings() {

        if (appStoreAPI.numberOfApps() > 0) {
            System.out.println("Simulating ratings...");
            appStoreAPI.simulateRatings();
            System.out.println(appStoreAPI.listSummaryOfAllApps());
        } else {
            System.out.println("No apps");
        }
    }


    //--------------------------------------------------
    //  Persistence Menu Items
    //--------------------------------------------------

    private void saveAllData() {
        try {
            appStoreAPI.save();
            developerAPI.save();
        } catch (Exception e) {
            System.err.println("Error writing to file: " + e);
        }
    }

    private void loadAllData() {
        try {
            appStoreAPI.load();
            developerAPI.load();
        } catch (Exception e) {
            System.err.println("Error reading from file: " + e);
        }
    }

}