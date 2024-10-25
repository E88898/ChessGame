#ifndef QUEEN_H
#define QUEEN_H
#include "Pieces.h"

class Queen :  public Pieces {
public:
    Queen(Color color, int x, int y);
    QVector<std::pair<int,int>> canMove(const std::vector<std::vector<std::pair<QPushButton*,Pieces*>>>& squares) const override;
    virtual QIcon returnIcon() override;
    virtual Queen* clone(Color color, int x, int y) override;
};

#endif // QUEEN_H
