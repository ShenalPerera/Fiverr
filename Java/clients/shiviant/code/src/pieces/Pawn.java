package pieces;

public class Pawn extends Piece {

    public Pawn(String color, String name) {
        super(color, name);
        if (color.equals("white")) {
            this.name = "wP";
        } else {
            this.name = "bP";
        }
    }

    /*
     * A pawn moves forward one space
     * if it has not moved yet, it can move forward two spaces
     */
    @Override
    public boolean isValidMove(int currentRow, int currentCol, int newRow, int newCol) {
        if (Math.abs(newCol - currentCol) == 0) {
            if (getColor().equals("white")) {
                if (newRow - currentRow == -1 || (newRow - currentRow == -2 && this.isFirstMove())) {
                    return true;
                } else {
                    return false;
                }
            } else {
                if (newRow - currentRow == 1 || (newRow - currentRow == 2 && this.isFirstMove())) {
                    return true;
                } else {
                    return false;
                }
            }
        }
        return false;
    }

    public boolean isValidCapture(int currentRow, int currentCol, int newRow, int newCol) {
        if (Math.abs(newCol - currentCol) == 1) {
            if (getColor().equals("white")) {
                if (newRow - currentRow == 1) {
                    return true;
                } else {
                    return false;
                }
            } else {
                if (newRow - currentRow == -1) {
                    return true;
                } else {
                    return false;
                }
            }
        }
        return false;
    }
}
