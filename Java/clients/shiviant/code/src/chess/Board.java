package chess;

import pieces.*;

import java.util.List;

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

    public boolean isCheck(String color) {
        // Find the location of the king of the specified color
        int kingRow = -1;
        int kingCol = -1;
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                Piece piece = this.getPiece(row, col);
                if (piece instanceof King && piece.getColor().equals(color)) {
                    kingRow = row;
                    kingCol = col;
                    break;
                }
            }
            if (kingRow != -1 && kingCol != -1) {
                break;
            }
        }
        if (kingRow == -1 || kingCol == -1) {
            // King not found, so not in check
            return false;
        }

        // Check if any opponent piece can attack the king
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                Piece piece = this.getPiece(row, col);
                if (piece != null && !piece.getColor().equals(color)) {
                    if (piece.isValidMove(row, col, kingRow, kingCol) && !isPathBlocked(row,col,kingRow, kingCol)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    public boolean isCheckmate(String color) {
        // First check if the king is in check
        if (!isCheck(color)) {
            return false;
        }

        // Look for all the pieces of the specified color and see if any of them can move
        // to a square that gets the king out of check
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                Piece piece = getPiece(row, col);
                if (piece != null && piece.getColor().equals(color)) {
                    // Check if the piece can move to any square that gets the king out of check
                    for (int destRow = 0; destRow < 8; destRow++) {
                        for (int destCol = 0; destCol < 8; destCol++) {
                            if (piece.isValidMove(row,col,destRow, destCol) ) {
                                // Try moving the piece to the destination square and see if it gets the king out of check
                                Piece originalPiece = getPiece(destRow, destCol);
                                setPiece(destRow, destCol, piece);
                                setPiece(row, col, null);
                                boolean kingSafe = !isCheck(color);
                                setPiece(row, col, piece);
                                setPiece(destRow, destCol, originalPiece);
                                if (kingSafe) {
                                    // The piece can get the king out of check, so it's not checkmate

                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }
        // If we reach this point, no piece can get the king out of check, so it's checkmate
        return true;
    }


}