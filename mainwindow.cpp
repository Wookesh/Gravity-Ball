#include "mainwindow.h"
#include "ball.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QtAndroid>
#include <QAndroidJniObject>
#include <QWidget>
#include <QDebug>
#include "timecounter.h"
#include "pointcounter.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{

    //LITTLE HACK FOR KEEPING SCREEN ON
    QAndroidJniObject activity = QtAndroid::androidActivity();
    if (activity.isValid()) {
        QAndroidJniObject window = activity.callObjectMethod("getWindow", "()Landroid/view/Window;");
        if (window.isValid()) {
            window.callMethod<void>("setFlags", "(II)V", 128, 128);
        }
    }

    QPalette pal = palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/background.png")));
    setPalette(pal);

    ball = new Ball();
    scene = new Scene();
    scene->addBall(ball);
    scene->setSceneRect(-200, -200, 400, 200000);
    connect(ball, &Ball::collision, scene, &Scene::gameOver);

    view = new View(scene, this);
    view->addBall(ball);
    view->centerOn(ball);
    connect(&scene->timer(), &QTimer::timeout, view, &View::updateBall);

    TimeCounter *timeCounter = new TimeCounter(this);
    connect(scene, &Scene::passed, timeCounter, &TimeCounter::addTime);
    connect(timeCounter, &TimeCounter::timesUp, scene, &Scene::gameOver);
    connect(ball, &Ball::collision, timeCounter, &TimeCounter::stop);

    PointCounter *pointCounter = new PointCounter(this);
    connect(scene, &Scene::passed, pointCounter, &PointCounter::addPoint);

    newGameButton = new QPushButton("Restart");
    connect(newGameButton, &QPushButton::clicked, ball, &Ball::restart);
    connect(newGameButton, &QPushButton::clicked, scene, &Scene::resetScene);
    connect(newGameButton, &QPushButton::clicked, timeCounter, &TimeCounter::start);
    connect(newGameButton, &QPushButton::clicked, pointCounter, &PointCounter::resetPoints);

    QVBoxLayout *layout = new QVBoxLayout();
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget(timeCounter);
    hLayout->addWidget(pointCounter);
    layout->addLayout(hLayout);
    layout->addWidget(view);
    layout->addWidget(newGameButton);

    setLayout(layout);
}

MainWindow::~MainWindow()
{

}

void MainWindow::resizeEvent(QResizeEvent *)
{
    qreal s = (width() - 40) / scene->width();
    view->resetTransform();
    view->scale(s, s);
}
