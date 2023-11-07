package ie.atu.sw;

public class Runner {

	public static void main(String[] args) {
		Menu menu = new Menu();
		
		boolean isExit = false; 
		do {
			
			isExit = menu.getUserInput() == 8;
			
		}while(!isExit);
	}

}
