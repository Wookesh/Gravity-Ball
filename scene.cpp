#include "scene.h"
#include <QDebug>
#include <QDateTime>

Scene::Scene(QObject *parent) : QGraphicsScene(parent), ball_(nullptr)
{
    initTimer();
    qsrand(QDateTime::currentDateTime().toTime_t());
    connect(&timer_, &QTimer::timeout, this, &Scene::checkForUpdate);
    sidePen.setWidth(5);
    wallPen.setWidth(10);
    wallPen.setColor(Qt::darkMagenta);
    resetScene();
    setBackgroundBrush(QColor(210, 220, 255));
}

void Scene::resetScene()
{
    for (QGraphicsItem *item : items())
        removeItem(item);

    if (ball_ != nullptr)
        QGraphicsScene::addItem(ball_);

    nextWallToPass_ = 400.0;
    lastWallToPass_ = 400.0;
    addLine(-200, -200, -200, lastWallToPass_, sidePen);
    addLine( 200, -200,  200, lastWallToPass_, sidePen);
    addLine( 200, -200, -200,            -200, sidePen);
    addWall();
    addWall();
}

void Scene::initTimer()
{
    if (!timer_.isActive()) {
        timer_.start(25);
    }

}

void Scene::gameOver()
{
    QGraphicsTextItem *gameOver = addText("GameOver", QFont("Times", 42));
    gameOver->setPos(QPointF(-200, ball_->pos().y()));
}


QTimer &Scene::timer()
{
    return timer_;
}

void Scene::addBall(Ball *ball)
{
    ball_ = ball;
    QGraphicsScene::addItem(ball);
    connect(&timer_, &QTimer::timeout, ball_, &Ball::move);
}

void Scene::addWall()
{
    static bool leftSite = true;
    static int penWidth = wallPen.widthF() / 2;
    int wallLength = qrand() % 200 + 100 - penWidth;
    addLine(leftSite ? penWidth - 200 : 200 - penWidth, lastWallToPass_, leftSite ? wallLength - 200 : 200 - wallLength, lastWallToPass_, wallPen);

    addLine(-200, lastWallToPass_, -200, lastWallToPass_ + distance_, sidePen);
    addLine( 200, lastWallToPass_,  200, lastWallToPass_ + distance_, sidePen);
    lastWallToPass_ += distance_;
    leftSite = !leftSite;
}

void Scene::checkForUpdate()
{
    if (ball_->pos().y() > nextWallToPass_) {
        nextWallToPass_ += distance_;
        addWall();
        emit passed();
    }
}
