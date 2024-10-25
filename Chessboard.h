#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QWidget>

class QPushButton;
class QGridLayout;
class Pieces;

class Chessboard : public QWidget {
public:
    Chessboard(QWidget* parent);
    ~Chessboard();
    void printBoard();
    Pieces* createPiece(int row, int col, QPushButton* button);
    void whereToMove(QVector<std::pair<int,int>>& coordinates);
    void moving(int row, int col);
signals:
    void onBordClicked(int row, int column);
private:
    void clickedButton();
    std::vector<std::vector<std::pair<QPushButton*,Pieces*>>> squares;
    QVector<std::pair<int,int>> whereCanMove;
    QGridLayout* gridLayout;
};

#endif // CHESSBOARD_H
