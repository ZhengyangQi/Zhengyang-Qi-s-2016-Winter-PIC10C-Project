/** @file bigfishleft.h"
 *  @author Zhengyang Qi
 *  @brief Contains a BigFishLeft class
 *
 * I wrote this file because I wanted to make a BigFishLeft create big fish object to
 * move from left
 *
 */

#ifndef BIGFISHLEFT_H
#define BIGFISHLEFT_H


#include<QGraphicsPixmapItem>
#include<QObject>
#include<QPixMap>
#include<QGraphicsItem>
#include<QMediaPlayer>

/** Class BigFishLeft
 * @brief The BigFishLeft class
 * Creating big fish from the left
 */
class BigFishLeft : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    // Constructor
    BigFishLeft(QGraphicsItem *parent =0);
    // Destructor
    ~BigFishLeft(){}
    // sounds
    QMediaPlayer * eatsound;
    QMediaPlayer * hurtsound;
public slots:
   // moving of the fish
    void swim();

};


#endif // BIGFISHLEFT_H
