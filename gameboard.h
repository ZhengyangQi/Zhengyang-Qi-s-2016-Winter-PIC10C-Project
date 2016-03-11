/** @file gameboard.h
 *  @author Zhengyang Qi
 *  @brief declaration for the main playing interface of the program
 *
 *  Contains the declarations for the various member functions which get and set the fractions for the program.
 */

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include<QGraphicsView>
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include<QKeyEvent>
#include<QLabel>
#include<QGraphicsScene>
#include<life.h>
#include<QPushButton>
#include"score.h"
#include "player.h"
#include "button.h"
#include"level.h"

/** Class GameBoard
 * @brief The GameBoard class as the main play interface
 */
class GameBoard : public QGraphicsView{
public:
    // Constuctor
    GameBoard(QWidget* parent = 0, bool easy = false, bool hard = false);

    // Destructor
    ~GameBoard(){}
    // Fuction to generate the end scene
    void GameOver();

    // public member variable that is a pointer to the scene
    QGraphicsScene* scene;
    // public member variable that is a pointer to player
    Player* myWhale;
    Life* life;
    Score* score;
    Level* level;
    Button* ExitButton;

};

#endif // GAMEBOARD_H
