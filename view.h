#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include "ball.h"

class View : public QGraphicsView {
    Q_OBJECT
public:
    explicit View(QGraphicsScene *scene, QWidget *parent = 0);
    void addBall(Ball *ball);
protected:
    void resizeEvent(QResizeEvent *event);
private :
    Ball *ball_;
public slots:
    void updateBall();
};

#endif // VIEW_H
