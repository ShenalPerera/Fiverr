package nz.ac.auckland.se281.a2;


import nz.ac.auckland.se281.a2.cli.Menu;

public abstract class Food {
    // Price and the name of the food
    private float price;
    private String name;

    // Constructor
    public Food(String name, float price){
        this.name = name;
        this.price = price;
    }

    // Default constructor
    public Food(){}


    // Getter and setter for encapsulation

    // Method to get the price
    public float getPrice() {
        return price;
    }

    //Methods to set the price and names
    public void setName(String name) {
        this.name = name;
    }

    public void setPrice(float price) {
        this.price = price;
    }

    // method to get the name
    public  String getName(){
        return name;
    };

    // Override the toString method to print the food to CLI
    @Override
    public  abstract String toString();

    // Get the label to identify the food item
    public abstract char getLabel();

    public abstract Menu.SIZE getSize();

}
