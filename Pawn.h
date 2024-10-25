#ifndef PAWN_H
#define PAWN_H
#include "Pieces.h"

class Pawn : public Pieces {
public:
    Pawn(Color color, int x, int y);
    QVector<std::pair<int,int>> canMove(const std::vector<std::vector<std::pair<QPushButton*,Pieces*>>>& squares) const override;
    virtual QIcon returnIcon() override;
    virtual Pawn* clone(Color color, int x, int y) override;
};
#endif // PAWN_H
