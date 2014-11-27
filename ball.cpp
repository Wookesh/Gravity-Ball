#include "ball.h"
#include <QDebug>
#include <QGraphicsScene>

Ball::Ball(QGraphicsItem *parent) : QGraphicsObject(parent)
{
    initBall();
}

void Ball::initBall()
{
    if (!acc_.isActive()) {
        acc_.start();
    }
    speed_ = QPointF(0.0, 0.0);
}

void Ball::updateSpeed()
{
    speed_ = QPointF(speed_.x() + acc_.reading()->x() * (10.0 / Frames), speed_.y() + acc_.reading()->y() * (10.0 / Frames));
}

void Ball::move()
{
    QPointF v = QPointF(-(speed_.x() * (10.0 / Frames) + acc_.reading()->x() * (1.0 / Frames) * (10.0 / Frames) / 2),
                        speed_.y() * (10.0 / Frames) + acc_.reading()->y() * (1.0 / Frames) * (10.0 / Frames) / 2);

    if (collidingItems().size() == 0) {
        moveBy(v.x(), v.y());
        updateSpeed();
    } else {
        emit collision();
    }
}

QRectF Ball::boundingRect() const
{
   return QRectF(-15, -15, 30, 30);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::green);
    painter->drawEllipse(boundingRect());

}

void Ball::restart()
{
    setPos(QPointF(0.0, 0.0));
    speed_ = QPointF(0.0, 0.0);
}

