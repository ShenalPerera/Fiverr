package nz.ac.auckland.se281.a2;

import nz.ac.auckland.se281.a2.cli.Menu.SIZE;
import nz.ac.auckland.se281.a2.cli.MessagesCLI;

import java.util.ArrayList;

public class BurgerShop {
	//Cart
	private final ArrayList<Food> cart = new ArrayList<>();

	public BurgerShop() {

	}



	/**
	 * Add a burger in the cart
	 * 
	 * @param name
	 * @param price
	 */
	public void addBurger(String name, float price) {
		// TODO TASK1
		this.cart.add(new Burger(name,price));

	}

	/**
	 * add a snack in the cart, if size is L the price should be incremented by $3
	 * if the size is XL the price should be incremented by $4 (@see
	 * nz.ac.auckland.se281.a2.cli.Menu.SIZE)
	 * 
	 * 
	 * @param name
	 * @param price
	 * @param size
	 */
	public void addSnack(String name, float price, SIZE size) {
		// TODO TASK1
		this.cart.add(new Snack(name,price,size));
	}

	/**
	 * 
	 * add a drink in the cart
	 * 
	 * if size is L the price should be incremented by $3 if the size is XL the
	 * price should be incremented by $4 (@see
	 * nz.ac.auckland.se281.a2.cli.Menu.SIZE)
	 * 
	 *
	 * @param name
	 * @param price
	 * @param size
	 */
	public void addDrink(String name, float price, SIZE size) {
		// TODO TASK1
		this.cart.add(new Drink(name,price,size));
	}

	/**
	 * print the content of the cart, or print MessagesCLI.CART_EMPTY if the cart is
	 * empty
	 *
	 *
	 */
	public void showCart() {
		// TODO TASK1
		float total = 0;
		for (int i = 0; i < cart.size(); i++){
			System.out.println(i + " - " + cart.get(i));
			total = total + cart.get(i).getPrice();
		}

		if (total >= 100){
			MessagesCLI.DISCOUNT.printMessage();
			total = total * 0.75f;
		}
		if (!cart.isEmpty()){

			System.out.println("Total: $"+ String.format("%.2f",total));
		}
		else{
			MessagesCLI.CART_EMPTY.printMessage();
		}
	}

	/**
	 * add a combo in the cart.
	 * 
	 * The price of a combo is the sum of all the items, but the drink would be half
	 * price. Note that in a combo, both snacks and drinks have the same size, and
	 * the combo price must consider the size (@see addSnack and addDrink methods).
	 * 
	 * @param nameBurger
	 * @param priceBurger
	 * @param nameSnack
	 * @param priceSnack
	 * @param nameDrink
	 * @param priceDrink
	 * @param size
	 */
	public void addCombo(String nameBurger, float priceBurger, String nameSnack, float priceSnack, String nameDrink,
			float priceDrink, SIZE size) {
		// TODO TASK2
		this.cart.add(new ComboPack(nameBurger,priceBurger,nameSnack,priceSnack,nameDrink,priceDrink,size));
	}

	/**
	 * remove the item in the cart specified by the position posCart. Note that the
	 * position of the cart start from zero. if postCart is invalid: posCart < 0 OR
	 * posCart >= size of the cart the method prints
	 * MessagesCLI.NOT_VALID_CART_POSITION
	 * 
	 * @param posCart
	 */
	public void removeItem(int posCart) {
		// TODO TASK3
		if (posCart >= 0 && posCart < cart.size()){
			this.cart.remove(posCart);
		}
		else if (cart.isEmpty()){
			MessagesCLI.CART_EMPTY.printMessage();
		}
		else{
			MessagesCLI.NOT_VALID_CART_POSITION.printMessage();
		}

	}

	/**
	 * removes all elements in the cart
	 */
	public void clearCart() {
		// TODO TASK3
		if (cart.isEmpty()){
			MessagesCLI.CART_EMPTY.printMessage();
		}
		else{
			this.cart.clear();
		}

	}

	/**
	 * This method confirms the order, showing the estimated pick up time. It also
	 * give a warning if there are missing opportunities for COMBO menus
	 * 
	 */
	public void confirmOrder() {
		// TODO TASK4
		if (this.cart.isEmpty()){
			MessagesCLI.ORDER_INVALID_CART_EMPTY.printMessage();
		}
		else{
			boolean isBurgerFound = false;

			boolean isSnackFound = false;
			boolean isDrinkFound = false;

			boolean isLargeSnackFound = false;
			boolean isLargeDrinkFound = false;

			boolean isXLSnackFound = false;
			boolean isXLDrinkFound = false;

			boolean isCombo = false;

			boolean isFirstBurgerFound = false;
			boolean  isFirstSnackFound = false;
			boolean isFirstDrinkFound = false;

			int totalSeconds = 0;

			for (Food food : cart) {
				if (food.getLabel() == 'b') {
					isBurgerFound = true;

				}

				switch (food.getLabel()){
					case 'b':
						isBurgerFound = true;

						if (!isFirstBurgerFound) {
							isFirstBurgerFound = true;
							totalSeconds += 5 * 60;
						} else {
							totalSeconds += 60;
						}
						break;

					case 's':
						if (!isSnackFound && food.getSize() == SIZE.M) isSnackFound = true;
						if (!isLargeSnackFound && food.getSize() == SIZE.L) isLargeSnackFound = true;
						if (!isXLSnackFound && food.getSize() == SIZE.XL) isXLSnackFound = true;

						if (!isFirstSnackFound) {
							isFirstSnackFound = true;
							totalSeconds += 3 * 60;
						} else {
							totalSeconds += 30;
						}
						break;


					case 'd':
						if (!isDrinkFound && food.getSize() == SIZE.M) isDrinkFound = true;
						if (!isLargeDrinkFound && food.getSize() == SIZE.L) isLargeDrinkFound = true;
						if (!isXLDrinkFound && food.getSize() == SIZE.XL) isXLDrinkFound = true;

						if (!isFirstDrinkFound) {
							isFirstDrinkFound = true;
							totalSeconds += 45;
						} else {
							totalSeconds += 15;
						}
						break;
					case 'c':
						if (!isFirstBurgerFound) {
							isFirstBurgerFound = true;
							totalSeconds += 5 * 60;
						} else  {
							totalSeconds += 60;
						}
						if (!isFirstSnackFound) {
							isFirstSnackFound = true;
							totalSeconds += 3 * 60;
						} else {
							totalSeconds += 30;
						}
						if (!isFirstDrinkFound) {
							isFirstDrinkFound = true;
							totalSeconds += 45;
						} else {
							totalSeconds += 15;
						}


				}

				isCombo = isBurgerFound && ((isSnackFound && isDrinkFound) || (isLargeSnackFound && isLargeDrinkFound) || (isXLSnackFound && isXLDrinkFound));




			}

			if (isCombo){
				MessagesCLI.MISSED_COMBO.printMessage();
			}

			else{
				int hours = totalSeconds / 3600;
				int minutes = (totalSeconds % 3600) / 60;
				int seconds = totalSeconds % 60;

				showCart();

				String hourString = String.format("%d hours",hours);
				String minutesString = String.format("%d minutes",minutes);
				String secondsString = String.format("%d seconds",seconds);

				String timeString = hourString + " " + minutesString + " " + secondsString;

				System.out.println(MessagesCLI.ESTIMATE_WAITING_TIME.getMessage() + timeString);

				clearCart();
			}
		}



	}


}
