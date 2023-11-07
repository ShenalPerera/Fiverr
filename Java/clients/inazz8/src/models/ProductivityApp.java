package models;
// Subclass of the app Class . Only have one additional member function than the parent(App)
public class ProductivityApp extends App {
    /**
     * There is one constructor for this class.
     *
     * @param developer
     * @param appName
     * @param appSize
     * @param appVersion
     * @param appCost
     */

    public ProductivityApp(Developer developer, String appName, double appSize, double appVersion, double appCost){
        super(developer, appName, appSize, appVersion, appCost); // Call the super class constructor
    }

    /**
     * isRecommendedApp
     * A more involved method that returns a boolean
     *
     * @return boolean value
     */
    public boolean isRecommendedApp() {
        if (getAppCost() >= 1.99 && calculateRating() > 3.0 ) { // Check whether cost is greater or equal to 1.99 and check rating is above 3.0
            return true; // if this condition is true
        }
        return false; // otherwise false
    }
}