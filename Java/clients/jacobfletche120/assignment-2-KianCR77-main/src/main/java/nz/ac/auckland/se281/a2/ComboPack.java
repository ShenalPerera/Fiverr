package nz.ac.auckland.se281.a2;

import nz.ac.auckland.se281.a2.cli.Menu;

public class ComboPack extends Food{

    private Menu.SIZE size;

    // Set name by combining all the three items and the sizes
    public ComboPack(String nameBurger, float priceBurger, String nameSnack, float priceSnack, String nameDrink,
                     float priceDrink, Menu.SIZE size){
        String name = "COMBO : (" + nameBurger + ", " + nameSnack + " (" + size.toString() + "), " + nameDrink + " (" +size.toString() + "))";
        setName(name);

        // Update the price according to the size and set the price
        float price = priceBurger + priceSnack;
        switch (size){
            case XL -> setPrice(price + 4f + (4f+priceDrink)/2);
            case L -> setPrice(price + 3f + (3f+priceDrink)/2);
            case M -> setPrice(price+priceDrink/2);
        }
        this.size = size;
    }

    @Override
    public String toString() {
        return getName() +": $"+ String.format("%.2f",getPrice());
    }

    @Override
    public char getLabel() {
        return 'c';
    }

    @Override
    public Menu.SIZE getSize() {
        return size;
    }
}
