#include "Knight.h"
#include <cstdlib>


Knight::Knight(Color color, int x, int y) : Pieces{color, x, y} {

}

QVector<std::pair<int,int>> Knight::canMove(const std::vector<std::vector<std::pair<QPushButton*,Pieces*>>>& squares) const  {
    int x = Pieces::getCoordinates().first, y = Pieces::getCoordinates().second;
    QVector<std::pair<int,int>> v;
    int i = x - 2, j = y - 1 ;
    if(i >= 0) {
        if(j >= 0) {
            if(squares[i][j].second->getColor() != this ->getColor()) {
                v.push_back({i,j});
            }
        }
        j = y + 1;
        if(j < 8) {
            if(squares[i][j].second->getColor() != this ->getColor()) {
                v.push_back({i,j});
            }
        }
    }
    i = x + 2, j = y - 1;
    if(i < 8) {
        if(j >= 0) {
            if(squares[i][j].second->getColor() != this ->getColor()) {
                v.push_back({i,j});
            }
        }
        j = y + 1;
        if(j < 8) {
            if(squares[i][j].second->getColor() != this ->getColor()) {
                v.push_back({i,j});
            }
        }
    }

    j = y - 2, i = x - 1;
    if(j >= 0) {
        if(i >= 0) {
            if(squares[i][j].second->getColor() != this ->getColor()) {
                v.push_back({i,j});
            }
        }
        i = x + 1;
        if(i < 8) {
            if(squares[i][j].second->getColor() != this ->getColor()) {
                v.push_back({i,j});
            }
        }
    }
    j = y + 2, i = x - 1;
    if(j < 8) {
        if(i >= 0) {
            if(squares[i][j].second->getColor() != this ->getColor()) {
                v.push_back({i,j});
            }
        }
        i = x + 1;
        if(i < 8) {
            if(squares[i][j].second->getColor() != this ->getColor()) {
                v.push_back({i,j});
            }
        }
    }


    return v;
}

QIcon Knight::returnIcon() {
    if(this->getColor() == Color::White) {
        return QIcon(":/Icons1/icons/white-knight.png");
    }
    return QIcon(":/Icons1/icons/black-knight.png");
};

Knight* Knight::clone(Color color, int x, int y) {
    return new Knight(color,x, y);
}
