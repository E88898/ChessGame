#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QWidget>

class QPushButton;
class QGridLayout;
class Pieces;
// es em
class Chessboard : public QWidget {
public:
    Chessboard(QWidget* parent);
    ~Chessboard();
    void printBoard();
    Pieces* createPiece(int row, int col, QPushButton* button);
    static QVector<QVector<Pieces*>> figures;
    void whereToMove(QVector<std::pair<int,int>>& coordinates);
signals:
    void onBordClicked(int row, int column);
private:
    void clickedButton();
    std::vector<std::vector<std::pair<QPushButton*,Pieces*>>> squares;
    QGridLayout* gridLayout;
};

#endif // CHESSBOARD_H
