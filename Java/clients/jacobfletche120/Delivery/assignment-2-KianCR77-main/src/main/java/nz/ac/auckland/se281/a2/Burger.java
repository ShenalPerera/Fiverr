package nz.ac.auckland.se281.a2;

import nz.ac.auckland.se281.a2.cli.Menu;

public class Burger extends Food{
    public Burger(String name, float price){
        super(name,price);
    }

    @Override
    public String toString() {
        return getName() + ": $" + String.format("%.2f",getPrice());
    }

    @Override
    public char getLabel() {
        return 'b';
    }

    public Menu.SIZE getSize(){
        return null;
    }
}
