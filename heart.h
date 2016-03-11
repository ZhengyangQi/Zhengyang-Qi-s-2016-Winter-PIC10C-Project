/** @file heart.h"
 *  @author Zhengyang Qi
 *  @brief Contains a Heart class
 *
 * I wrote this file because I wanted to make a heart object drop down to increase health
 *
 */
#ifndef HEART_H
#define HEART_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QPixMap>
#include<QGraphicsItem>
#include<QMediaPlayer>

/** Class Heart
 * @brief The Heart class
 * Creating Heart and its behavior fucntions
 */
class Heart : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    // Constructor
    Heart(QGraphicsItem *parent =0);
    // Destructor
    ~Heart(){}
    // sound
    QMediaPlayer * eatsound;
public slots:
   // drop a heart
    void drop();

};






#endif // HEART_H
