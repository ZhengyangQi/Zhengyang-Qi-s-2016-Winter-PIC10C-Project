/** @file life.h"
 *  @author Zhengyang Qi
 *  @brief Contains a Life class
 *
 * I wrote this file because I wanted to record the remaining lives of the player
 *
 */
#ifndef LIFE_H
#define LIFE_H


#include<QGraphicsTextItem>


/** Class Life
   @brief class to keep track the remaining lives of the pleyer
   */
class Life : public QGraphicsTextItem{
public:
    // Constructor for Life object
    Life (QGraphicsItem *parent = 0);

    //default destructor
    ~Life(){}

    // Fuctions to change the lives
    void increase();
    void decrease();
    //public parameter
    int health;

};







#endif // LIFE_H
