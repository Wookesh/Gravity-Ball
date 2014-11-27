#include "pointcounter.h"

PointCounter::PointCounter(QWidget *parent) : QLCDNumber(parent), points_(0)
{
    setFixedHeight(100);
    setFrameStyle(QFrame::Box | QFrame::Plain);
    setMidLineWidth(3);
    setLineWidth(3);
}

void PointCounter::resetPoints()
{
    points_ = 0;
    display(points_);
}

void PointCounter::addPoint()
{
    display(++points_);
}
