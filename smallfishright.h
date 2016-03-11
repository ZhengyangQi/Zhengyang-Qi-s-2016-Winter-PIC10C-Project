/** @file smallfishright.h"
 *  @author Zhengyang Qi
 *  @brief Contains a SmallFishRight class
 *
 * I wrote this file because I wanted to make a  create small fish to
 * move from right
 *
 */
#ifndef SMALLFISHRIGHT_H
#define SMALLFISHRIGHT_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QPixMap>
#include<QGraphicsItem>
#include"gameboard.h"
#include<QMediaPlayer>

/** Class SmallFishRight
 * @brief The SmallFishRight class
 * Creating samll fish from the left
 */
class SmallFishRight : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    // Constructor
    SmallFishRight(QGraphicsItem *parent =0);
    // Destructor
    ~SmallFishRight(){}
    // sounds
    QMediaPlayer * eatsound;
friend class Player;
public slots:
   // moving of the fish
    void swim();

};
#endif // SMALLFISHRIGHT_H
