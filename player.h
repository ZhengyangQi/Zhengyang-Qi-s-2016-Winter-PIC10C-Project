/** @file Player.h"
 *  @author Zhengyang Qi
 *  @brief Contains a player class
 *
 * I wrote this file because I wanted to create an object for user to control
 */

#ifndef PLAYER_H
#define PLAYER_H

#include<QOBject>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>

/** Class player
 * @brief The Player class
 * Inheritance from QObject and QGraphicsPixmapItem that will create an object for user to control
 */

class Player: public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT
 public:
    // Constructor for Player object
    Player(QGraphicsItem* parent = 0);

     // Destructor
    ~Player(){ }

    //Fuction to let the user to using keyboard to control the object;
    void keyPressEvent(QKeyEvent* event);

public slots:

    // Left fish appear
    void LeftSamllFishAppear();
    void LeftBigFishAppear();
    void LeftSharkAppear();

    // Right fish appear
    void RightSmallFishAppear();
    void RightBigFishAppear();
    void RightSharkAppear();

    // Drop dowm
    void BombDrop();
    void HeartDrop();
private:
    // Pointer to the whale image
    QPixmap* whale_image;
friend class smallfishleft;


};



#endif // PLAYER_H
