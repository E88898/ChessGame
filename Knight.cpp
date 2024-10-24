#include "Knight.h"
#include <cstdlib>


Knight::Knight(Color color, int x, int y) : Pieces{color, x, y} {

}

QVector<std::pair<int,int>> Knight::canMove() const  {
    int x = Pieces::getCoordinates().first, y = Pieces::getCoordinates().second;
    QVector<std::pair<int,int>> v;
    int i = x - 2, j = y - 1 ;
    if(i >= 0) {
        if(j >= 0) {
            if(Chessboard::figures[i][j]->getCoordinates().first == -1 ||
               this->getColor() != Chessboard::figures[i][j]->getColor()) {
                v.push_back({i,j});
            }
        }
        j = y + 1;
        if(j < 8) {
            if(Chessboard::figures[i][j]->getCoordinates().first == -1 ||
                this->getColor() != Chessboard::figures[i][j]->getColor()) {
                v.push_back({i,j});
            }
        }
    }
    i = x + 2, j = y - 1;
    if(i < 8) {
        if(j >= 0) {
            if(Chessboard::figures[i][j]->getCoordinates().first == -1 ||
                this->getColor() != Chessboard::figures[i][j]->getColor()) {
                v.push_back({i,j});
            }
        }
        j = y + 1;
        if(j < 8) {
            if(Chessboard::figures[i][j]->getCoordinates().first == -1 ||
                this->getColor() != Chessboard::figures[i][j]->getColor()) {
                v.push_back({i,j});
            }
        }
    }

    j = y - 2, i = x - 1;
    if(j >= 0) {
        if(i >= 0) {
            if(Chessboard::figures[i][j]->getCoordinates().first == -1 ||
                this->getColor() != Chessboard::figures[i][j]->getColor()) {
                v.push_back({i,j});
            }
        }
        i = x + 1;
        if(i < 8) {
            if(Chessboard::figures[i][j]->getCoordinates().first == -1 ||
                this->getColor() != Chessboard::figures[i][j]->getColor()) {
                v.push_back({i,j});
            }
        }
    }
    j = y + 2, i = x - 1;
    if(j < 8) {
        if(i >= 0) {
            if(Chessboard::figures[i][j]->getCoordinates().first == -1 ||
                this->getColor() != Chessboard::figures[i][j]->getColor()) {
                v.push_back({i,j});
            }
        }
        i = x + 1;
        if(i < 8) {
            if(Chessboard::figures[i][j]->getCoordinates().first == -1 ||
                this->getColor() != Chessboard::figures[i][j]->getColor()) {
                v.push_back({i,j});
            }
        }
    }


    return v;
}
