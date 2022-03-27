package appLogin;

//import the Scanner library here

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	static ArrayList<Account> accounts = new ArrayList<Account>(); // an ArrayList containing a list of accounts
	static Scanner input = new Scanner(System.in); // a new Scanner object is instantiated

	public static void main(String[] args) {

		home(); // The program will start and will run the home() method

	}

	public static void home() {

		System.out.println("\n*******************************");
		System.out.println("*--->Please choose an OPTION; *");
		System.out.println("A - Register a new user");
		System.out.println("B - Log in to the system");
		System.out.println("C - View customer details");

		String myChoice = input.next();

		myChoice = myChoice.toUpperCase(); /*
								 * change this variable so that it uses an inbuilt function to change the input
								 * to upper case.
								 */

		switch (myChoice) {
		/*
		 * complete this switch statement to allow users to choose the options A, B or C
		 * seen above. Be aware of the names of the methods when implementing this.
		 */
			case "A":
				registerNewUser();
				break;
			case "B":
				logIn();
				break;
			case "C":
				viewDetails();
				break;
			default:
				break;
		}
	}

	public static void registerNewUser() {

		/*
		 * Complete this method. This method will ask a user to enter a username and
		 * password. The username and password must be at least 6 characters in length.
		 * Once this has been entered, these details will be used to create an Account
		 * object. The Account object will then need to be added to the ArrayList called
		 * accounts, found at the top of this program.
		 * 
		 * The method will ask the user if they wish to add another user. If the
		 * response is "yes", the program will run the registerNewUser() method again,
		 * otherwise the home() method will run. Ensure that the user is notified upon
		 * successful/unsuccessful registration.
		 */
		System.out.print("Enter the username: ");
		String username = input.next();
		System.out.print("Enter a password: ");
		String password = input.next();

		Account account ;
		if (password.length() < 6 || username.length() <6){
			System.out.println("Registration unsuccessful!");
		}
		else{
			account = new Account(username,password);
			boolean success = accounts.add(account);
			if (success){
				System.out.println("Registration successful!");
			}
		}
		System.out.print("Do you wish to add another user: ");
		String answer = input.next();

		if (answer.equalsIgnoreCase("yes")){
			registerNewUser();
		}
		else{
			home();
		}

	}

	public static void logIn() {

		/*
		 * Complete this method. This method will ask a user to enter their username and
		 * password. Once these details have been entered, the program will check to see
		 * if the username and password appear in the ArrayList called accounts. If the
		 * username and password match, the user will be notified that their login has
		 * been successful, otherwise the user will be notified that their login has
		 * been unsuccessful. The program will then run the home method.
		 * 
		 */
		System.out.print("Enter the username: ");
		String username = input.next();
		System.out.print("Enter the password: ");
		String password = input.next();

		boolean isFound =false;

		for (Account account : accounts) {
			if (account.user.equals(username) && account.pass.equals(password)) {
				System.out.println("Your login has been successful!");
				isFound = true;
				break;
			}
		}
		if (!isFound){
			System.out.println("Your login has been unsuccessful!");
		}
		home();

	}

	public static void viewDetails() {
		/*
		 * Complete this method. This method will simply loop through the accounts
		 * ArrayList, and then list the username of each account object. Ensure the
		 * users' passwords are not also displayed. After displaying the results, the
		 * program will run the home method, to take the user back to the main screen.
		 * 
		 */

		for (Account account:accounts ) {
			System.out.println(account.user);
		}
		home();

	}
}