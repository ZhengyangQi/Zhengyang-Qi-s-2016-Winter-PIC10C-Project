/** @file Heart.cpp
 *  @brief Contains the implementation for the Heart class.
 *
 * Implements the slots of the Heart class using objects.
 */
#include<QTimer>
#include<QGraphicsScene>
#include<stdlib.h>
#include<QTime>
#include<Qlist>
#include<typeinfo>
#include"player.h"
#include"gameboard.h"
#include"heart.h"

extern GameBoard* board;

/** Constructor of Heart
 * @brief Heart
 * @param parent is a QGraphicsItem pointer
 */
Heart::Heart(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/Images/heart.png"));

    eatsound = new QMediaPlayer();
    eatsound->setMedia(QUrl("qrc:/Sounds/eat.wav"));

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

/** Fucntion to let the Heart*/
void Heart::drop()
{
    setPos(x(),y()+20);

      // If the player run into a Heart
        QList<QGraphicsItem*> run_into_Heart = collidingItems();
        for(int i = 0, n = run_into_Heart.size();i<n;++i){
            if(typeid(*run_into_Heart[i])==typeid(Player)){
                board->life->increase();
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

    if(pos().y()>450){
        scene()->removeItem(this);
        delete this;
        return;
    }
}
