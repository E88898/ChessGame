#include "Bishop.h"
#include <QtMath>

Bishop::Bishop(Color color, int x, int y) : Pieces{color,x,y}   {};

QVector<std::pair<int,int>> Bishop::canMove() const  {
    int x = Pieces::getCoordinates().first, y = Pieces::getCoordinates().second;
    QVector<std::pair<int,int>> v;

    int j = y - 1, k = y + 1;
    for(int i = x - 1; i >= 0; --i) {
        if(j >= 0) {
            if(Chessboard::figures[i][j]->getCoordinates().first == -1) {
                v.push_back({i,j});
            } else if (this->getColor() != Chessboard::figures[i][j]->getColor()){
                v.push_back({i,j});
                j = -1;
            } else {
                j = -1;
            }
        }
        if(k < 8) {
            if(Chessboard::figures[i][k]->getCoordinates().first == -1) {
                v.push_back({i,k});
            } else if(this->getColor() != Chessboard::figures[i][k]->getColor()) {
                v.push_back({i,k});
                k = 8;
            } else {
                k = 8;
            }
        }
        --j;
        ++k;
    }

    j = y - 1, k = y + 1;
    for(int i = x + 1; i < 8; ++i) {
        if(j >= 0) {
            if(Chessboard::figures[i][j]->getCoordinates().first == -1) {
                v.push_back({i,j});
            } else if (this->getColor() != Chessboard::figures[i][j]->getColor()){
                v.push_back({i,j});
                j = -1;
            } else {
                j = -1;
            }
        }
        if(k < 8) {
            if(Chessboard::figures[i][k]->getCoordinates().first == -1) {
                v.push_back({i,k});
            } else if(this->getColor() != Chessboard::figures[i][k]->getColor()) {
                v.push_back({i,k});
                k = 8;
            } else {
                k = 8;
            }
        }
        --j;
        ++k;
    }

    return v;
}
