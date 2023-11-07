package chess;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import pieces.*;

public class ChessGame {
    public static Board chessBoard;
    public static boolean whiteKingUnderCheck = false;
    public static boolean blackKingUnderCheck = false;
    public static boolean whiteKingUnderCheckmate = false;
    public static boolean blackKingUnderCheckmate = false;
    public static void main(String[] args) throws IOException {
        Board board = new Board();
        board.setup();
        board.printBoard();
        
        Boolean isWhiteTurn = true;
        
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            System.out.println();
            if (isWhiteTurn) {
                if (whiteKingUnderCheck) {
                    System.out.println("Check");
                }
                System.out.print("White's move: ");
            } else {
                if (blackKingUnderCheck) {
                    System.out.println("Check");
                }
                System.out.print("Black's move: ");
            }
            String input = reader.readLine().trim().toLowerCase();

            // length below 5 is invalid input
            if (input.length() < 5) {
                System.out.println("Illegal move, try again  ([DELETE LATER] Reason: bad input)");
                continue;
            } else if (input.equals("resign")) {
                System.out.println(isWhiteTurn ? "Black wins" : "White wins");
                break;
            } else if (input.substring(input.length() - 5).equals("draw?")) {
                System.out.println("draw");
                break;
            } else {
                // Parse input of FileRank FileRank format
                String[] inputArray2 = input.split(" ");
                String[] from = inputArray2[0].split("");
                String[] to = inputArray2[1].split("");

                int fromRow = 8 - Integer.parseInt(from[1]);
                int fromCol = from[0].charAt(0) - 'a';

                int toRow = 8 - Integer.parseInt(to[1]);
                int toCol = to[0].charAt(0) - 'a';

                System.out.println(fromRow + " " + fromCol + " " + toRow + " " + toCol);

                // Check if the piece is present
                if (!board.isPiecePresent(fromRow, fromCol)) {
                    System.out.println("Illegal move, try again ([DELETE LATER] Reason: not present)");
                    continue;
                }

                // if the target box is same as the current box, then you can't move the piece there 
                if(fromRow == toRow && fromCol == toCol) { 
                    System.out.println("Illegal move, try again ([DELETE LATER] Reason: same box)"); 
                    continue; 
                }

                // if there is a piece on target box and if it is same color as the piece on current box, then you can't move the piece there 
                if(board.isPiecePresent(toRow, toCol) && board.getPiece(toRow, toCol).getColor().equals(board.getPiece(fromRow, fromCol).getColor())) { 
                    System.out.println("Illegal move"); 
                    continue; 
                }

                // Check if the piece is of the correct color
                Piece piece = board.getPiece(fromRow, fromCol);
                if (isWhiteTurn ? !piece.getColor().equals("white") : !piece.getColor().equals("black")) {
                    System.out.println("Illegal move, try again ([DELETE LATER] Reason: wrong color)");
                    continue;
                }
                
                // Check if path is blocked
                if (board.isPathBlocked(fromRow, fromCol, toRow, toCol)) {
                    System.out.println("Illegal move, try again ([DELETE LATER] Reason: path blocked)");
                    continue;
                }

                // Check if the move is valid
                if (!piece.isValidMove(fromRow, fromCol, toRow, toCol)) {
                    System.out.println("Illegal move, try again ([DELETE LATER] Reason: invalid move)");
                    continue;
                }

                board.movePiece(fromRow, fromCol, toRow, toCol);

                String turn = isWhiteTurn ? "white" : "black";

                String opColor = !isWhiteTurn ? "white" : "black";
                if (board.isCheckmate(opColor)){
                    System.out.println("Checkmate : " + turn +"s wins!");
                    break;
                }

                if (board.isCheck(turn)){
                    System.out.println("Illegal move, try again : your king is under attack");
                    board.movePiece(toRow,toCol,fromRow,fromCol);
                    continue;
                }



            }

            System.out.println();

            board.printBoard();
            isWhiteTurn = !isWhiteTurn;
        }
    }
}
