/** @file button.h"
 *  @author Zhengyang Qi
 *  @brief Contains a Button class
 *
 * I wrote this file because I wanted to make a customeriazed pushButton to reveive click signal
 *
 */

#ifndef BUTTON_H
#define BUTTON_H


#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

/** class Button
 *  @brief class to customize the pushbutton
 *   make a customeriazed pushButton to reveive click signal
*/
class Button:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    // constructors
    Button(QString name, QGraphicsItem* parent=NULL);

    //KeyPressEvent
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:
    void clicked();

private:
    // private text for the text on button
    QGraphicsTextItem* text;
};

#endif // BUTTON_H
