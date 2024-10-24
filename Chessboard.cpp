#include "Chessboard.h"
#include <QColor>
#include <QDebug>
#include <QGridLayout>
#include <QPushButton>

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
    //const int boardSize = 8;
    // for (int row = 0; row < boardSize; ++row) {
    //     for (int col = 0; col < boardSize; ++col) {
    //         delete squares[row][col];
    //     }
    // }
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
            if ((row + col) % 2 == 0) {
                button->setStyleSheet(R"(QPushButton {
                                                    border: 0;
                                                    background-color: #f0d9b5;
                                                    }
                                                    QPushButton::hover{
                                                        background-color: #005000;
                                                        })");
            } else {
                button->setStyleSheet(R"(QPushButton{
                                                        border: 0;
                                                        background-color: #b58863;
                                                    }
                                                    QPushButton::hover{
                                                        background-color: #005000;
                                                        })");
            }

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
    QVector<std::pair<int,int>> v;
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            if(clicked == squares[i][j].first) {
                v = squares[i][j].second->canMove();
                break;
            }
        }
    }
    whereToMove(v);

}

void Chessboard::whereToMove(QVector<std::pair<int,int>>& coordinates) {
    for(int i = 0; i < coordinates.size(); ++i) {
        qDebug() << coordinates[i].first << ' ' << coordinates[i].second;
        squares[coordinates[i].first][coordinates[i].second].first->setStyleSheet((R"(QPushButton {
                                                    border: 0;
                                                    background-color: #005000;
                                                    }
                                                    )")
        );
    }
}
