package SampleFilesForIOwithFiles.ReadReviewProject;
public class Review {
    private String userName = "NoName";
    private int rating = -1;
    
    public void setUserName(String revUserName) {
       userName = revUserName;        
    }
 
    public void setRating(int revRating) {
       rating = revRating;
    }
 
    public String getUserName() { return userName; }
    public int getRating() { return rating; }
 }