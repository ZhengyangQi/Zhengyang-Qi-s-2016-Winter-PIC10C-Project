/** @file SmallFishLeft.cpp
 *  @brief Contains the implementation for the SmallFishLeft class.
 *
 * Implements the slots of the SmallFishLeft class using objects.
 */
#include "smallfishleft.h"
#include<QTimer>
#include<QGraphicsScene>
#include<stdlib.h>
#include<QTime>
#include<Qlist>
#include<typeinfo>
#include "player.h"
#include"gameboard.h"

extern GameBoard * board;

/** Constructor of small fish from the left
 * @brief SmallFishLeft
 * @param parent is a QGraphicsItem pointer
 */
SmallFishLeft::SmallFishLeft(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/Images/smallleft.png"));

    eatsound = new QMediaPlayer();
    eatsound->setMedia(QUrl("qrc:/Sounds/eat.wav"));

    int random_number = rand()%450;
    setPos(0,random_number);

    // fish start to come out
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(swim()));

    timer->start(50);
}

/** Fucntion to let the small fish from the left move
 * @brief SmallFishLeft::swim
 */
void SmallFishLeft::swim()
{
 setPos(x()+10,y());
    QList<QGraphicsItem*> eat_small_fish= collidingItems();
    for(int i=0, n=eat_small_fish.size();i<n;i++){
        if(typeid(*(eat_small_fish[i]))==typeid(Player)){
            //increase score
            board->score->increase();
            if(eatsound->state() == QMediaPlayer::PlayingState){
                eatsound->setPosition(0);
            }
            else if(eatsound->state() == QMediaPlayer::StoppedState){
            eatsound->play();
            }
            //remove both
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    //move up

   if(pos().x()>800){
       scene()->removeItem(this);
       delete this;
   }

}
