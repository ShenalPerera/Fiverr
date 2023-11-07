#include "game.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"
#include "king.h"
#include "location.h"
    
Game::Game()
{
}

Game::~Game()
{

    for (auto whitePiece : whitePieces)
    {
        delete whitePiece;
    }
    whitePieces.clear();
    for (auto blackPiece : blackPieces)
    {
        delete blackPiece;
    }
    blackPieces.clear();
    
    // Delete players
    delete &player1;
    delete &player2;
}
    
void Game::initialize()
{
    Piece* piece;
    King* kingPiece;
    Location* location;
    

    whitePieces = *(new set<Piece*>);
    blackPieces = *(new set<Piece*>);

    piece = new Queen(true);
    location = ChessBoard::getBoard()->getLocationAt(3, 0);
    location->setOccupier(piece);
    piece->setLocation(location);
    whitePieces.insert(piece);
    piece = new Queen(false);
    location = ChessBoard::getBoard()->getLocationAt(3, 7);
    location->setOccupier(piece);
    piece->setLocation(location);
    blackPieces.insert(piece);

    piece = new Bishop(true);
    location = ChessBoard::getBoard()->getLocationAt(2, 0);
    location->setOccupier(piece);
    piece->setLocation(location);
    whitePieces.insert(piece);
    piece = new Bishop(false);
    location = ChessBoard::getBoard()->getLocationAt(2, 7);
    location->setOccupier(piece);
    piece->setLocation(location);
    blackPieces.insert(piece);
    piece = new Bishop(true);
    location = ChessBoard::getBoard()->getLocationAt(5, 0);
    location->setOccupier(piece);
    piece->setLocation(location);
    whitePieces.insert(piece);
    piece = new Bishop(false);
    location = ChessBoard::getBoard()->getLocationAt(5, 7);
    location->setOccupier(piece);
    piece->setLocation(location);
    blackPieces.insert(piece);

    piece = new Knight(true);
    location = ChessBoard::getBoard()->getLocationAt(1, 0);
    location->setOccupier(piece);
    piece->setLocation(location);
    whitePieces.insert(piece);
    piece = new Knight(false);
    location = ChessBoard::getBoard()->getLocationAt(1, 7);
    location->setOccupier(piece);
    piece->setLocation(location);
    blackPieces.insert(piece);
    piece = new Knight(true);
    location = ChessBoard::getBoard()->getLocationAt(6, 0);
    location->setOccupier(piece);
    piece->setLocation(location);
    whitePieces.insert(piece);
    piece = new Knight(false);
    location = ChessBoard::getBoard()->getLocationAt(6, 7);
    location->setOccupier(piece);
    piece->setLocation(location);
    blackPieces.insert(piece);

    piece = new Rook(true);
    location = ChessBoard::getBoard()->getLocationAt(0, 0);
    location->setOccupier(piece);
    piece->setLocation(location);
    whitePieces.insert(piece);
    piece = new Rook(false);
    location = ChessBoard::getBoard()->getLocationAt(0, 7);
    location->setOccupier(piece);
    piece->setLocation(location);
    blackPieces.insert(piece);
    piece = new Rook(true);
    location = ChessBoard::getBoard()->getLocationAt(7, 0);
    location->setOccupier(piece);
    piece->setLocation(location);
    whitePieces.insert(piece);
    piece = new Rook(false);
    location = ChessBoard::getBoard()->getLocationAt(7, 7);
    location->setOccupier(piece);
    piece->setLocation(location);
    blackPieces.insert(piece);
    
    for (int i = 0; i < 8; i++)
    {
        piece = new Pawn(true);
        location = ChessBoard::getBoard()->getLocationAt(i, 1);
        location->setOccupier(piece);
        piece->setLocation(location);
        whitePieces.insert(piece);
        piece = new Pawn(false);
        location = ChessBoard::getBoard()->getLocationAt(i, 6);
        location->setOccupier(piece);
        piece->setLocation(location);
        blackPieces.insert(piece);
    }


    kingPiece = new King(true);
    location = ChessBoard::getBoard()->getLocationAt(4, 0);
    location->setOccupier(kingPiece);
    kingPiece->setLocation(location);
    whitePieces.insert(kingPiece);
    

    player1 = new Player("White", true, *kingPiece, whitePieces);


    kingPiece = new King(false);
    location = ChessBoard::getBoard()->getLocationAt(4, 7);
    location->setOccupier(kingPiece);
    kingPiece->setLocation(location);
    blackPieces.insert(kingPiece);

    player2 = new Player("Black", false, *kingPiece, blackPieces);
    
    nextPlayer = player2;
}
    
Player* Game::getNextPlayer()
{
    nextPlayer = opponentOf(*nextPlayer);
    return nextPlayer;
}
    
Player* Game::opponentOf(Player& player)
{
    Player* opponent;
    
    if(player.getName() == player1->getName())
    {
        opponent = player2;
    }
    else 
    {
        opponent = player1;
    }

    return opponent;
}

Player* Game::player1 = nullptr;
Player* Game::player2 = nullptr;
Player* Game::nextPlayer = nullptr;
set<Piece*> Game::whitePieces;
set<Piece*> Game::blackPieces;