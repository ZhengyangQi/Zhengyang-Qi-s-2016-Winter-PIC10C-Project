/** @file Life.cpp
 *  @brief Contains the implementation for the Life class.
 *
 * Implements the slots of the Heart class using objects.
 */
#include"Life.h"
#include<QFont>
#include"gameboard.h"

extern GameBoard* board;

/** Constructor for the level*/
Life::Life(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    health = 5 ;

    setPlainText(QString("Whale Remaining: ")+QString::number(health));
    setFont(QFont("Comic Sans MS", 15));
    setDefaultTextColor(Qt::red);
}

/** Function to increase the life*/
void Life::increase(){
    health++;
    setPlainText(QString("Whale Remaining: ")+QString::number(health));

}

/** Function to decrease the life*/
void Life::decrease(){
    if (health<1){
    board->GameOver();
    }
    health--;
    setPlainText(QString("Whale Remaining: ")+QString::number(health));

}
