/** @file SmallFishRight.cpp
 *  @brief Contains the implementation for the SmallFishRight class.
 *
 * Implements the slots of the SmallFishRight class using objects.
 */
#include "smallfishright.h"
#include<QTimer>
#include<QGraphicsScene>
#include<stdlib.h>
#include<QTime>
#include<Qlist>
#include<typeinfo>
#include "player.h"
#include"gameboard.h"

extern GameBoard * board;

/** Constructor of small fish from the right
 * @brief SmallFishRight
 * @param parent is a QGraphicsItem pointer
 */
SmallFishRight::SmallFishRight(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/Images/fish1.png"));

    eatsound = new QMediaPlayer();
    eatsound->setMedia(QUrl("qrc:/Sounds/eat.wav"));
    int random_number = rand()%450;
    setPos(810,random_number);

    // fish start to come out
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(swim()));

    timer->start(50);
}

/** Fucntion to let the small fish from the right move
 * @brief SmallFishRight::swim
 */
void SmallFishRight::swim()
{
 setPos(x()-10,y());
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

   if(pos().x()<0){
       scene()->removeItem(this);
       delete this;
   }

}
