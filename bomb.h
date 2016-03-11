/** @file bomb.h"
 *  @author Zhengyang Qi
 *  @brief Contains a Bomb class
 *
 * I wrote this file because I wanted to make a BigFishRight create big fish object to
 * move from right
 *
 */

#ifndef BOMB_H
#define BOMB_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QPixMap>
#include<QGraphicsItem>
#include<QMediaPlayer>

/** Class Bomb
 * @brief The Bomb class
 * Creating Bomb and functions of its behavior such as drop and explode
 */
class Bomb : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    // Constructor
    Bomb(QGraphicsItem *parent =0);
    // Destructor
    ~Bomb(){}
    //sound
    QMediaPlayer * hurtsound;
public slots:
   // drop a bomb
    void drop();

};




#endif // BOMB_H
