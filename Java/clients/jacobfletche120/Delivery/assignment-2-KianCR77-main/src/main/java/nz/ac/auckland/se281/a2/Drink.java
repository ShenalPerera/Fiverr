package nz.ac.auckland.se281.a2;

import nz.ac.auckland.se281.a2.cli.Menu;

public class Drink extends Snack{
    public Drink(String name, float price , Menu.SIZE size){
        super(name, price, size);
    }

    @Override
    public char getLabel() {
        return 'd';
    }
}
