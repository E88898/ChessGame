#include "Pawn.h"
#include <cstdlib>

Pawn::Pawn(Color color, int x, int y) : Pieces{color,x,y } {}

QVector<std::pair<int,int>> Pawn::canMove(const std::vector<std::vector<std::pair<QPushButton*,Pieces*>>>& squares) const  {
    int x = Pieces::getCoordinates().first, y = Pieces::getCoordinates().second;
    QVector<std::pair<int,int>> v;

    if(this->getColor() == Color::Black) {

        if(x == 1) {

            if(squares[x + 2][y].second->getColor() == Color::None) {
                v.push_back({x+2,y});
            }
        }
        if(y - 1 >= 0) {
            if(squares[x + 1][y - 1].second->getColor() == Color::White) {
                v.push_back({x + 1,y - 1});
            }
        }
        if(y + 1 < 8 ) {
            if(squares[x + 1][y + 1].second->getColor() == Color::White) {
                v.push_back({x + 1,y + 1});
            }
        }

        if(squares[x + 1][y].second->getColor() == Color::None) {
            v.push_back({x + 1, y});
        }

    }

    if(this->getColor() == Color::White) {

        if(x == 6) {
            if(squares[x - 2][y].second->getColor() == Color::None) {
                v.push_back({x-2,y});
            }
        }
        if(y - 1 >= 0) {
            if(squares[x - 1][y - 1].second->getColor() == Color::Black) {
                v.push_back({x - 1, y - 1});
            }
        }
        if(y + 1 < 8 ) {
            if(squares[x - 1][y + 2].second->getColor() ==  Color::Black) {
                v.push_back({x - 1,y + 1});
            }
        }

        if(squares[x - 1][y].second->getColor() == Color::None) {
            v.push_back({x - 1, y});
        }

    }


    return v;
}

QIcon Pawn::returnIcon() {
    if(this->getColor() == Color::White) {
        return QIcon(":/Icons1/icons/white-pawn.png");
    }
    return QIcon(":/Icons1/icons/black-pawn.png");
};

Pawn* Pawn::clone(Color color, int x, int y) {
    return new Pawn(color,x, y);
}
