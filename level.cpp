/** @file Level.cpp
 *  @brief Contains the implementation for the Level class.
 *
 * Implements the slots of the Level class using objects.
 */
#include"level.h"
#include<QFont>
#include"gameboard.h"
#include"score.h"

extern GameBoard* board;
/** Constructor for the level*/
Level::Level(QGraphicsItem *parent): QGraphicsTextItem(parent)
{

    setPlainText(QString("Level: Weak Whale "));
    setFont(QFont("Comic Sans MS", 15));
    setDefaultTextColor(Qt::green);
}

/** Function to increase the level*/
void Level::increase(){
    setPlainText(QString("Level: Strong Whale! "));

}

