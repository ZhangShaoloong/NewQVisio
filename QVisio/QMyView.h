#ifndef QMYVIEW_H
#define QMYVIEW_H
#include <QMouseEvent>
#include <QGraphicsView>
#include "QMySence.h"

class QMyView : public QGraphicsView
{
    Q_OBJECT
public:
    QMyView(QGraphicsScene* scene);

signals:
    void mousePositionMove(int x,int y);

protected:
    void mouseMoveEvent(QMouseEvent* event);

public slots:
    //放大
    void zoomOut();
    //缩小
    void zoomIn();

};

#endif // QMYVIEW_H
