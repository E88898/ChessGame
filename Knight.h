#ifndef KNIGHT_H
#define KNIGHT_H

#include "Pieces.h"
class Knight : public Pieces {
public:
    Knight(Color color, int x, int y);
    QVector<std::pair<int,int>> canMove(const std::vector<std::vector<std::pair<QPushButton*,Pieces*>>>& squares) const override;
    virtual QIcon returnIcon() override;
    virtual Knight* clone(Color color, int x, int y) override;
};

#endif // KNIGHT_H
