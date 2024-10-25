#ifndef KING_H
#define KING_H

#include "Pieces.h"

class King : public Pieces {
public:
    King(Color color, int x, int y);
    QVector<std::pair<int,int>> canMove(const std::vector<std::vector<std::pair<QPushButton*,Pieces*>>>& squares) const override;
    virtual QIcon returnIcon() override;
    virtual King* clone(Color color, int x, int y) override;
};

#endif // KING_H
