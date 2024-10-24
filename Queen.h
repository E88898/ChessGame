#ifndef QUEEN_H
#define QUEEN_H
#include "Pieces.h"

class Queen :  public Pieces {
public:
    Queen(Color color, int x, int y);
    QVector<std::pair<int,int>> canMove() const override;

};

#endif // QUEEN_H
