#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QWidget>

class QPushButton;
class QGridLayout;
class Pieces;
class Pawn;
class None;

class Chessboard : public QWidget {
public:
    Chessboard(QWidget* parent);
    ~Chessboard();
    void printBoard();
    Pieces* createPiece(int row, int col, QPushButton* button);
    static QVector<QVector<Pieces*>> figures;
    void whereToMove();
signals:
    void onBordClicked(int row, int column);
    void pawnPromotion(Pawn* pawn, int row, int column);
public slots:
    Pieces* openDialog(Pawn* pawn);
private:
    void undoWhereToMove();
    void clickedButton();
    std::vector<std::vector<std::pair<QPushButton*,Pieces*>>> squares;
    QGridLayout* gridLayout;
    Pieces* activePiece = nullptr;
    QVector<std::pair<int,int>> activeCoordinates;

};

#endif // CHESSBOARD_H
