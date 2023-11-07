package models;

/**
 * Subclass of the App class
 */
public class GameApp extends App {
    // Private variables that unique to GameApp class
    private boolean isMultiplayer = false; //default value is false
    private int rating;

    /**
     * There is one constructor for this class.
     * The parameter list for this constructor should be the same as the parameter list for the App class but with the additional field (isMultiplayer).
     * The constructor should call the superclass constructor and also instantiate the multiplayer field.
     *
     * @param developer
     * @param appName
     * @param appSize
     * @param appVersion
     * @param appCost
     * @param isMultiplayer
     */


    public GameApp(Developer developer, String appName, double appSize, double appVersion, double appCost, boolean isMultiplayer) {
        // Call the super contructor of the App class
        super(developer, appName, appSize, appVersion, appCost);
        setMultiplayer(isMultiplayer); // call the setMultiplayer method to set the value

    }

    // Setting Up Multiplayer
    public boolean isMultiplayer() { // method to check whther game is  multiplayer
        return isMultiplayer; // return the boolean field of this app (true = yes, false = no)
    }

    public void setMultiplayer(boolean multiplayer) {
        isMultiplayer = multiplayer;
    }

    /**
     * isRecommendedApp
     * @return boolean value
     */
   // public boolean isRecommendedApp() {
       // if (isMultiplayer() && listRatings()>= 4.0) { // if the app is multiplayer and has more than 3.9 ratings
           // return true;  // return true
       // }
      //  return false; // otherwise not recommended
   // }

    @Override
    public boolean isRecommendedApp() {
        return false;
    }

    /**
 * appSummary
 */

    // Return a string that consist with all details of the app
    public String appSummary() {
        return "Name: " + getAppName() + "Version:" + getAppVersion() + "The Price:" + getAppCost() + "Rating: " + calculateRating();

    }
}
