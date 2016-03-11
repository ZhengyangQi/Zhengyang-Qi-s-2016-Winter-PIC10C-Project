/** @file Score.cpp
 *  @brief Contains the implementation for the Score class.
 *
 * Implements the slots of the Score class using objects.
 */
#include"score.h"
#include <QFont>
#include"level.h"
#include"gameboard.h"


extern GameBoard * board;

/** Constructor for the score*/
Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    point=0;

    //draw text
    setPlainText(QString("Score: ")+QString::number(point));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("Comic Sans MS", 15));
}

/** Function to increase the score*/
void Score::increase()
{
    point++;
    //draw text
    setPlainText(QString("Score: ")+QString::number(point));
    if(board->score->point>19){board->level->increase();}
}

/** Function to increase the score by five*/
void Score::increaseByFive()
{
    point+=5;
    setPlainText(QString("Score: ")+QString::number(point));
     if(board->score->point>19){board->level->increase();}
}

/** Function to reture the score*/
int Score::getScore()
{
    return point;
}
