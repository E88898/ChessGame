#ifndef ROOK_H
#define ROOK_H
#include "Pieces.h"

class Rook : public Pieces{
public:
    Rook(Color color, int x, int y);
    QVector<std::pair<int,int>> canMove(const std::vector<std::vector<std::pair<QPushButton*,Pieces*>>>& squares) const override;
    virtual QIcon returnIcon() override;
    virtual Rook* clone(Color color, int x, int y) override;
};

#endif // ROCK_H
