/** @file sharkLeft.h"
 *  @author Zhengyang Qi
 *  @brief Contains a SharkLeft class
 *
 * I wrote this file because I wanted to make a  create Sharks to
 * move from left
 *
 */
#ifndef SHARKLEFT_H
#define SHARKLEFT_H


#include<QGraphicsPixmapItem>
#include<QObject>
#include<QPixMap>
#include<QGraphicsItem>
#include<QMediaPlayer>

/** Class SharkLeft
 * @brief The SharkLeft class
 * Creating Shark from the left
 */
class SharkLeft : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    // Constructor
    SharkLeft(QGraphicsItem *parent =0);
    // Destructor
    ~SharkLeft(){}
    //sound
    QMediaPlayer * hurtsound;
public slots:
   // moving of the fish
    void swim();

};


#endif // SHARKLEFT_H
