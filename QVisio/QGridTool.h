#ifndef QGRIDTOOL_H
#define QGRIDTOOL_H

#include <QSize>
#include <QColor>
#include <QPainter>
#include <QRectF>

class QGridTool
{
public:
    QGridTool(QColor color = QColor(Qt::darkCyan), QSize zoneSize = QSize(1920,1080), QSize gridSize = QSize(10,10));
    //绘制网格
    void PrintGrid(QPainter *painter, const QRectF &rect);
    //设置网格颜色
    void SetGridColor(QColor color);
    //设置绘制区域大小
    void SetZoneSize(QSize zoneSize);
    //设置网格大小
    void SetGridSize(QSize gridSize);

private:
    //网格颜色
    QColor m_LineColor;
    //网格面积大小
    QSize m_ZoneSize;
    //网格大小
    QSize m_GridSize;
};

#endif // QGRIDTOOL_H
