import java.io.File;
import java.io.FileNotFoundException;
import java.util.Random;
import java.util.Scanner;

public class MadLibsGame {
    public static String[] getWordListFromFile(String fileCategoryName) throws FileNotFoundException {
        Scanner scanner = new Scanner(System.in);
        String fileName;
        File file;
        boolean fileExists;

        System.out.print("Please enter file name for " + fileCategoryName + ": ");
        fileName = scanner.nextLine();
        file = new File(fileName);
        fileExists = file.exists();

        while (!fileExists) {
            System.out.print("File does not exist, try again: ");
            fileName = scanner.nextLine();
            file = new File(fileName);
            fileExists = file.exists();
        }
        System.out.println(fileName + " successfully found.\n");
        return setWordsIntoTheArray(file);

    }

    public static String[] setWordsIntoTheArray(File file) throws FileNotFoundException {
        Scanner fileScanner = new Scanner(file);
        int wordCount =  Integer.parseInt(fileScanner.nextLine());

        String[] words = new String[wordCount];
        int i = 0;
        while (fileScanner.hasNextLine() && i < wordCount){
            words[i] = fileScanner.nextLine();
            i++;
        }

        return words;
    }

    public static String getRandomWordFromArray(String[] words,  Random random){
        int size = words.length;
        int index = random.nextInt(size);
        return words[index];
    }



    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int seed;
        int numberOfSentences;

        try {
            String[] adjectives = getWordListFromFile("adjectives");
            String[] animals = getWordListFromFile("animals");
            String[] objects = getWordListFromFile("objects");
            String[] answers = getWordListFromFile("answers");

            System.out.print("Enter a seed: ");
            while (true){
                seed = scanner.nextInt();
                if (seed > 0) break;
                System.out.print("Not a positive number, try again: ");
            }

            System.out.print("Enter number of sentences to produce: ");
            while (true){
                numberOfSentences = scanner.nextInt();
                if (numberOfSentences  >=1 && numberOfSentences <= 50) break;
                System.out.print("Not between 1 and 50, try again: ");
            }
            Random random = new Random(seed);

            System.out.println("\nHere are the sentences:\n");

            for (int i = 1; i < numberOfSentences+1; i++){
                System.out.printf("Sentence %d: Six %s %s sit in the %s. Do they fit? %s\n",
                        i,
                        getRandomWordFromArray(adjectives,random),
                        getRandomWordFromArray(animals,random),
                        getRandomWordFromArray(objects,random),
                        getRandomWordFromArray(answers,random)
                        );
            }

        }
        catch (FileNotFoundException e){
            System.out.println("Unexpected error occurred");
        }
    }
}
