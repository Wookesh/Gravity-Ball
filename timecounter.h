#ifndef TIMECOUNTER_H
#define TIMECOUNTER_H

#include <QLCDNumber>
#include <QTime>
#include <QTimer>

class TimeCounter : public QLCDNumber {
    Q_OBJECT
public:
    explicit TimeCounter(QWidget *parent = 0);
private :
    QTime time_;
    QTimer *timer_;
public slots:
    void start();
    void stop();
    void updateTime();
    void addTime();
signals :
    void timesUp();
};

#endif // TIMECOUNTER_H
