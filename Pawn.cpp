#include "Pawn.h"
#include <cstdlib>

Pawn::Pawn(Color color, int x, int y) : Pieces{color,x,y } {}

QVector<std::pair<int,int>> Pawn::canMove() const  {
    int x = Pieces::getCoordinates().first, y = Pieces::getCoordinates().second;
    QVector<std::pair<int,int>> v;

    if(Pieces::getColor() == Color::Black) {

        if(x == 1) {
            if(Chessboard::figures[x+2][y]->getCoordinates().first == -1) {
                v.push_back({x+2,y});
            }
        }
        if(y - 1 >= 0) {
            if(Chessboard::figures[x+1][y - 1]->getColor() == Color::White) {
                v.push_back({x + 1,y - 1});
            }
        }
        if(y + 1 < 8 ) {
            if(Chessboard::figures[x+1][y + 1]->getColor() == Color::White) {
                v.push_back({x + 1,y + 1});
            }
        }

        if(Chessboard::figures[x + 1][y]->getCoordinates().first == - 1) {
            v.push_back({x + 1, y});
        }

    }

    if(Pieces::getColor() == Color::White) {

        if(x == 6) {
            if(Chessboard::figures[x-2][y]->getCoordinates().first == -1) {
                v.push_back({x-2,y});
            }
        }
        if(y - 1 >= 0) {
            if(Chessboard::figures[x-1][y - 1]->getColor() == Color::Black) {
                v.push_back({x - 1,y - 1});
            }
        }
        if(y + 1 < 8 ) {
            if(Chessboard::figures[x-1][y + 1]->getColor() == Color::Black) {
                v.push_back({x - 1,y + 1});
            }
        }

        if(Chessboard::figures[x - 1][y]->getCoordinates().first == - 1) {
            v.push_back({x - 1, y});
        }

    }


    return v;
}
