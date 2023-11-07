package chess;

import pieces.*;

public class Board {
    Piece[][] board = new Piece[8][8];

    // Initial setup of the board
    public void setup() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                this.board[i][j] = null;
            }
        }
        
        // set up pawns
        for(int i = 0; i < 8; i++) {
            pieces.Pawn whitePawn = new pieces.Pawn("white", "wP");
            pieces.Pawn blackPawn = new pieces.Pawn("black", "bP");
            this.board[6][i] = whitePawn;
            this.board[1][i] = blackPawn;
        }

        // white pieces
        this.board[7][0] = new pieces.Rook("white", "wR");
        this.board[7][1] = new pieces.Knight("white", "wN");
        this.board[7][2] = new pieces.Bishop("white", "wB");
        this.board[7][3] = new pieces.Queen("white", "wQ");
        this.board[7][4] = new pieces.King("white", "wK");
        this.board[7][5] = new pieces.Bishop("white", "wB");
        this.board[7][6] = new pieces.Knight("white", "wN");
        this.board[7][7] = new pieces.Rook("white", "wR");

        // black pieces
        this.board[0][0] = new pieces.Rook("black", "bR");
        this.board[0][1] = new pieces.Knight("black", "bN");
        this.board[0][2] = new pieces.Bishop("black", "bB");
        this.board[0][3] = new pieces.Queen("black", "bQ");
        this.board[0][4] = new pieces.King("black", "bK");
        this.board[0][5] = new pieces.Bishop("black", "bB");
        this.board[0][6] = new pieces.Knight("black", "bN");
        this.board[0][7] = new pieces.Rook("black", "bR");
    }

    public boolean isPiecePresent(int row, int col) {
        if (this.board[row][col] == null) {
            return false;
        } else {
            return true;
        }
    }

    public Piece getPiece(int row, int col) {
        return this.board[row][col];
    }

    public void setPiece(int row, int col, Piece piece) {
        board[row][col] = piece;
    }

    public void clearTile(int row, int col) {
        this.board[row][col] = null;
    }

    public void printBoard() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                /*
                If the tile is empty, print an empty space
                If the tile is not empty, print the piece's name
                
                Note: Empty black tiles are marked with a double hash (##)
                */
                if (this.board[i][j] == null) {
                    if ((i + j) % 2 != 0) {
                        System.out.print("## ");
                    } else {
                        System.out.print("   ");
                    }
                } else {
                    System.out.print(this.board[i][j].getName() + " ");
                }
            }
            System.out.println(8 - i);
        }
        System.out.println(" a  b  c  d  e  f  g  h");
    }

    public void movePiece(int currentRow, int currentCol, int newRow, int newCol) {
        this.board[newRow][newCol] = this.board[currentRow][currentCol];
        this.board[currentRow][currentCol] = null;
    }

    public Piece[][] getBoard() {
        return this.board;
    }
    public boolean isPathBlocked(int currentRow, int currentCol, int newRow, int newCol) {
        Piece piece = this.getPiece(currentRow, currentCol);
        if (piece instanceof Knight) {
            return false;
        }
        int diffRow = newRow - currentRow;
        int diffCol = newCol - currentCol;
        int directionRow = Integer.compare(diffRow, 0);
        int directionCol = Integer.compare(diffCol, 0);
        int row = currentRow + directionRow;
        int col = currentCol + directionCol;
        while (row != newRow || col != newCol) {
            if (board[row][col] != null) {
                return true;
            }
            row += directionRow;
            col += directionCol;
        }
        return false;
    }

    // Check for check or checkmate
    // method to check if the opponent king is under check or not
   public boolean isKingUnderCheck(int row, int col, boolean isWhiteTurn, boolean checkOpponentKing) {
    // loop through the entire board
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                // if there is a piece present on the current square
                if (board[i][j] != null) {
                    if (checkOpponentKing) {
                        if (board[i][j].getColor().equals("white") == isWhiteTurn) {
                            if (board[i][j].isValidMove(i, j, row, col)) {
                                if (!isPathBlocked(i, j, row, col)) {
                                    return true;
                                }
                            }
                        }
                    } else {
                        if (board[i][j].getColor().equals("white") != isWhiteTurn) {
                            if (board[i][j].isValidMove(i, j, row, col)) {
                                if (!isPathBlocked(i, j, row, col)) {
                                    return true;
                                }
                            }
                        }
                    }
                }

            }
        }
        return false;
    }
}