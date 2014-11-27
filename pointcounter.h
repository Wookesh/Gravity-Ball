#ifndef POINTCOUNTER_H
#define POINTCOUNTER_H

#include <QLCDNumber>

class PointCounter : public QLCDNumber {
    Q_OBJECT
public:
    explicit PointCounter(QWidget *parent = 0);

private :
    qint16 points_;

public slots:
    void resetPoints();
    void addPoint();
};

#endif // POINTCOUNTER_H
