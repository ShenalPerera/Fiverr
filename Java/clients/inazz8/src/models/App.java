package models;

//Import Libraries

import utils.Utilities;

import java.util.ArrayList;
import java.util.List;

// Class to create App object
public abstract class App {

    // Private attributes of the class

    private Developer developer;    // Developer object to keep the track of developer of this app

    private String appName = "No app name"; // String to keep the name ("Initialize to No app name")

    private double appSize = 0; // Double to keep the size of this app

    private double appVersion = 1.0;    // Current version of tha pp

    private double appCost = 0;     // Cost of the app

    private List<Rating> ratings = new ArrayList(); // list of ratings

    /**
     * Constructor Signature:
     *
     * @param developer
     * @param appName
     * @param appSize
     * @param appVersion
     * @param appCost
     */

    public App(Developer developer, String appName, double appSize, double appVersion, double appCost){
        /**
         * In here all methods are set methods. These methods are defined below. These method takes relevant type
         * argument and update the object attribute with that value
         */
        setDeveloper(developer);    // set the developer variable by using setDeveloper method
        setAppName(appName);        // set the appName field by using setAppName method
        setAppSize(appSize);        // set the appSize field by using setAppSize method
        setAppVersion(appVersion);  // set The version field
        setAppCost(appCost);        // set the cost field
}

    /**
     * There one abstract method in this class (the three concrete classes will provide the implementation for it):
     * isRecommendedApp()
     */

    public abstract boolean isRecommendedApp(); //This is the abstract method in the app class (implementation differ from child to child)

    /**
     *
     * @return string that consist the name,version cost and rating
     */
    public String appSummary() {
        // make and return cumulatively added string with above-mentioned attributes
        return "app name " + appName + " version " + appVersion  + " app cost " + appCost + " overall rating value " + ratings.size();
    }

/**
 * add a rating to the ratings ArrayList.
 * @param rating
 * @return ratings added to ratings arraylist
 */

    public boolean addRating(Rating rating) {
    return ratings.add(rating); // Given rating object in the argument is added to the list ratings and default add method
        // return boolean whether add is success or not
}

    /**
     * build a string containing all the ratings and return it. If no ratings have been added yet, return "No ratings added yet".
     * @return
     */

    public String listRatings() {
        if (ratings.isEmpty()) {    // check the ratings list is empty
            return "No ratings added yet";  // if it is empty return this messsage
        } else {
            String string = ""; // otherwise, str is initialized to empty (to keep the details of the apps)
            for (Rating ratings1 : ratings) {   // Loop through the rating object in the ratings list one by one
                string += ratings1;         // add each rating to that string variable
            }
            return string;          // return the string
        }
    }

    // Method to calculate the sum of the rating of the current app
    public double calculateRating() {
        double SumOfRatings = 0;    // variable to keep the sum
        int i = 0;              // keep the track of the ratings
        double avgRating = 0;   // Variable to keep the average
        for (Rating ratings1 : ratings) {   // loop through each rating of this app
            if (!(ratings1.getNumberOfStars() <= 0)) {  // check whether rating (number of stars) is not 0 or negtive
                SumOfRatings += ratings1.getNumberOfStars();    // get the number of stars from each object and sum them up
                i++;    // increase one by when the rating is occurred
            }
        }
        // Calculate the average by deviding the number of stars by count of the number of ratings (i)
        avgRating = SumOfRatings / i;
        // if rating lit is empty retun 0.0
        if (ratings.isEmpty()) {
            return 0.0;
        }
        // if not return the average calculated rating
        return avgRating;
    }

    //Abstract Methods

        /**
         * getDeveloper
         */
        public Developer getDeveloper() { // method to get the developer of the app
            return developer;           // return the developer of this app
        }

        /**
         * setDeveloper
         */
        public void setDeveloper(Developer developer) { // method to set the developer
            this.developer = developer; // set the developer filed with equal to given developer in the argument
        }

    /**
     * getAppName
     */
    public String getAppName() {    // public method to get the app name of this app
        return appName;     // return the name of the app
    }

    /**
     * setAppName
     */
    public void setAppName(String appName) { // method to set the app name
        this.appName = appName; // assign the appName filed of this app to given value in the argument
    }

    /**
     * getAppSize
     */

    public double getAppSize() { // get the size of the app
        return appSize; // return the value in the appSize field
    }

    /**
     * setAppSize
     */

    public void setAppSize(double appSize) {    // method to set the app size
        if (Utilities.validRange(appSize, 1, 1000)) { // check the appSize argument in the range 1 <= appsize <= 1000
            this.appSize = appSize;// if it is valid then update the appSize to given value
        }
    }

    /**
     * getAppVersion
     */
    public double getAppVersion() { // method to geth the appVerion value
        return appVersion;  // return the appVersion filed value
    }

    // Setters for the private variables
    /**
     * setAppVersion
     */
    public void setAppVersion(double appVersion) { // Method to set the appVersion
        if (appVersion >= 1.0) { // check whther given value is equal or greater than 1.0
            this.appVersion = appVersion; // if yes update the appCersion field to given value
        }
    }

    /**
     * getAppCost
     */
    public double getAppCost() { // method to get the value in appCost field
        return appCost; // return the appCost field value
    }

    /**
     * setAppCost
     */
    public void setAppCost(double appCost) {
        if (appCost >= 0) {     // Check the given cost is non-zero and  not negative
            this.appCost = appCost; // if it is valid set the appCost
        } else {
            return; // otherwise, return from the method without doing anything
        }
    }

    /**
     * ArrayList GetRatings
     */
    public List<Rating> getRatings() { // method to get the ratings list
        return ratings; // return the ratings list of this app
    }

    /**
     * setRatings
     */
    public void setRatings(List<Rating> ratings) { // method to set the ratings list
        this.ratings = ratings; // assign the ratings list to given list
    }

    /**
     * Method to convert the app to string. This will make a string with its' attributes. This override method will returns it
     * @return
     */
    public String toString() {
        return "App{" + "developer=" + developer + ", appName='" + appName + '\'' + appSize + "MB" + "(Version " + appVersion +  "Cost: " + appCost +  "Ratings (" + calculateRating() + listRatings() + '}';
    }
}