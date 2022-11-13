#include "QGridTool.h"

#include <QPen>
#include <QPainter>

QGridTool::QGridTool(QColor color,QSize zoneSize,QSize gridSize):m_LineColor(color),
    m_ZoneSize(zoneSize),m_GridSize(gridSize)
{

}

//绘制网格
void QGridTool::PrintGrid(QPainter *painter, const QRectF &rect)
{
    QPen p(m_LineColor);
    p.setStyle(Qt::DashLine);
    p.setWidthF(0.2);
    painter->setPen(p);

    painter->save();
    painter->setRenderHints(QPainter::Antialiasing,false);

    painter->fillRect(rect,Qt::white);
    for (int x=rect.left() ;x <rect.right()  ;x+=(int)(m_GridSize.width())) {
        painter->drawLine(x,rect.top(),x,rect.bottom());

    }
    for (int y=rect.top();y<rect.bottom() ;y+=(int)(m_GridSize.height()))
    {
        painter->drawLine(rect.left(),y,rect.right(),y);
    }
    p.setStyle(Qt::SolidLine);
    p.setColor(Qt::black);
    painter->drawLine(rect.right(),rect.top(),rect.right(),rect.bottom());
    painter->drawLine(rect.left(),rect.bottom(),rect.right(),rect.bottom());
    painter->restore();
}


//设置网格颜色
void QGridTool::SetGridColor(QColor color)
{
    m_LineColor = color;
}
//设置绘制区域大小
void QGridTool::SetZoneSize(QSize zoneSize)
{
    m_ZoneSize = zoneSize;
}
//设置网格大小
void QGridTool::SetGridSize(QSize gridSize)
{
    m_GridSize = gridSize;
}
