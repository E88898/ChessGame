#ifndef BISHOP_H
#define BISHOP_H
#include "Pieces.h"


class Bishop : public Pieces {
public:
    Bishop(Color color, int x, int y);
    QVector<std::pair<int,int>> canMove(const std::vector<std::vector<std::pair<QPushButton*,Pieces*>>>& squares) const override;
    virtual QIcon returnIcon() override;
    virtual Bishop* clone(Color color,int x, int y) override;
};

#endif // BISHOP_H
