#include "King.h"
#include <cstdlib>

King::King(Color color,int x, int y) : Pieces{color, x, y} {}

QVector<std::pair<int,int>> King::canMove() const  {
    int x = Pieces::getCoordinates().first, y = Pieces::getCoordinates().second;
    QVector<std::pair<int,int>> v;

    if(x - 1 >= 0) {
        if(Chessboard::figures[x - 1][y]->getColor() != this->getColor()) {
            v.push_back({x - 1, y});
        }
        if(y - 1 >= 0) {
            if(Chessboard::figures[x - 1][y - 1]->getColor() != this->getColor()) {
                v.push_back({x - 1, y - 1});
            }
        }
        if(y + 1 < 8) {
            if(Chessboard::figures[x - 1][y + 1]->getColor() != this->getColor()) {
                v.push_back({x - 1, y + 1});
            }
        }
    }

    if(y - 1 >= 0) {
        if(Chessboard::figures[x][y - 1]->getColor() != this->getColor()) {
            v.push_back({x, y - 1});
        }
    }
    if(y + 1 < 8) {
        if(Chessboard::figures[x][y + 1]->getColor() != this->getColor()) {
            v.push_back({x, y + 1});
        }
    }


    if(x + 1 < 8) {
        if(Chessboard::figures[x + 1][y]->getColor() != this->getColor()) {
            v.push_back({x + 1, y});
        }
        if(y - 1 >= 0) {
            if(Chessboard::figures[x + 1][y - 1]->getColor() != this->getColor()) {
                v.push_back({x + 1, y - 1});
            }
        }
        if(y + 1 < 8) {
            if(Chessboard::figures[x + 1][y + 1]->getColor() != this->getColor()) {
                v.push_back({x + 1, y + 1});
            }
        }
    }


    return v;
}
