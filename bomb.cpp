/** @file Bomb.cpp
 *  @brief Contains the implementation for the Bomb class.
 *
 * Implements the slots of the Bomb class using objects.
 */

#include<QTimer>
#include<QGraphicsScene>
#include<stdlib.h>
#include<QTime>
#include<Qlist>
#include<typeinfo>
#include"player.h"
#include"gameboard.h"
#include"bomb.h"

extern GameBoard* board;

/** Constructor of Bomb from the left
 * @brief Bomb
 * @param parent is a QGraphicsItem pointer
 */
Bomb::Bomb(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/Images/bomb.png"));

    hurtsound = new QMediaPlayer();
    hurtsound->setMedia(QUrl("qrc:/Sounds/hurt.wav"));


    //Create seed for the timer
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    int random_num = qrand()%800;
    setPos(random_num,0);

    // fish start to come out
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(drop()));

    timer->start(75);
}

/** Fucntion to let the Bomb*/
void Bomb::drop()
{
    setPos(x(),y()+20);

      // If the player run into a bomb
        QList<QGraphicsItem*> run_into_bomb = collidingItems();
        for(int i = 0, n = run_into_bomb.size();i<n;++i){
            if(typeid(*run_into_bomb[i])==typeid(Player)){
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

    if(pos().y()>450){
        scene()->removeItem(this);
        delete this;
        return;
    }
}
