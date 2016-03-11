/** @file Player.cpp
 *  @brief Contains the implementation for the Player class.
 *
 * Implements the slots of the Player class using objects.
 */
#include<player.h>
#include<QKeyEvent>
#include<QGraphicsScene>
#include<QTimer>
#include<iostream>
#include<gameboard.h>
#include"smallfishleft.h"
#include"bigfishleft.h"
#include"sharkleft.h"
#include"smallfishright.h"
#include"bigfishright.h"
#include"sharkright.h"
#include"bomb.h"
#include"heart.h"

extern GameBoard * board;

/**
 * Constructor for Player object
 * @param parent is the QGraphicItem
 */
Player::Player(QGraphicsItem* parent) : QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/Images/SmallWhaleRight.png"));
}



/**
  Fuction to let the user to using keyboard to control the object;
  @ param event is the pointer of the KeyPressEvent
*/
void Player::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Left){
        if(pos().x()>0){
            setPos(x()-15,y());
            if(board->score->point<20){setPixmap(QPixmap(":/Images/SmallWhaleleft.png"));}
            if(board->score->point>=20){setPixmap(QPixmap(":/Images/whaleleft.png"));}
        }
    }
    else if (event->key()==Qt::Key_Right){
        if(pos().x()+150<800){
                setPos(x()+15,y());
                 if(board->score->point<20){setPixmap(QPixmap(":/Images/SmallWhaleRight.png"));}
                  if(board->score->point>=20){setPixmap(QPixmap(":/Images/fish4.png"));}
                }
    }
    else if (event->key()==Qt::Key_Up){
        if(pos().y()>0){
                setPos(x(),y()-15);
                if(board->score->point<20){setPixmap(QPixmap(":/Images/SmallWhaleleft.png"));}
                if(board->score->point>=20){setPixmap(QPixmap(":/Images/whaleleft.png"));}
        }
    }
    else if (event->key()==Qt::Key_Down){
        if(pos().y()+100<450){
                setPos(x(),y()+15);
                if(board->score->point<20){setPixmap(QPixmap(":/Images/SmallWhaleleft.png"));}
                if(board->score->point>=20){setPixmap(QPixmap(":/Images/whaleleft.png"));}
        }
    }
}

/** Left small fish appear*/
void Player::LeftSamllFishAppear()
{
SmallFishLeft* smallleft = new SmallFishLeft();
scene()->addItem(smallleft);
}

/** Right small fish appear*/
void Player::RightSmallFishAppear()
{
    SmallFishRight* smallright = new SmallFishRight();
    scene()->addItem(smallright);
}

/** Left big fish appear*/
void Player::LeftBigFishAppear()
{
BigFishLeft* bigleft = new BigFishLeft();
scene()->addItem(bigleft);
}

/** Right big fish appear*/
void Player::RightBigFishAppear()
{
BigFishRight* bigRight = new BigFishRight();
scene()->addItem(bigRight);
}

/** Left shark appear*/
void Player::LeftSharkAppear()
{
 SharkLeft* LeftShark = new SharkLeft();
 scene()->addItem(LeftShark);
}

/** Right shark appear*/
void Player::RightSharkAppear()
{
 SharkRight* RightShark = new SharkRight();
 scene()->addItem(RightShark);
}

/** Bomb appear*/
void Player::BombDrop()
{
    Bomb* bomb = new Bomb();
    scene()->addItem(bomb);
}

/** Heart appear*/
void Player::HeartDrop()
{
    Heart* heart = new Heart();
    scene()->addItem(heart);
}



