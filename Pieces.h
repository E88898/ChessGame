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
    virtual QVector<std::pair<int,int>> canMove() const = 0;
    Color getColor() const { return color; }
    std::pair<int,int> getCoordinates() const { return data; }

private:
    Color color;
    std::pair<int,int> data;
};

#endif // PIECES_H
