/** @file BigFishLeft.cpp
 *  @brief Contains the implementation for the BigFishLeft class.
 *
 * Implements the slots of the BigFishLeft class using objects.
 */

#include<Bigfishleft.h>
#include<QTimer>
#include<QGraphicsScene>
#include<stdlib.h>
#include<player.h>
#include<QTime>
#include<Qlist>
#include<typeinfo>
#include"gameboard.h"

extern GameBoard* board;

/** Constructor of Big fish from the left
 * @brief BigFishLeft
 * @param parent is a QGraphicsItem pointer
 */
BigFishLeft::BigFishLeft(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/Images/bigleft.png"));
    eatsound = new QMediaPlayer();
    eatsound->setMedia(QUrl("qrc:/Sounds/eat.wav"));

    hurtsound = new QMediaPlayer();
    hurtsound->setMedia(QUrl("qrc:/Sounds/hurt.wav"));

    int random_number = rand()%450;
    setPos(0,random_number);

    // fish start to come out
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(swim()));
    timer->start(50);

}

/** Fucntion to let the Big fish from the left move
 * @brief BigFishLeft::swim
 */
void BigFishLeft::swim(){
    setPos(x()+20,y());
    if(board->score->point<20){
      // If the player run into a big fish before grown up
        QList<QGraphicsItem*> eat_Big_fish = collidingItems();
        for(int i = 0, n = eat_Big_fish.size();i<n;++i){
            if(typeid(*eat_Big_fish[i])==typeid(Player)){
                board->life->decrease();
                if(hurtsound->state() == QMediaPlayer::PlayingState){
                    hurtsound->setPosition(0);
                }
                else if(hurtsound->state() == QMediaPlayer::StoppedState){
                hurtsound->play();
                }
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    }
if(board->score->point>=20){
  // If the player catch the fish, it got eaten
    QList<QGraphicsItem*> eat_Big_fish = collidingItems();
    for(int i = 0, n = eat_Big_fish.size();i<n;++i){
        if(typeid(*eat_Big_fish[i])==typeid(Player)){
            board->score->increaseByFive();
            if(typeid(*eat_Big_fish[i])==typeid(Player)){
                board->score->increaseByFive();
                if(eatsound->state() == QMediaPlayer::PlayingState){
                    eatsound->setPosition(0);
                }
                else if(eatsound->state() == QMediaPlayer::StoppedState){
                eatsound->play();
                }
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
}
    if(pos().x()>800){
        scene()->removeItem(this);
        delete this;
        return;
    }
}

}
