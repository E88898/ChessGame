#ifndef KNIGHT_H
#define KNIGHT_H

#include "Pieces.h"
class Knight : public Pieces {
public:
    Knight(Color color, int x, int y);
    QVector<std::pair<int,int>> canMove() const override;
};

#endif // KNIGHT_H
