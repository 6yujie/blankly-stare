#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Card.h"
#include "CardDeck.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CardDeck deck1(1);
    CardDeck deck2(0);

    Card cd(joker, red);
    Card cd1(ace, diamond);
    deck1.give_one_card(deck2, cd);
    deck1.give_one_card(deck2, cd1);
    deck1.give_one_card(deck1, cd);

    qDebug()<<"stop";
}

MainWindow::~MainWindow()
{
    delete ui;
}
