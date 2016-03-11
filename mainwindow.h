/** @file mainwindow.h
 *  @brief declaration for the main window of the program
 *
 *  Contains the declarations for the various member functions which get and set the fractions for the program.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "player.h"
#include "gameboard.h"

namespace Ui {
class MainWindow;
}

/** class MainWindow
    @brief the main inferface that takes all the widget
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void move_the_whale();
    void move_big_fish();

    //Slot to activate the easy mode
    void easy_game_begin();
    //Slot to activate the hard mode
    void hard_game_begin();
private slots:
    void on_pushButton_10_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;

    Player* myWhale;
};

#endif // MAINWINDOW_H
