import java.util.Scanner;

public class Testing {
    static Scanner scanner = new Scanner(System.in);
    static String[] products = {"Crew Neck", "V-Neck", "Polo", "Boat Neck", "Tank Top"};

    public static void main(String[] args) {
        System.out.println("Choose 1,2,3 or exit");

        while (scanner.hasNextLine()){
            int choice = scanner.nextInt();
            String c = scanner.nextLine(); // jump to next line
            if (choice == 1) {
                System.out.println("You choose 1");
            }
            else if (choice == 2) {
                System.out.println("Choose 2");
            }
            else if (choice == 3){
                System.out.println("Type product");
                String userInput = scanner.nextLine();

                System.out.println("userInput is: " + userInput);
            }
        }
    }
}
