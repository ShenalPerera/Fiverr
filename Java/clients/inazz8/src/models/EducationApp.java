package models;

// Importing Libraries

import utils.Utilities;

/**
 * This class is child class of the App class. This has additional attribute called level and additional methods
 */

public class EducationApp extends App {

    private int level = 0;      // private variable to keep the level


    /**
     * // Constructor
     *
     * @param developer
     * @param appName
     * @param appSize
     * @param appVersion
     * @param appCost
     * @param v
     */

    public EducationApp(Developer developer, String appName, double appSize, double appVersion, double appCost, double v)
    {
        // Call the super class (App) constructor
        super(developer, appName, appSize, appVersion, appCost);
        // set the level varaible
        setLevel(level);
    }

    /**
     * GetLevel Method
     */
    public int getLevel() { // method to set the level field of this Education app
        return level; // rturn the level field value
    }

    /**
     * setLevel
     * @param level Includes validation to make sure it has a min 1 and max 10
     */
    public void setLevel(int level) {
        if (Utilities.validRange(level, 1, 10)) {   // level should be in range 1 and 10
            this.level = level; // set the level
        }
    }

    /**
     * isRecommendedApp
     * @return boolean value
     */
    // Method to check this app is recommended or not
    public boolean isRecommendedApp() {
        if (getAppCost() > 0.99 && calculateRating() >= 3.5 && getLevel() >= 3) {   // if the rating of this app is equal or above 3.5 and
            // cost is above than 0.99 and level of the app is greater or rqual to 3 retrun true
            return true;
        }
        return false;   // if not recommended return false
    }

    /**
     * appSummary
     * @return toString
     * A method connects all the strings and sends them to toString()
     */
    public String appSummary() {
        return "Developer " + getDeveloper().toString() + "App Name: " + getAppName() + "Version: " + getAppVersion() + "The Price: " + getAppCost() + "Rating: " + calculateRating() + "Level: " + getLevel();
    }
}

