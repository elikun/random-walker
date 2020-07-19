#ifndef DOT_CLASS_H
#define DOT_CLASS_H

#include <QAbstractAnimation>
#include <QApplication>
#include <QFont>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QPen>
#include <QPropertyAnimation>
#include <QRect>
#include <QString>
#include <QThread>

#include <iostream>
#include <chrono>
#include <thread>

#include "../EnvironmentConstants.hpp"

class Dot : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
    Q_PROPERTY(QRectF rect READ rect WRITE setRect)

    public:
        Dot();
        ~Dot();

    public slots:
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();

    private:
        QPropertyAnimation *animation;
};

#endif