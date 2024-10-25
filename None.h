#ifndef NONE_H
#define NONE_H
#include "Pieces.h"

class None : public Pieces {
public:
    None(Color color, int x, int y) : Pieces(color,x,y) {};
    QVector<std::pair<int,int>> canMove(const std::vector<std::vector<std::pair<QPushButton*,Pieces*>>>& squares) const override { return {}; };
    virtual QIcon returnIcon() override {return QIcon();};
    virtual None* clone(Color color, int x, int y) override {return new None(color, x, y);};
};
#endif // NONE_H
