#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scene.h"
#include "view.h"
#include <QPushButton>
#include <ball.h>

class MainWindow : public QWidget {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *);
private :

    Ball *ball;
    QPushButton *newGameButton;
    Scene *scene;
    View *view;

};

#endif // MAINWINDOW_H
