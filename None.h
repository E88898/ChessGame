#ifndef NONE_H
#define NONE_H
#include "Pieces.h"

class None : public Pieces {
public:
    None(Color color, int x, int y) : Pieces(color,x,y) {};
    QVector<std::pair<int,int>> canMove() const override { return {}; };
};
#endif // NONE_H
