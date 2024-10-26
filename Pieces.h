#ifndef PIECES_H
#define PIECES_H

#include "qcontainerfwd.h"
#include "Chessboard.h"


class Pieces {
public:
    enum class Color {White, Black, None};
    Pieces(Color color, int x, int y ): color{color} {
        data.first = x;
        data.second = y;
    };
    virtual ~Pieces() {};
    virtual QVector<std::pair<int,int>> canMove(const std::vector<std::vector<std::pair<QPushButton*,Pieces*>>>& squares) const = 0;
    virtual bool isPromotable() { return 0; };
    Color getColor() const { return color; }
    std::pair<int,int> getCoordinates() const { return data; }
    virtual Pieces* clone(Color color, int x, int y) = 0;
    virtual QIcon returnIcon() = 0;
private:
    Color color;
    std::pair<int,int> data;
};

#endif // PIECES_H
