#include "Bishop.h"
#include <QtMath>

Bishop::Bishop(Color color, int x, int y) : Pieces{color,x,y}   {};

QVector<std::pair<int,int>> Bishop::canMove(const std::vector<std::vector<std::pair<QPushButton*,Pieces*>>>& squares) const  {
    int x = Pieces::getCoordinates().first, y = Pieces::getCoordinates().second;
    QVector<std::pair<int,int>> v;

    int j = y - 1, k = y + 1;
    for(int i = x - 1; i >= 0; --i) {
        if(j >= 0) {
            if(squares[i][j].second->getColor() == Color::None) {
                v.push_back({i,j});
            } else if (this->getColor() != squares[i][j].second->getColor()){
                v.push_back({i,j});
                j = -1;
            } else {
                j = -1;
            }
        }
        if(k < 8) {
            if(squares[i][k].second->getColor() == Color::None) {
                v.push_back({i,k});
            } else if (this->getColor() != squares[i][k].second->getColor()){
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
            if(squares[i][j].second->getColor() == Color::None) {
                v.push_back({i,j});
            } else if (this->getColor() != squares[i][j].second->getColor()){
                v.push_back({i,j});
                j = -1;
            } else {
                j = -1;
            }
        }
        if(k < 8) {
            if(squares[i][k].second->getColor() == Color::None) {
                v.push_back({i,k});
            } else if (this->getColor() != squares[i][k].second->getColor()){
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

QIcon Bishop::returnIcon() {
    if(this->getColor() == Color::White) {
        return QIcon(":/Icons1/icons/white-bishop.png");
    }
    return QIcon(":/Icons1/icons/black-bishop.png");
};

Bishop* Bishop::clone(Color color, int x, int y) {
    return new Bishop(color,x, y);
}
