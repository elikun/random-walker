#include "Dot.hpp"

Dot::Dot()
{
}

Dot::~Dot()
{
}

void Dot::moveUp()
{
    QRect startPos = this->rect().toRect();
    QRect endPos(startPos.left(), startPos.top() - MOVEMENT_STEP, startPos.width(), startPos.height());
    this->setRect(endPos);
    animation = new QPropertyAnimation(this, "rect");
    animation->setDuration(MOVEMENT_DURATION_MS);
    animation->setStartValue(startPos);
    animation->setEndValue(endPos);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void Dot::moveDown()
{
    QRect startPos = this->rect().toRect();
    QRect endPos(startPos.left(), startPos.top() + MOVEMENT_STEP, startPos.width(), startPos.height());
    this->setRect(endPos);
    animation = new QPropertyAnimation(this, "rect");
    animation->setDuration(MOVEMENT_DURATION_MS);
    animation->setStartValue(startPos);
    animation->setEndValue(endPos);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void Dot::moveLeft()
{
    QRect startPos = this->rect().toRect();
    QRect endPos(startPos.left() - MOVEMENT_STEP, startPos.top(), startPos.width(), startPos.height());
    this->setRect(endPos);
    animation = new QPropertyAnimation(this, "rect");
    animation->setDuration(MOVEMENT_DURATION_MS);
    animation->setStartValue(startPos);
    animation->setEndValue(endPos);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void Dot::moveRight()
{
    QRect startPos = this->rect().toRect();
    QRect endPos(startPos.left() + MOVEMENT_STEP, startPos.top(), startPos.width(), startPos.height());
    this->setRect(endPos);
    animation = new QPropertyAnimation(this, "rect");
    animation->setDuration(MOVEMENT_DURATION_MS);
    animation->setStartValue(startPos);
    animation->setEndValue(endPos);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}