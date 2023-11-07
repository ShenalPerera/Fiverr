import java.util.Random;
import java.util.Scanner;

public class DiceGame {

    public static int getPositiveIntFromUser(String userMessage){
        Scanner scanner = new Scanner(System.in);
        System.out.print(userMessage +": ");
        int number = scanner.nextInt();

        while (number <=0 ){
            System.out.print("Not a positive number, try again: ");
            number = scanner.nextInt();
        }
        return number;
    }

    private static void printMatchingCounts(int[] rollCounts) {
        int totalRolls = rollCounts[4];
        System.out.println("After " + totalRolls + " rolls:");
        double percentage;
        percentage = (double) rollCounts[0] / totalRolls * 100;
        System.out.printf("- Three dice matching : %d (%.1f%%)\n", rollCounts[0], percentage);
        percentage = (double) rollCounts[1] / totalRolls * 100;
        System.out.printf("- Four dice matching : %d (%.1f%%)\n", rollCounts[1], percentage);
        percentage = (double) rollCounts[2] / totalRolls * 100;
        System.out.printf("- Five dice matching : %d (%.1f%%)\n", rollCounts[2], percentage);
        percentage = (double) rollCounts[3] / totalRolls * 100;
        System.out.printf("- Three and two dice matching : %d (%.1f%%)\n", rollCounts[3], percentage);
    }


    public static int[] printGame(int seed){
        int numberOfRolls = getPositiveIntFromUser("Enter number of rolls");
        Random rand = new Random(seed);

        int threeMatchCounts = 0;
        int fourMatchCounts = 0;
        int fiveMatchCounts = 0;
        int twoThreeCounts = 0;

        for (int round = 0; round < numberOfRolls; round++){

            int[] dice = new int[5];

            for (int j = 0; j < 5; j++){
                dice[j] = rand.nextInt(6) + 1;
            }

            int[] counts = new int[6];

            for (int die : dice) {
                counts[die - 1]++;
            }

            for (int count : counts) {
                if (count == 3) {
                    threeMatchCounts++;
                }
                else if (count == 4){
                    fourMatchCounts++;
                }
                else if (count == 5){
                    fiveMatchCounts++;
                }
                else if (count == 2){
                    for (int i : counts) {
                        if (i == 3) {
                            twoThreeCounts++;
                            break;
                        }
                    }
                }
            }

        }


        return new int[]{threeMatchCounts, fourMatchCounts, fiveMatchCounts, twoThreeCounts, numberOfRolls};
    }

    public static void calFinalResults(int[] tempResult, int[] finalResults){

        for (int i =0; i < tempResult.length; i++){
            finalResults[i] += tempResult[i];
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int seed = getPositiveIntFromUser("Enter a seed");

        int [] results;
        int []finalResults =  new int[5];

        do {
            results = printGame(seed);
            printMatchingCounts(results);
            calFinalResults(results,finalResults);

            System.out.print("\nWould you like to run experiment again (Y/N)? ");
            String answer = scanner.next();

            char letter = Character.toLowerCase(answer.charAt(0));
            if (letter == 'y') continue;
            if (letter == 'n') break;

        }while (true);

        printMatchingCounts(finalResults);
    }

}
