/** @file main.cpp
 * @author:Zhengyang Qi
 * ID:204296544
 * MAR 9th 2016
 * PIC 10C Winter 2016
 * Program for hw10 program.
 * Qt final project of a graphic user interface game, Feed My Whale. User control the whale character to eat small fish and doger the large fish.
 * The goal for the game is the get as many as possible points
*/

#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
