/** @file level.h"
 *  @author Zhengyang Qi
 *  @brief Contains a Level class
 *
 * I wrote this file because I wanted to record the current level of the player
 *
 */
#ifndef LEVEL_H
#define LEVEL_H


#include<QGraphicsTextItem>

/** Class Level
   @brief class to keep track the level of the pleyer
   */
class Level : public QGraphicsTextItem{
public:
    // Constructor for Life object
    Level (QGraphicsItem *parent = 0);

    //default destructor
    ~Level(){}

    // Fuctions to change the lives
    void increase();

};






#endif // LEVEL_H
