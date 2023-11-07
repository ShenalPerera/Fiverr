package pieces;

public class King extends Piece {
    public King (String color, String name) {
        super(color, name);
        if (color.equals("white")) {
            this.name = "wK";
        } else {
            this.name = "bK";
        }
    }

    /* 
     * A king moves one square in any direction
     * so the difference between the current row and the new row
     * must be less than or equal to 1
     * and the difference between the current column and the new column
     * must be less than or equal to 1
     * if the difference is less than or equal to 1, then the king can move to the new position
    */

    @Override
    public boolean isValidMove(int currentRow, int currentCol, int newRow, int newCol) {
        if (Math.abs(currentRow - newRow) == 0 && Math.abs(currentCol - newCol) == 1) {
            return true;
        } else if (Math.abs(currentRow - newRow) == 1 && Math.abs(currentCol - newCol) == 0) {
            return true;
        } else if (Math.abs(currentRow - newRow) == 1 && Math.abs(currentCol - newCol) == 1) {
            return true;
        } else {
            return false;
        }
    }

}