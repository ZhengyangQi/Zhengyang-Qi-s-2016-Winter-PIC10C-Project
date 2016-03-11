/** @file sharkright.h"
 *  @author Zhengyang Qi
 *  @brief Contains a SharkRight class
 *
 * I wrote this file because I wanted to make a  create Sharks to
 * move from right
 *
 */
#ifndef SHARKRIGHT_H
#define SHARKRIGHT_H


#include<QGraphicsPixmapItem>
#include<QObject>
#include<QPixMap>
#include<QGraphicsItem>
#include<QMediaPlayer>

/** Class SharkRight
 * @brief The SharkRight class
 * Creating Shark from the Right
 */
class SharkRight : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    // Constructor
    SharkRight(QGraphicsItem *parent =0);
    // Destructor
    ~SharkRight(){}
    //sound
    QMediaPlayer * hurtsound;
public slots:
   // moving of the fish
    void swim();

};

#endif // SHARKRIGHT_H
