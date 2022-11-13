#include "MyLineItem.h"
#include <QPen>
#include "math.h"
#include <QPointF>
#include <QDebug>

#define M_PI 3.1415926

MyLineItem::MyLineItem(QPointF startPointf,QPointF endPointf, QColor color, int lineType, float width)
    :QGraphicsLineItem(startPointf.x(),startPointf.y(),endPointf.x(),endPointf.y()),
    m_lineColor(color),m_LineType(lineType),m_LineWidth(width),m_LineStartPoint(startPointf),m_LineEndPoint(endPointf)
{
   QPen pen;
   pen.setColor(m_lineColor);
   pen.setStyle((Qt::PenStyle)m_LineType);
   pen.setWidth(m_LineWidth);
   this->setPen(pen);
}

QColor MyLineItem::lineColor() const
{
    return m_lineColor;
}

void MyLineItem::setLineColor(const QColor &lineColor)
{
    m_lineColor = lineColor;
}

int MyLineItem::LineType() const
{
    return m_LineType;
}

void MyLineItem::setLineType(int LineType)
{
    m_LineType = LineType;
}

int MyLineItem::LineWidth() const
{
    return m_LineWidth;
}

void MyLineItem::setLineWidth(int LineWidth)
{
    m_LineWidth = LineWidth;
}

QPointF MyLineItem::LineStartPoint() const
{
    return m_LineStartPoint;
}

void MyLineItem::setLineStartPoint(const QPointF &LineStartPoint)
{
    m_LineStartPoint = LineStartPoint;
}

QPointF MyLineItem::LineEndPoint() const
{
    return m_LineEndPoint;
}

void MyLineItem::setLineEndPoint(const QPointF &LineEndPoint)
{
    m_LineEndPoint = LineEndPoint;
}

//计算起点和终点的长度
double MyLineItem::GetLineLength()
{
    return this->line().length();
}

MyArrowLine::MyArrowLine(QPointF startPointf,QPointF endPointf, QColor color, int lineType, float width)
    :MyLineItem(startPointf, endPointf, color, lineType, width)
{
    this->m_arrowAngle = 45;
    this->m_arrowLength =50;
    this->m_arrowType = StartArrowType;
    this->m_mainLineVector = m_LineEndPoint-m_LineStartPoint;
    QList<QPolygonF> polygonList = CalArrowPolygonF(20.0, M_PI/8.0);
    QGraphicsPolygonItem* item = new QGraphicsPolygonItem(polygonList.first());
    item->setBrush(QColor(220,40,30));
    m_polyItem1 = item;

    item = new QGraphicsPolygonItem(polygonList.last());
    item->setBrush(QColor(220,40,30));
    m_polyItem2 = item;
}


QGraphicsPolygonItem* MyArrowLine::getItem1()
{
  return m_polyItem1;
}

 QGraphicsPolygonItem* MyArrowLine::getItem2()
 {
    return m_polyItem2;
 }

//计算箭头的多边形，输入箭头角度
QList<QPolygonF> MyArrowLine::CalArrowPolygonF(double arrowLength, double arrowDegree)
{
    QList<QPolygonF>  polygonList;
    double startX = m_LineStartPoint.x();
    double startY = m_LineStartPoint.y();
    double endX = m_LineEndPoint.x();
    double endY = m_LineEndPoint.y();
    double lineAngle = atan2(endY-startX,endX-startY)+M_PI;
    //结尾箭头点1的坐标
    double x11 = endX + arrowLength * cos(lineAngle - arrowDegree);
    double y11 = endY + arrowLength * sin(lineAngle - arrowDegree);
    //结尾箭头点2的坐标
    double x12 = endX + arrowLength * cos(lineAngle + arrowDegree);
    double y12 = endY + arrowLength * sin(lineAngle + arrowDegree);
    QPolygonF polygon;
    polygon.append(m_LineEndPoint);
    polygon.append(QPointF(x11,y11));
    polygon.append(QPointF(x12,y12));
    polygonList.append(polygon);
     //计算起始箭头点位置
    endX = m_LineStartPoint.x();
    endY= m_LineStartPoint.y();
    startX = m_LineEndPoint.x();
    startY = m_LineEndPoint.y();
     lineAngle = atan2(endY-startX,endX-startY);
     //箭头点1的坐标
     double x21 = endX - arrowLength * sin(lineAngle - arrowDegree);
     double y21 = endY - arrowLength * cos(lineAngle - arrowDegree);
     //箭头点2的坐标
     double x22 = endX - arrowLength * sin(lineAngle + arrowDegree);
     double y22 = endY - arrowLength * cos(lineAngle + arrowDegree);
     polygon.clear();
     polygon.append(m_LineStartPoint);
     polygon.append(QPointF(x21,y21));
     polygon.append(QPointF(x22,y22));
     polygonList.append(polygon);

    return polygonList;
}

int MyArrowLine::getArrowType() const
{
    return m_arrowType;
}

void MyArrowLine::setArrowType(int value)
{
    m_arrowType = value;
}

int MyArrowLine::getArrowLength() const
{
    return m_arrowLength;
}

void MyArrowLine::setArrowLength(int arrowLength)
{
    m_arrowLength = arrowLength;
}

int MyArrowLine::getArrowAngle() const
{
    return m_arrowAngle;
}

void MyArrowLine::setArrowAngle(int arrowAngle)
{
    m_arrowAngle = arrowAngle;
}
