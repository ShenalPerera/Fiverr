package ie.atu.sw;

import java.util.Scanner;

public class Menu {
    private Scanner scanner;

    public Menu() {
        this.scanner = new Scanner(System.in);
    }

    public int getUserInput() {
        int userInput;
        do {

            printMenu();

            userInput = scanner.nextInt();

            if (userInput <= 7 && userInput >= 1) {
                return userInput;
            }

            System.out.print(ConsoleColour.RED_BOLD_BRIGHT);
            System.out.println("Invalid option. Please Try again !");
            System.out.println(ConsoleColour.RESET);
        } while (true);

    }

    private void printMenu() {
        System.out.println(ConsoleColour.WHITE);
        System.out.println("************************************************************");
        System.out.println("*       ATU - Dept. Computer Science & Applied Physics     *");
        System.out.println("*                                                          *");
        System.out.println("*                   ADFGVX File Encryption                 *");
        System.out.println("*                                                          *");
        System.out.println("************************************************************");
        System.out.println("(1) Specify Input File Directory");
        System.out.println("(2) Specify Output File Directory");
        System.out.println("(3) Set Key");
        System.out.println("(4) Encrypt");
        System.out.println("(5) Decrypt");
        System.out.println("(6) Options"); //Add as many menu items as you like.
        System.out.println("(7) Quit");

        //Output a menu of options and solicit text from the user
        System.out.print(ConsoleColour.BLACK_BOLD_BRIGHT);
        System.out.print("Select Option [1-4]> ");
        System.out.println(ConsoleColour.RESET);
    }

    public String getStringFromUser(String promptMessage) {
        System.out.print(ConsoleColour.BLACK_BOLD_BRIGHT);
        System.out.print(promptMessage + " > ");
        System.out.println(ConsoleColour.RESET);
        return scanner.next();
    }
}
