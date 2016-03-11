/** @file SharkLeft.cpp
 *  @brief Contains the implementation for the SharkLeft class.
 *
 * Implements the slots of the SharkLeft class using objects.
 */
#include<Sharkleft.h>
#include<QTimer>
#include<QGraphicsScene>
#include<stdlib.h>
#include<player.h>
#include<QTime>
#include<Qlist>
#include<typeinfo>
#include"gameboard.h"

extern GameBoard* board;

/** Constructor of sharks from the left
 * @brief SharkLeft
 * @param parent is a QGraphicsItem pointer
 */
SharkLeft::SharkLeft(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/Images/fish3.png"));

    hurtsound = new QMediaPlayer();
    hurtsound->setMedia(QUrl("qrc:/Sounds/hurt.wav"));


    int random_number = rand()%450;
    setPos(-343,random_number);

    // fish start to come out
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(swim()));

    timer->start(75);
}

/** Fucntion to let the Big fish from the left move
 * @brief SharkLeft::swim
 */
void SharkLeft::swim()
{
    setPos(x()+5,y());

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

    if(pos().x()>800){
        scene()->removeItem(this);
        delete this;
        return;
    }
}
