package utils;

// TODO Nothing!  This class is complete but you need to implement this in DeveloperAPI and AppStoreAPI

// Interface for serialzer
public interface ISerializer {
    // abstract method for save method
    void save() throws Exception;
    // abstract method to load
    void load() throws Exception;
    // abstract method to fileName()
    String fileName();
}