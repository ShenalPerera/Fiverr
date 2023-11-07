package pieces;

/*
 * Abstract Piece class that all pieces inherit from
 * Contains the color, name, and location of the piece
 * Has abstract methods which implementation will be different for each piece 
 */

import chess.Board;

public abstract class Piece {
    public String color;
    public String name;
    private boolean firstMove = true;
    private boolean secondMove = true;

    public Piece(String color, String name) {
        this.color = color;
        this.name = name;
    }

    public String getColor() {
        return color;
    }

    public String getName() {
        return name;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setFirstMove(boolean firstMove) {
        this.firstMove = firstMove;
    }

    public boolean getSecondMove() {
        return this.secondMove;
    }

    public void setSecondMove(boolean secondMove) {
        this.secondMove = secondMove;
    }

    public String getInverse() {
        if (color.equals("white")) {
            return "black";
        } else {
            return "white";
        }
    }

    public boolean isFirstMove() {
        return this.firstMove;
    }

    public abstract boolean isValidMove(int currentRow, int currentCol, int newRow, int newCol);
        
}