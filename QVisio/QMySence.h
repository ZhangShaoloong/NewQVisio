#ifndef QMYSENCE_H
#define QMYSENCE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include "QGridTool.h"

class QMySence : public QGraphicsScene
{
public:
    QMySence(QObject *parent = NULL);

    //设置坐标原点(x,y),指定坐标原点位置即左上角的点位
    void setCoordOriginalPoint(int x, int y);

protected:
    void drawBackground(QPainter *painter, const QRectF &rect);

private:
    QGridTool* m_grid;
    //图片原点坐标
    int m_originalPointX;
    int m_originalPointY;
};

#endif // QMYSENCE_H
