/** @file SharkRight.cpp
 *  @brief Contains the implementation for the SharkRight class.
 *
 * Implements the slots of the SharkRight class using objects.
 */
#include<sharkright.h>
#include<QTimer>
#include<QGraphicsScene>
#include<stdlib.h>
#include<player.h>
#include<QTime>
#include<Qlist>
#include<typeinfo>
#include"gameboard.h"

extern GameBoard* board;

/** Constructor of sharks from the Right
 * @brief SharkRight
 * @param parent is a QGraphicsItem pointer
 */
SharkRight::SharkRight(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/Images/sharkleft.png"));

    hurtsound = new QMediaPlayer();
    hurtsound->setMedia(QUrl("qrc:/Sounds/hurt.wav"));

    int random_number = rand()%450;
    setPos(810,random_number);
    // fish start to come out
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(swim()));

    timer->start(50);
}

/** Fucntion to let the Big fish from the Right move
 * @brief SharkRight::swim
 */
void SharkRight::swim()
{
    setPos(x()-5,y());

      // If the player run into a shark
        QList<QGraphicsItem*> run_into_shark = collidingItems();
        for(int i = 0, n = run_into_shark.size();i<n;++i){
            if(typeid(*run_into_shark[i])==typeid(Player)){
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

    if(pos().x()<-343){
        scene()->removeItem(this);
        delete this;
        return;
    }
}
