/** @file score.h"
 *  @author Zhengyang Qi
 *  @brief Contains a Score class
 *
 * I wrote this file because I wanted to record the current score of the player
 *
 */
#ifndef SCORE_H
#define SCORE_H


#include<QGraphicsTextItem>


/** class Score
   @brief class to keep track the current score of the pleyer
   */
class Score:public QGraphicsTextItem{
public:
    // Constructor
    Score(QGraphicsItem*parent=0);
    // Fucntions to increase the score
    void increase();
    void increaseByFive();
    // Fuctoin to return the current score
    int getScore();
    // Public parameter of the current point
    int point;


};

#endif // SCORE_H
