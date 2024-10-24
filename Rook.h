#ifndef ROOK_H
#define ROOK_H
#include "Pieces.h"

class Rook : public Pieces{
public:
    Rook(Color color, int x, int y);
    QVector<std::pair<int,int>> canMove() const override;
};

#endif // ROCK_H
