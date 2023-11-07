import java.util.ArrayList;
import java.util.Arrays;

//Student ID:
//Student Name:

/*/
Student Comments:


*/


public class A5Q1 {
    
    //This should find all the permutations of a string and return those in an array
    //feel free to write any helper method(s) that would do the recursion 
    //You may assume that the String s is made of unique characters (no character repeated)
    public static ArrayList<String> permute(String s)
    {
        ArrayList<String> permutations =  new ArrayList<String>();
        int start = 0;
        int end = s.length() - 1;

        recursive_permute(s,start,end,permutations);

        return permutations;//should return an arraylist
    }

    // Function to swap the incidence of the string
    public static String swap(String word, int start, int end){
        {
            char temp;
            char[] charArray = word.toCharArray();  // Split it into charavters
            temp = charArray[start] ;
            charArray[start] = charArray[end];
            charArray[end] = temp;
            return String.valueOf(charArray);
        }
    }
    // Recursion function of permuting
    public static void recursive_permute(String word, int start, int end, ArrayList<String> words){
        // Catch the base case for each stack
        if(start == end){
            words.add(word);
        }
        else{
            for (int i = start; i <= end; i++)
            {
                word = swap(word,start,i);
                recursive_permute(word, start+1, end,words);
                word = swap(word,start,i);
            }
        }
    }

    public static void main(String[] args)
    {
        System.out.println(A5Q1.permute("ABCDE"));
    }
}
