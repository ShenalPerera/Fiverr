package ie.atu.sw;

public class Parser {
    public static String[] parseTheLine(String line){

        String [] words = line.trim().split(" ");

        for (int i =0; i< words.length; i++){
            words[i] = words[i].trim().replaceAll("[^a-zA-Z0-9]", "").toUpperCase();
        }
        return words;
    }
}
