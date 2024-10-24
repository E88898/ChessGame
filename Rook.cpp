#include "Rook.h"

Rook::Rook(Color color, int x, int y) : Pieces(color,x, y) {};

QVector<std::pair<int,int>> Rook::canMove() const  {
    int x = Pieces::getCoordinates().first, y = Pieces::getCoordinates().second;
    QVector<std::pair<int,int>> v;
    for(int i = x - 1; i >= 0; --i) { // up
        if(Chessboard::figures[i][y]->getCoordinates().first == -1) {
            v.push_back({i,y});
            continue;
        }
        if(this->getColor() != Chessboard::figures[i][y]->getColor()) {
            v.push_back({i,y});
        }
        break;
    }
    for(int i = x + 1; i < 8; ++i) { // down
        if(Chessboard::figures[i][y]->getCoordinates().first == -1) {
            v.push_back({i,y});
            continue;
        }
        if(this->getColor() != Chessboard::figures[i][y]->getColor()) {
            v.push_back({i,y});
        }
        break;
    }
    for(int j = y - 1; j >= 0; --j) { // left
        if(Chessboard::figures[x][j]->getCoordinates().first == -1) {
            v.push_back({x,j});
            continue;
        }
        if(this->getColor() != Chessboard::figures[x][j]->getColor()) {
            v.push_back({x,j});
        }
        break;
    }
    for(int j = y + 1; j < 8; ++j) { // right
        if(Chessboard::figures[x][j]->getCoordinates().first == -1) {
            v.push_back({x,j});
            continue;
        }
        if(this->getColor() != Chessboard::figures[x][j]->getColor()) {
            v.push_back({x,j});   
        }
        break;
    }

    return v;
}
