#ifndef BISHOP_H
#define BISHOP_H
#include "Pieces.h"


class Bishop : public Pieces {
public:
    Bishop(Color color, int x, int y);
    QVector<std::pair<int,int>> canMove() const override;

};

#endif // BISHOP_H
