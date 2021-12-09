package SampleFilesForIOwithFiles.ReadReviewProject;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.FileInputStream;
import java.io.IOException;

public class ReviewSystem {
    public static void main(String [] args) throws IOException {
      // Scanner scnr = new Scanner(System.in);
      double ratingAvg;      
      ArrayList<Review> reviewList = new ArrayList<Review>();
      String restaurantName;
      
      // Reads restaurant name and reviews from input file at program start
      restaurantName = readReviews(reviewList);

      ratingAvg = calcAvgRating(reviewList);
      displayReviews(restaurantName, reviewList, ratingAvg);
   }  
   public static String readReviews(ArrayList<Review> reviewList) throws IOException {
      FileInputStream fileByteStream = null; // File input stream
      Scanner inFS = null;                   // Scanner object
      String restaurantName;
      String userName;
      int userRating;

      // Try to open file
      System.out.println("Opening file Trattoria_Reviews.txt.");
      fileByteStream = new FileInputStream("files/Trattoria_Reviews.txt");
      inFS = new Scanner(fileByteStream);

      restaurantName = inFS.nextLine();

      while(inFS.hasNext()) {
         Review currentReview = new Review();
         userName = inFS.next();
         userRating = inFS.nextInt();

         currentReview.setUserName(userName);
         currentReview.setRating(userRating);
         reviewList.add(currentReview);
      }

      fileByteStream.close(); // close() may throw IOException if fails
      inFS.close();
      return restaurantName;
   }
   
   public static double calcAvgRating(ArrayList<Review> reviewList) {
      int i;
      double ratingAvg = 0;

      for(i = 0; i < reviewList.size(); ++i) {
         ratingAvg += reviewList.get(i).getRating();
      }
      return ratingAvg /= reviewList.size();
   }

   public static void displayReviews(String restaurantName,
                                     ArrayList<Review> reviewList,
                                     double ratingAvg) {
      int i;

      System.out.println("\n" + restaurantName);
      System.out.println("Average rating: " + ratingAvg);
      System.out.println("--------------------");

      for(i = 0; i < reviewList.size(); ++i) {
         System.out.println("User name: " + reviewList.get(i).getUserName());
         System.out.println("   Rating: " + reviewList.get(i).getRating());
         System.out.println();
      }
   }

}