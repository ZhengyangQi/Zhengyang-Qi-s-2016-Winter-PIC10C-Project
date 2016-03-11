/** @file Gamboard.cpp
 *  @brief Contains the implementation for the GameBoard class.
 *
 * Implements the slots of the GameBoard class using objects.
 */
#include"gameboard.h"
#include"player.h"
#include<QPixmap>
#include<QKeyEvent>
#include<QGraphicsScene>
#include<QTimer>
#include <QMediaPlayer>
#include"button.h"


/**
 * @brief GameBoard Constructor
 * @param parent is the QWidget pointor
 * @param easy is a bool value default to be fasle
 * @param hard is a bool value default to be fasle
 */
GameBoard::GameBoard(QWidget *parent, bool easy, bool hard)
{
    //construct a scene
scene = new QGraphicsScene(this);
scene->setSceneRect(0,0,800,450);
setBackgroundBrush(QBrush(QImage(":/Images/back.jpg")));
setScene(scene);
   // set ScrollBarPolicy
setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
setFixedSize(800,450);

//create the player
myWhale = new Player();
myWhale -> setPos(400,225);
myWhale -> setFlag(QGraphicsItem::ItemIsFocusable);
myWhale ->setFocus();
scene->addItem(myWhale);

//create score
score = new Score();
score->setPos(40,10);
scene->addItem(score);

//create button
ExitButton = new Button(QString("Quit"));
ExitButton->setPos(600,10);
scene->addItem(ExitButton);
connect(ExitButton,SIGNAL(clicked()),this,SLOT(close()));

//initialize life
life = new Life();
life->setPos(170,10);
scene->addItem(life);

//initialize level
level = new Level();
level->setPos(400,10);
scene->addItem(level);

//add background music
QMediaPlayer* music = new QMediaPlayer();
music->setMedia(QUrl("qrc:/Sounds/BackGroudMusic.mp3"));
if(music->state() == QMediaPlayer::PlayingState){
    music->setPosition(0);
}
else if(music->state() == QMediaPlayer::StoppedState){
music->play();
}

// if the easy mode is chosen
if(easy==true){
    // timer to generate small fish
    QTimer* time1 = new QTimer();
    QObject::connect(time1,SIGNAL(timeout()),myWhale,SLOT(LeftSamllFishAppear()));
    time1->start(3000);

    // timer to generate large fish
    QTimer* time2 = new QTimer();
    QObject::connect(time2,SIGNAL(timeout()),myWhale,SLOT(LeftBigFishAppear()));
    time2->start(5000);

    // timer to generate shark
    QTimer* time3 = new QTimer();
    QObject::connect(time3,SIGNAL(timeout()),myWhale,SLOT(LeftSharkAppear()));
    time3->start(12000);

}

// if the hard mode is chosen
if(hard==true){

    // timer to generate small fish
    QTimer* time = new QTimer();
    QObject::connect(time,SIGNAL(timeout()),myWhale,SLOT(LeftSamllFishAppear()));
    time->start(3000);

    // timer to generate small fish
    QTimer* time2 = new QTimer();
    QObject::connect(time2,SIGNAL(timeout()),myWhale,SLOT(RightSmallFishAppear()));
    time2->start(7000);

    // timer to generate large fish
    QTimer* time3 = new QTimer();
    QObject::connect(time3,SIGNAL(timeout()),myWhale,SLOT(LeftBigFishAppear()));
    time3->start(5000);

    // timer to generate large fish
    QTimer* time4 = new QTimer();
    QObject::connect(time4,SIGNAL(timeout()),myWhale,SLOT(RightBigFishAppear()));
    time4->start(10000);

    // timer to generate shark
    QTimer* time5 = new QTimer();
    QObject::connect(time5,SIGNAL(timeout()),myWhale,SLOT(LeftSharkAppear()));
    time5->start(18000);

    // timer to generate shark
    QTimer* time6 = new QTimer();
    QObject::connect(time6,SIGNAL(timeout()),myWhale,SLOT(RightSharkAppear()));
    time6->start(15000);

    // timer to generate bomb
    QTimer* time7 = new QTimer();
    QObject::connect(time7,SIGNAL(timeout()),myWhale,SLOT(BombDrop()));
    time7->start(8000);

    // timer to generate heart
    QTimer* time8 = new QTimer();
    QObject::connect(time8,SIGNAL(timeout()),myWhale,SLOT(HeartDrop()));
    time8->start(10000);

}

show();
}

/** Fucntion to call end scene whtn life is leas than zero*/
void GameBoard::GameOver()
{
    // store the final score
int final = score->getScore();
QString message = "Your Final Score is: "+ QString::number(final);

// create new scene
scene = new QGraphicsScene(this);
scene->setSceneRect(0,0,800,450);
setScene(scene);

// end message
QGraphicsTextItem* printScore = new QGraphicsTextItem();
printScore->setPlainText(message);
printScore->setPos(80,100);
printScore-> setDefaultTextColor(Qt::yellow);
printScore->  setFont(QFont("Comic Sans MS", 15));
scene->addItem(printScore);


// create quit button
Button* end = new Button(QString("Quit"));
end->setPos(600,10);
scene->addItem(end);

connect(end,SIGNAL(clicked()),this->parent(),SLOT(close()));

}
