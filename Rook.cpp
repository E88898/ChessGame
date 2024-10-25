#include "Rook.h"

Rook::Rook(Color color, int x, int y) : Pieces(color,x, y) {};

QVector<std::pair<int,int>> Rook::canMove(const std::vector<std::vector<std::pair<QPushButton*,Pieces*>>>& squares) const  {
    int x = Pieces::getCoordinates().first, y = Pieces::getCoordinates().second;
    QVector<std::pair<int,int>> v;
    for(int i = x - 1; i >= 0; --i) { // up
        if(squares[i][y].second->getColor() == Color::None) {
            v.push_back({i,y});
            continue;
        }
        if(this->getColor() != squares[i][y].second->getColor()) {
            v.push_back({i,y});
        }
        break;
    }
    for(int i = x + 1; i < 8; ++i) { // down
        if(squares[i][y].second->getColor() == Color::None) {
            v.push_back({i,y});
            continue;
        }
        if(this->getColor() != squares[i][y].second->getColor()) {
            v.push_back({i,y});
        }
        break;
    }
    for(int j = y - 1; j >= 0; --j) { // left
        if(squares[x][j].second->getColor() == Color::None) {
            v.push_back({x,j});
            continue;
        }
        if(this->getColor() != squares[x][j].second->getColor()) {
            v.push_back({x,j});
        }
        break;
    }
    for(int j = y + 1; j < 8; ++j) { // right
        if(squares[x][j].second->getColor() == Color::None) {
            v.push_back({x,j});
            continue;
        }
        if(this->getColor() != squares[x][j].second->getColor()) {
            v.push_back({x,j});   
        }
        break;
    }

    return v;
}

QIcon Rook::returnIcon() {
    if(this->getColor() == Color::White) {
        return QIcon(":/Icons1/icons/white-rook.png");
    }
    return QIcon(":/Icons1/icons/black-rook.png");
};

Rook* Rook::clone(Color color, int x, int y) {
    return new Rook(color,x, y);
}
