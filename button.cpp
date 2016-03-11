/** @file Button.cpp
 *  @brief Contains the implementation for the Button class.
 *
 * Implements the slots of the Bomb class using objects.
 */

#include "Button.h"
#include <QGraphicsTextItem>
#include <QBrush>

/** Constructor with two parameters
 @param name is the input string that will be the text on the button
 @param parent is a default QGraphicsItem pointer
 */
Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw the rect
    setRect(0,0,151,30);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::lightGray);
    setBrush(brush);

    // draw the text
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    // allow responding to hover events
    setAcceptHoverEvents(true);
}

/** Function to take key press event*/
void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}



