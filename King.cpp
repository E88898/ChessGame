#include "King.h"
#include <cstdlib>

King::King(Color color,int x, int y) : Pieces{color, x, y} {}

QVector<std::pair<int,int>> King::canMove(const std::vector<std::vector<std::pair<QPushButton*,Pieces*>>>& squares) const  {
    int x = Pieces::getCoordinates().first, y = Pieces::getCoordinates().second;
    QVector<std::pair<int,int>> v;

    if(x - 1 >= 0) {
        if(squares[x - 1][y].second->getColor() != this->getColor()) {
            v.push_back({x - 1, y});
        }
        if(y - 1 >= 0) {
            if(squares[x - 1][y - 1].second->getColor() != this->getColor()) {
                v.push_back({x - 1, y - 1});
            }
        }
        if(y + 1 < 8) {
            if(squares[x - 1][y + 1].second->getColor() != this->getColor()) {
                v.push_back({x - 1, y + 1});
            }
        }
    }

    if(y - 1 >= 0) {
        if(squares[x][y - 1].second->getColor() != this->getColor()) {
            v.push_back({x, y - 1});
        }
    }
    if(y + 1 < 8) {
        if(squares[x][y + 1].second->getColor() != this->getColor()) {
            v.push_back({x, y + 1});
        }
    }

    if(x + 1 < 8) {
        if(squares[x + 1][y].second->getColor() != this->getColor()) {
            v.push_back({x + 1, y});
        }
        if(y - 1 >= 0) {
            if(squares[x + 1][y - 1].second->getColor() != this->getColor()) {
                v.push_back({x + 1, y - 1});
            }
        }
        if(y + 1 < 8) {
            if(squares[x + 1][y + 1].second->getColor() != this->getColor()) {
                v.push_back({x + 1, y + 1});
            }
        }
    }




    return v;
}

QIcon King::returnIcon() {
    if(this->getColor() == Color::White) {
        return QIcon(":/Icons1/icons/white-king.png");
    }
    return QIcon(":/Icons1/icons/black-king.png");
};

King* King::clone(Color color, int x, int y) {
    return new King(color,x, y);
}
