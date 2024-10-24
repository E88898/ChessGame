#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Chessboard.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(600, 600);

    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
    layout->setAlignment(Qt::AlignCenter);
    Chessboard* game = new Chessboard(this);
    layout->addWidget(game);
}

MainWindow::~MainWindow()
{
    delete ui;
}
