/** @file bigfishright.h"
 *  @author Zhengyang Qi
 *  @brief Contains a BigFishRight class
 *
 * I wrote this file because I wanted to make a BigFishRight create big fish object to
 * move from right
 *
 */

#ifndef BIGFISHRIGHT_H
#define BIGFISHRIGHT_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QPixMap>
#include<QGraphicsItem>
#include<QMediaPlayer>

/** Class BigFishRight
 * @brief The BigFishRight class
 * Creating big fish from the Right
 */
class BigFishRight : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    // Constructor
    BigFishRight(QGraphicsItem *parent =0);
    // Destructor
    ~BigFishRight(){}
    // sounds
    QMediaPlayer * eatsound;
    QMediaPlayer * hurtsound;
public slots:
   // moving of the fish
    void swim();

};





#endif // BIGFISHRIGHT_H
