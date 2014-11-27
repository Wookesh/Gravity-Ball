#include "timecounter.h"

TimeCounter::TimeCounter(QWidget *parent) : QLCDNumber(parent), time_(QTime(0, 0, 30))
{
    timer_ = new QTimer(this);
    connect(timer_, &QTimer::timeout, this, &TimeCounter::updateTime);
    setFixedHeight(100);
    setFrameStyle(QFrame::Box | QFrame::Plain);
    setMidLineWidth(3);
    setLineWidth(3);
    start();
}

void TimeCounter::start()
{
    time_ = QTime(0, 0, 30);
    if (!timer_->isActive())
        timer_->start(1000);
}

void TimeCounter::stop()
{
    timer_->stop();
}

void TimeCounter::addTime()
{
    time_ = time_.addSecs(1);
    display(time_.toString("mm:ss"));
}

void TimeCounter::updateTime()
{
    time_ = time_.addSecs(-1);
    display(time_.toString("mm:ss"));
    if (time_ == QTime(0, 0, 0)) {
        stop();
        emit timesUp();
    }
}
