#include "Chessboard.h"
#include <QColor>
#include <QDebug>
#include <QGridLayout>
#include <QPushButton>
#include <QDialog>
#include <QLabel>

#include "Bishop.h"
#include "Knight.h"
#include "None.h"
#include "Pieces.h"
#include "Queen.h"
#include "Rook.h"
#include "Pawn.h"
#include "King.h"


QVector<QVector<Pieces*>> Chessboard::figures(8,QVector<Pieces*>(8));
Chessboard::Chessboard(QWidget* parent) : QWidget(parent), squares(8, std::vector<std::pair<QPushButton*,Pieces*>>(8)) {
    setFixedSize(400, 400);
    gridLayout = new QGridLayout(this);
    printBoard();
}

Chessboard::~Chessboard() {
}

void Chessboard::printBoard() {
    const int boardSize = 8;
    for (int row = 0; row < boardSize; ++row) {
        for (int col = 0; col < boardSize; ++col) {
            QPushButton* button = new QPushButton(this);
            Pieces* piece = createPiece(row,col, button);
            figures[row][col] = piece;
            squares[row][col] = {button,piece};
            connect(button, &QPushButton::clicked, this, &Chessboard::clickedButton);
            button->setFixedSize(50, 50);
            QColor backGroundColor;
            QString baseStyle = R"(QPushButton {
                          border: 1px solid white;
                          background-color: %1;
                      }
                      QPushButton::hover {
                          background-color: #5d5b59;
                      })";

            if ((row + col) % 2 == 0) {
                backGroundColor = "#f0d9b5";
            } else {
                backGroundColor = "#b58863";
            }
            button->setStyleSheet(baseStyle.arg(backGroundColor.name()));
            gridLayout->addWidget(button, row, col);
        }
    }
}



Pieces* Chessboard::createPiece(int row, int col, QPushButton* button) {
    button->setIconSize(QSize(40, 40));
    if(row == 0 && col == 0) {
        button->setIcon(QIcon(":/Icons1/icons/black-rook.png"));
        return new Rook(Pieces::Color::Black, row, col);
    }

    if(row == 0 && col == 7) {
        button->setIcon(QIcon(":/Icons1/icons/black-rook.png"));
        return new Rook(Pieces::Color::Black, row, col);
    }

    if(row == 7 && col == 0) {
        button->setIcon(QIcon(":/Icons1/icons/white-rook.png"));
        return new Rook(Pieces::Color::White, row, col);
    }

    if(row == 7 && col == 7) {
        button->setIcon(QIcon(":/Icons1/icons/white-rook.png"));
        return new Rook(Pieces::Color::White, row, col);
    }

    if(row == 0 && col == 1) {
        button->setIcon(QIcon(":/Icons1/icons/black-knight.png"));
        return new Knight(Pieces::Color::Black, row, col);
    }

    if(row == 0 && col == 6) {
        button->setIcon(QIcon(":/Icons1/icons/black-knight.png"));
        return new Knight(Pieces::Color::Black, row, col);
    }

    if(row == 7 && col == 1) {
        button->setIcon(QIcon(":/Icons1/icons/white-knight.png"));
        return new Knight(Pieces::Color::White, row, col);
    }
    if(row == 7 && col == 6) {
        button->setIcon(QIcon(":/Icons1/icons/white-knight.png"));
        return new Knight(Pieces::Color::White, row, col);
    }

    if(row == 0 && col == 2) {
        button->setIcon(QIcon(":/Icons1/icons/black-bishop.png"));
        return new Bishop(Pieces::Color::Black, row, col);
    }
    if(row == 0 && col == 5) {
        button->setIcon(QIcon(":/Icons1/icons/black-bishop.png"));
        return new Bishop(Pieces::Color::Black, row, col);
    }

    if(row == 7 && col == 2) {
        button->setIcon(QIcon(":/Icons1/icons/white-bishop.png"));
        return new Bishop(Pieces::Color::White, row, col);
    }

    if(row == 7 && col == 5) {
        button->setIcon(QIcon(":/Icons1/icons/white-bishop.png"));
        return new Bishop(Pieces::Color::White, row, col);
    }

    if(row == 0 && col == 3) {
        button->setIcon(QIcon(":/Icons1/icons/black-queen.png"));
        return new Queen(Pieces::Color::Black, row, col);
    }

    if(row == 7 && col == 3) {
        button->setIcon(QIcon(":/Icons1/icons/white-queen.png"));
        return new Queen(Pieces::Color::White, row, col);
    }

    if(row == 4 && col == 4) {
        button->setIcon(QIcon(":/Icons1/icons/white-queen.png"));
        return new Queen(Pieces::Color::White, row, col);
    }

    if(row == 0 && col == 4) {
        button->setIcon(QIcon(":/Icons1/icons/black-king.png"));
        return new King(Pieces::Color::Black, row, col);
    }

    if(row == 7 && col == 4) {
        button->setIcon(QIcon(":/Icons1/icons/white-king.png"));
        return new King(Pieces::Color::White, row, col);
    }

    if(row == 1 ) {
        button->setIcon(QIcon(":/Icons1/icons/black-pawn.png"));
        return new Pawn(Pieces::Color::Black, row, col);
    }

    if(row == 6 ) {
        button->setIcon(QIcon(":/Icons1/icons/white-pawn.png"));
        return new Pawn(Pieces::Color::White, row, col);

    }
    return new None(Pieces::Color::None, -1, -1);
}


void Chessboard::clickedButton() {
    QPushButton* clicked = qobject_cast<QPushButton*>(sender());
  //  connect(clicked, &QPushButton::clicked, this, Chessboard::openDialog(new Pawn(Pieces::Color::White, 0,0)));
    if (activePiece) {
        undoWhereToMove();
    }
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            if(clicked == squares[i][j].first) {
                activeCoordinates = squares[i][j].second->canMove();
                activePiece = squares[i][j].second;
                break;
            }
        }
    }
    whereToMove();
}

void Chessboard::pawnPromotion(Pawn* piece, int row, int col) {
    int currRow = piece->getCoordinates().first;
    int currCol = piece->getCoordinates().second;
    Pieces* newPiece = openDialog(piece);
    figures[row][col] = newPiece;
    squares[row][col].second = newPiece;

    None* none = new None(piece->getColor(),currRow,currCol);
    figures[currRow][currCol] = none;
    squares[currRow][currCol].second = none;
}


void Chessboard::whereToMove() {
    QColor backGroundColor;
    QString baseStyle = R"(QPushButton {
                          border: 1px solid white;
                          background-color: %1;
                      }
                      QPushButton::hover {
                          background-color: #5d5b59;
                      })";
    for(int i = 0; i < activeCoordinates.size(); ++i) {
        qDebug() << activeCoordinates[i].first << ' ' << activeCoordinates[i].second;
        int row = activeCoordinates[i].first;
        int col = activeCoordinates[i].second;
        if ((row + col) % 2 == 0) {
            backGroundColor = "#aeadac";
        } else {
            backGroundColor = "#868482";
        }
        squares[activeCoordinates[i].first][activeCoordinates[i].second].first->setStyleSheet(baseStyle.arg(backGroundColor.name()));
    }
    backGroundColor = "#FDFD96";
    squares[activePiece->getCoordinates().first][activePiece->getCoordinates().second].first->setStyleSheet(baseStyle.arg(backGroundColor.name()));
}


void Chessboard::undoWhereToMove() {
    QColor backGroundColor;
    QString baseStyle = R"(QPushButton {
                          border: 1px solid white;
                          background-color: %1;
                      }
                      QPushButton::hover {
                          background-color: #5d5b59;
                      })";
    int activeRow = activePiece->getCoordinates().first;
    int activeCol = activePiece->getCoordinates().second;
    if ((activeRow + activeCol) % 2 == 0) {
        backGroundColor = "#f0d9b5";
    } else {
        backGroundColor = "#b58863";
    }
    squares[activePiece->getCoordinates().first][activePiece->getCoordinates().second].first->setStyleSheet(baseStyle.arg(backGroundColor.name()));

    for(int i = 0; i < activeCoordinates.size(); ++i) {
        int row = activeCoordinates[i].first;
        int col = activeCoordinates[i].second;
        if ((row + col) % 2 == 0) {
            squares[activeCoordinates[i].first][activeCoordinates[i].second].first->setStyleSheet(R"(
                    QPushButton {
                        border: 1px solid white;
                        background-color: #f0d9b5;
                    }
                    QPushButton::hover{
                    background-color: #5d5b59;
                    })");
        } else {
            squares[activeCoordinates[i].first][activeCoordinates[i].second].first->setStyleSheet(R"(
                    QPushButton {
                        border: 1px solid white;
                        background-color: #b58863;
                    }
                    QPushButton::hover{
                    background-color: #5d5b59;
                    }
        )");
        }
    }
}

Pieces* Chessboard::openDialog(Pawn* pawn) {
    QDialog dialog(this);
    dialog.resize(200,200);
    dialog.setWindowTitle("choose a figure");

    QGridLayout* layout = new QGridLayout(&dialog);
    QLabel* label = new QLabel("Choose a figure", &dialog);
    QPushButton* queenButton = new QPushButton(&dialog);
    queenButton->setIcon(QIcon(":/Icons1/icons/white-queen.png"));
    queenButton->setIconSize(QSize(40,40));
    QPushButton* bishopButton = new QPushButton(&dialog);
    bishopButton->setIcon(QIcon(":/Icons1/icons/white-bishop.png"));
    bishopButton->setIconSize(QSize(40,40));
    QPushButton* rookButton = new QPushButton(&dialog);
    rookButton->setIcon(QIcon(":/Icons1/icons/white-rook.png"));
    rookButton->setIconSize(QSize(40,40));
    QPushButton* knightButton = new QPushButton(&dialog);
    knightButton->setIcon(QIcon(":/Icons1/icons/white-knight.png"));
    knightButton->setIconSize(QSize(40,40));

    Pieces::Color color = pawn->getColor();
    int row = pawn->getCoordinates().first;
    int col = pawn->getCoordinates().second;

    Pieces* acceptedPiece = nullptr;

    connect(queenButton, &QPushButton::clicked, this, [color,row,col,&acceptedPiece,&dialog]() { acceptedPiece = new Queen(color, row, col); dialog.accept(); });
    connect(bishopButton, &QPushButton::clicked, this, [color,row,col,&acceptedPiece,&dialog]() { acceptedPiece = new Bishop(color, row, col); dialog.accept(); });
    connect(knightButton, &QPushButton::clicked, this, [color,row,col,&acceptedPiece,&dialog]() { acceptedPiece = new Knight(color, row, col); dialog.accept(); });
    connect(rookButton, &QPushButton::clicked, this, [color,row,col,&acceptedPiece,&dialog]() { acceptedPiece = new Rook(color, row, col);  dialog.accept(); });

    layout->addWidget(label,0,0);
    layout->addWidget(queenButton,1,0);
    layout->addWidget(bishopButton,1,1);
    layout->addWidget(knightButton,2,0);
    layout->addWidget(rookButton,2,1);

    dialog.exec();
    return acceptedPiece;
}
