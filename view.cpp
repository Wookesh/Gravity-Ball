#include "view.h"

View::View(QGraphicsScene *scene, QWidget *parent) : QGraphicsView(scene, parent)
{
    QGraphicsView::setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QGraphicsView::setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void View::addBall(Ball *ball)
{
    ball_ = ball;
}

void View::updateBall()
{
    centerOn(ball_);
}

void View::resizeEvent(QResizeEvent *event)
{

}
