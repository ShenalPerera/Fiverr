// Name the package
package controllers;

// import relevant libraries
import com.thoughtworks.xstream.XStream;
import com.thoughtworks.xstream.io.xml.DomDriver;
import models.*;
import utils.*;

// import java inbuilt classes
import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

// import Random function from math library
import static java.lang.Math.random;
import static utils.RatingUtility.generateRandomRating;

// Define the class AppStoreAPI
public class AppStoreAPI {

    // Declare the private variable called apps as ArrayList data type
    private List<App> apps = new ArrayList<>();

    /**
     * Constructor
     * The constructor should instantiate the apps ArrayList.
     */
    public AppStoreAPI() {
        apps = new ArrayList<>();
    }

    /**
     * addApp
     *
     * @param app
     * This function will add app to the apps arraylist by using this function. Relevant app object is given in the argument
     * and it is added to the list
     */
    public void addApp(App app) {
        apps.add(app);
    }


    /**
    * This function will return a string. If the arraylist apps is empty then it will return "No apps"
     * Otherwise it will go through the apps list and print return whole a string
    *
    */
    public String listAllApps() {
        String str = "";                    // Initialize the str string variable to empty string
        int index = 0;                      // Int variable to keep the track of the index of each app
        if (!apps.isEmpty()) {              // Checking whther the apps list is empty
            for (App app : apps) {          // If list has apps then go through each one by one using for loop
                index++;                    // Keep increment for every new app in the list
                str += index + "." + app;   // Update the str with index of the app and . and the app object

            }
            return str;                     // Now this consist every details of the apps cumulatively when looping and return str
        }
        return "No apps";
    }


    /**
     * deleteAppByIndex
     *
     * @param IndexToDelete
     * @return RemovedApp
     */
    // Function to delete an app with given index
    public App deleteAppByIndex(int IndexToDelete) {
        // Check whether given index is valid using the helper function (isValidIndex function in the utilities)
        if (Utilities.isValidIndex(apps, IndexToDelete)) return apps.remove(IndexToDelete ); // if it is valid remove the app with given index
        // In here remove is in-built function for remove item from an arraylist
        return null; // if the index is invalid return null
    }

    /**
    *getAppByIndex
     * @param indexToFind
     * @return Matched App
     */
    public App getAppByIndex(int indexToFind) {
        // Check the validity of the index using helper function (See the Utilities)
        if (Utilities.isValidIndex(apps, indexToFind)) return apps.get(indexToFind);// if index is valid get the app from list
        return null; // if invalid index return null
    }

    /**
     * getAppByName
     * @param name
     * @return foundApp
     * Function to get the app by its name
     */
    public App getAppByName(String name) {
        // Local variable to keep the found app(initialize to null)
        App foundApp = null;

        // Go through the apps list using loop
        for (App app : apps) {
            // For each app check whether given name is match withe app name without taking the cases
            if (app.getAppName().equalsIgnoreCase(name)) {
                foundApp = app;     // If the name is matched assign the foundApp varable to current matched app
            }
        }

        return foundApp;    // return the app(If app is not found this will return null)
    }

    /**
     * listSummaryOfAllApps
     * @return String
     */
    public String listSummaryOfAllApps() {
        // If the list (apps) is empty this will return "No apps"
        if (apps.isEmpty()) {
            return "No apps";
        }

        // Local string varaible to keep the summary. This will get updated with each app
        String allSummaries = "";
        // Keep track of the index
        int index = 0;
        // Loop through the apps list
        for (App app : apps) {
            index++;                // increase the index for each app by one
            allSummaries = allSummaries + index + "." + " " + app.appSummary(); // update the allSummaries variable
            // cumulatively with index of the app.<space>and the summary of each app(Class specific for function)
        }

        return allSummaries;    // return the summary string

    }

    /**
     *
     * @return String
     */

    // This function is same as the above. But it will only list the Game App OBJECTS only
    public String listAllGameApps() {
        if (!apps.isEmpty()) {
            String str = "";    // Empty string to keep the details
            int index = 0;      // keep tack of the all games apps index
            for (App app : apps) {  // loop through the list
                index++;        // increase the index for each app
                if (app instanceof GameApp) {   // Condition check for gameApp instance if yes update the string otherwise ignore the app
                    str += index + "." + app + " "; // if this is a gameapp then update the details in the str string
                }
            }
            return str; // return the str
        }
        return "No Game apps";  // if not return the "NO Game apps " message
    }

    /*
        This app will list all Educational apps. In the above function this will differ from the consition checking.
        This will check whether the current considering app is instance(object) of the EducationApp
     */

    /**
     *
     * @return detailsOfAllEducational APPs
     */
    public String listAllEducationApps() {
        if (!apps.isEmpty()) {  // To check the apps list is not empty
            String str = "";    // This string is o keep the details of the each releted app
            int index = 0;      // index is to track the index of the app
            for (App app : apps) {  // loop through the each app
                index++;        // increase the index by one for each app to keep the consistent of the app index
                if (app instanceof EducationApp) { // Condition for check this belongs to Education App
                    str += index + "." + app + " "; // update the ( add the details to the current str)
                }

            }
            return str; // return the str if one or more Educational app found
        }
        return "No Education apps found";   // Message for if not found
    }

    /*
        This app will list all Educational apps. In the above function this will differ from the consition checking.
        This will check whether the current considering app is instance(object) of the Productive App
     */

    /**
     *
     * @return detailsOfAllProductive apps
     */
    public String listAllProductivityApps() {
        if (apps.isEmpty()) {   // check the apps list is empty
            return "No Productivity apps found";    // if list is empty return this message
        }
        String str = "";    // empty string to keep the details of productive apps
        int index = 0;      // index to keep the track the position of the app in the list
        for (App app : apps) {  // loop through the each app
            index++;    // increase the value by one for each app
            if (app instanceof ProductivityApp) {   // check whther current app is a productive app
                str += index + "." + app + " "; //if it is object of productiveApp lass then update the details
            }

        }
        return str; // return thestring if one such ap is found
    }

    /*
        Above three member functions are doing the same thing. It will keep empty string and update the string accoring to
        the app found in the list. Each function differ from the category of the app. Game, education and Productive
     */


    /**
     *
     * @param appName
     * @return string
     * This function will get the name of app as argument. Then it will check similar name with apps in the list.
     * If found update the str variable. If the list is empty it will return a messase "looks like <appName> <space> exists
     */
    public String listAllAppsByName(String appName) {
        String str = "";    // Empty string
        for (App app : apps) {  // Loop through each app
            if (app.getAppName().equalsIgnoreCase(appName)) {   // check the name is match withe given name
                str += app + " ";       // If it is matchupdate the string
            }
        }
        // If the strig str is empty return this meesage
        if (str.isBlank()) {
            return "looks like " + appName + " exists";
        }
        // If not return the updated string
        return str;
    }

    // Function to count how many apps in the list
    public int numberOfApps(){
        return apps.size(); // return the size of the list apps
    }

    /**
     *
     * @param rating
     * @return string contins details about the apps that have equal or higher rating compare to argument
     */
    public String listAllAppsAboveOrEqualAGivenStarRating(int rating) {
        String str = "";        // Empty string to keep the details of the apps
        for (App app : apps) { // loop through every apps
            if (app.calculateRating() >= rating) {  // check the current app rating (using calculateRating() function) and given i the argument

                str += app + " "; // Update the string if condition is true
            }
        }
        // If string is empty it means no apps found related to given rating and return relevant meesage
        if (str.isBlank()) {
            return "No apps have the rating of " + rating + " or above";
        }
        // if apps found str hase the detalis of each relevant apps and return this str
        return str;
    }

    // App class has isRecommendedAPP() function that will return true if it is. Loop through the each apps and check whther
    // app is recommended using above mentioned function. If yes update the details of the app. If no apps found return NO APPs
    public String listAllRecommendedApps() {
        String str = "";
        for (App app : apps) {
            if (app.isRecommendedApp()) {
                str += app + " ";
            }
        }
        if (str.isBlank()) {
            return "NO APPS";
        }
        return str;
    }

    /**
     *
     * @param developer
     * @return String
     * This app get an object of the Developer class. And check whther current app is developed by this developer
     * if yes update the details of the every app that relevant to given developer and return the string. If not Return relevant message
     * that says NO APS FOR DEVELOPER <developer>
     */
    public String listAllAppsByChosenDeveloper(Developer developer) {
        String str = "";
        for (App app : apps) {
            if (app.getDeveloper().equals(developer)) { // check the given developer and the current app's developer is same
                str += app + " ";   // if yes update the details
            }
        }
        // Condition of no apps found and return relevant message
        if (str.isBlank()) {
            return "NO APS FOR DEVELOPER: " + str;
        }
        // otherwise return the str
        return str;
    }

    //Function to get ab random app from the list
    public App randomApp() {
        // Generate a random number between 0 and the size of the list
        int random1 = new Random().nextInt(0, apps.size()); //This will random give number between 0 and size of the list
        return apps.get(random1);   // return the app in the list withe generated random index
    }

    // Function to  simulate the rating of the app
    public void simulateRatings() {
        // Loop through every app in the list
        for (App app : apps) {
            // Using member function of the app (addRating()) add a rating to the app
            app.addRating(generateRandomRating());  // To generate the random rating useed the helper function from utils
        }
    }

    /**
     *
     * @param appName
     * @return Boolean
     * Loop through the every app and check the app has given name. If one such app is found return tru if not return false
     */
    public boolean isValidAppName(String appName) {
        for (App app1 : apps) {
            if (app1.getAppName().equalsIgnoreCase(appName)) { // check the equality of the names
                return true;
            }
        }
        return false;
    }

    // Function to check the validity of the index.
    public boolean isValidIndex(int index) throws FileNotFoundException {
        return (index >= 0) && (index < apps.size()); // return boolean accroding to the given index
        // Flase if out of range other wise true
    }


        @SuppressWarnings("unchecked")
        public void load () throws Exception {
            //list of classes that you wish to include in the serialisation, separated by a comma
            Class<?>[] classes = new Class[]{App.class, EducationApp.class, GameApp.class, ProductivityApp.class, Rating.class};

            //setting up the xstream object with default security and the above classes
            XStream xstream = new XStream(new DomDriver());
            XStream.setupDefaultSecurity(xstream); // Set the security
            xstream.allowTypes(classes);        // Allows acces to type Classes

            //doing the actual serialisation to an XML file
            ObjectInputStream in = xstream.createObjectInputStream(new FileReader("app.xml"));
            apps = (List<App>) in.readObject(); // read the objects
            in.close(); // close the stream
        }

        // Function to save the objects in xml format
        public void save () throws Exception {
        //  Create XStream object with DomDriver()
            XStream xstream = new XStream(new DomDriver());
            // Create the object stream named out with given file name
            ObjectOutputStream out = xstream.createObjectOutputStream(new FileWriter("app.xml"));
            out.writeObject(apps);  // write the apps to out
            out.close();    // close stream
        }

        public String fileName () {
            return "app.xml";
        }

    public void sortAppsByNameAscending() {
    }
}

