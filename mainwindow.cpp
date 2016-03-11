/** @file mainwindow.cpp
 *  @brief Contains the implementation for the MainWindow class.
 *
 * Implements the slots of the MainWindow class using objects of Players.
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameboard.h"
#include"player.h"

GameBoard * board;

/** Function to setup ui*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
// destructor
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::move_the_whale()
{
    ui->label_3->move(260,150);
}

void MainWindow::move_big_fish()
{
    ui->label_5->move(60,260);
}


/** Slot to activate the easy mode
 *
 */
void MainWindow::easy_game_begin()
{
    board = new GameBoard(this,true,false);
    this->setCentralWidget(board);

    this->setFixedSize(800,450);
    board->show();

    QObject::connect(board->ExitButton,SIGNAL(clicked()),this,SLOT(close()));
}

/** Slot to activate the hard mode
 *
 */
void MainWindow::hard_game_begin()
{
    board = new GameBoard(this,false,true);
    this->setCentralWidget(board);
    this->setFixedSize(800,450);
    board->show();
QObject::connect(board->ExitButton,SIGNAL(clicked()),this,SLOT(close()));
}


// button slots
void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
