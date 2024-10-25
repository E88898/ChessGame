#ifndef PAWN_H
#define PAWN_H
#include "Pieces.h"

class Pawn : public Pieces {
public:
    Pawn(Color color, int x, int y);
    QVector<std::pair<int,int>> canMove() const override;
};
#endif // PAWN_H
