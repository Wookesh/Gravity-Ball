#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include"ball.h"

class Scene : public QGraphicsScene {
    Q_OBJECT
public:
    explicit Scene(QObject *parent = 0);
    void initTimer();
    void addBall(Ball * ball);
    QTimer &timer();
private :
    QPen sidePen;
    QPen wallPen;
    static constexpr qreal distance_ = 300.0;
    qreal nextWallToPass_;
    qreal lastWallToPass_;
    QTimer timer_;
    Ball *ball_;
    void addWall();
public slots:
    void resetScene();
    void checkForUpdate();
    void gameOver();
signals :
    void passed();

};

#endif // SCENE_H
