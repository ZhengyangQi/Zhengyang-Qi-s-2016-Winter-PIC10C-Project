/** @file smallfishleft.h"
 *  @author Zhengyang Qi
 *  @brief Contains a SmallFishLeft class
 *
 * I wrote this file because I wanted to make a  create small fish to
 * move from left
 *
 */
#ifndef SMALLFISHLEFT_H
#define SMALLFISHLEFT_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QPixMap>
#include<QGraphicsItem>
#include"gameboard.h"
#include<QMediaPlayer>

/** Class SmallFishLeft
 * @brief The SmallFishLeft class
 * Creating samll fish from the left
 */
class SmallFishLeft : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    // Constructor
    SmallFishLeft(QGraphicsItem *parent =0);
    // Destructor
    ~SmallFishLeft(){}
    // sounds
    QMediaPlayer * eatsound;

friend class Player;

public slots:
   // moving of the fish
    void swim();

};

#endif // SMALLFISHLEFT_H
