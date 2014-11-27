#ifndef BALL_H
#define BALL_H

#include <QGraphicsObject>
#include <QAccelerometer>
#include <QPainter>
#include <QTimer>
#include <QPointF>

class Ball : public QGraphicsObject {
    Q_OBJECT
public:
    Ball(QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private :
    QAccelerometer acc_;
    QPointF speed_;

    static const int Frames = 40;

    void initBall();
    void updateSpeed();
public slots:
    void restart();
    void move();

signals :
    void collision();

};

#endif
