package nz.ac.auckland.se281.a2;

import nz.ac.auckland.se281.a2.cli.Menu;

public class Snack extends Food{

    private Menu.SIZE size;

    public Snack(String name, float price, Menu.SIZE size){
        super(name,price);
        this.size = size;

        // Update the price according to the size
        switch (size) {
            case L -> setPrice(price + 3f);
            case XL -> setPrice(price + 4f);
        }
    }

    // Method to change and get the size
    public void setSize(Menu.SIZE size) {
        this.size = size;
    }

    public Menu.SIZE getSize() {
        return size;
    }

    @Override
    public String toString() {
        return getName() + " (" + getSize().toString() + "): $" + String.format("%.2f",getPrice());
    }

    @Override
    public char getLabel() {
        return 's';
    }
}
