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
    Pieces* ptr;
    if(row == 0 && col == 0) {
        ptr = new Rook(Pieces::Color::Black, row, col);
        button->setIcon(ptr->returnIcon());
        return ptr;
    }
    if(row == 0 && col == 7) {
        ptr = new Rook(Pieces::Color::Black, row, col);;
        button->setIcon(ptr->returnIcon());
        return ptr;
    }

    if(row == 7 && col == 0) {
        ptr = new Rook(Pieces::Color::White, row, col);
        button->setIcon(ptr->returnIcon());
        return ptr;
    }
    if(row == 7 && col == 7) {
        ptr = new Rook(Pieces::Color::White, row, col);
        button->setIcon(ptr->returnIcon());
        return ptr;
    }

    if(row == 0 && col == 1) {
        ptr = new Knight(Pieces::Color::Black, row, col);
        button->setIcon(ptr->returnIcon());
        return ptr;
    }

    if(row == 0 && col == 6) {
        ptr= new Knight(Pieces::Color::Black, row, col);
        button->setIcon(ptr->returnIcon());
        return ptr;
    }

    if(row == 7 && col == 1) {
        ptr =  new Knight(Pieces::Color::White, row, col);
        button->setIcon(ptr->returnIcon());
        return ptr;
    }
    if(row == 7 && col == 6) {
        ptr = new Knight(Pieces::Color::White, row, col);
        button->setIcon(ptr->returnIcon());
        return ptr;
    }

    if(row == 0 && col == 2) {
        ptr = new Bishop(Pieces::Color::Black, row, col);
        button->setIcon(ptr->returnIcon());
        return ptr;
    }
    if(row == 0 && col == 5) {
        ptr = new Bishop(Pieces::Color::Black, row, col);
        button->setIcon(ptr->returnIcon());
        return ptr;
    }

    if(row == 7 && col == 2) {
        ptr = new Bishop(Pieces::Color::White, row, col);
        button->setIcon(ptr->returnIcon());
        return ptr;
    }
    if(row == 7 && col == 5) {
        ptr = new Bishop(Pieces::Color::White, row, col);
        button->setIcon(ptr->returnIcon());
        return ptr;
    }

    if(row == 0 && col == 3) {
        ptr = new Queen(Pieces::Color::Black, row, col);
        button->setIcon(ptr->returnIcon());
        return ptr;
    }
    if(row == 7 && col == 3) {
        ptr = new Queen(Pieces::Color::White, row, col);
        button->setIcon(ptr->returnIcon());
        return ptr;
    }

    if(row == 4 && col == 4) {
        ptr = new Queen(Pieces::Color::Black, row, col);
        button->setIcon(ptr->returnIcon());
        return ptr;
    }

    if(row == 0 && col == 4) {
        ptr = new King(Pieces::Color::Black, row, col);
        button->setIcon(ptr->returnIcon());
        return ptr;
    }

    if(row == 7 && col == 4) {
        ptr = new King(Pieces::Color::White, row, col);
        button->setIcon(ptr->returnIcon());
        return ptr;
    }

    if(row == 1 ) {
        ptr = new Pawn(Pieces::Color::Black, row, col);
        button->setIcon(ptr->returnIcon());
        return ptr;
    }

    if(row == 6 ) {
        ptr = new Pawn(Pieces::Color::White, row, col);
        button->setIcon(ptr->returnIcon());
        return ptr;

    }

    return new None(Pieces::Color::None, -1, -1);
}


void Chessboard::clickedButton() {
    QPushButton* clicked = qobject_cast<QPushButton*>(sender());
    if(whereCanMove.size() == 0) {
        QVector<std::pair<int,int>> v;
        for(int i = 0; i < 8; ++i) {
            for(int j = 0; j < 8; ++j) {
                if(clicked == squares[i][j].first) {
                    v = squares[i][j].second->canMove(squares);
                    v.push_back({i,j});
                    break;
                }
            }
        }
        whereCanMove = v;
        whereToMove(v);
    } else {
        for(int i = 0; i < 8; ++i) {
            for(int j = 0; j < 8; ++j) {
                if(clicked == squares[i][j].first) {
                    moving(i,j);
                }
            }
        }
        whereCanMove.clear();

    }


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


void Chessboard::moving(int i, int j) {
    int last = whereCanMove.size() - 1;
    int x = whereCanMove[last].first, y = whereCanMove[last].second;
    for(int idx = 0; idx < whereCanMove.size() - 1; ++idx) {
        if(i == whereCanMove[idx].first && j == whereCanMove[idx].second) {


            Pieces* ptr = squares[x][y].second->clone(squares[x][y].second->getColor(),i,j);
            delete squares[x][y].second;
            delete squares[i][j].second;
            squares[x][y].second = new None(Pieces::Color::None, -1, -1);
            squares[i][j].second = ptr;
            squares[x][y].first->setIcon(squares[x][y].second->returnIcon());
            squares[i][j].first->setIcon(squares[i][j].second->returnIcon());

        }

    }

}


