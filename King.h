#ifndef KING_H
#define KING_H

#include "Pieces.h"

class King : public Pieces {
public:
    King(Color color, int x, int y);
    QVector<std::pair<int,int>> canMove() const override;
};

#endif // KING_H
