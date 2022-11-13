#ifndef MYLINEITEM_H
#define MYLINEITEM_H

#include <QObject>
#include <QGraphicsLineItem>
#include <QGraphicsPolygonItem>
#include <QPointF>
#include <QPolygonF>
//各类线条类
enum LineType
{
    NoramlLine, //正常线条
    ArrowLine,  //箭头
};

class MyLineItem : public QGraphicsLineItem
{
public:
    MyLineItem(QPointF startPointf,QPointF endPointf, QColor color = Qt::black,int lineType = Qt::SolidLine,float width = 1.5);
    //线颜色
    QColor lineColor() const;
    void setLineColor(const QColor &lineColor);
    //线类型
    int LineType() const;
    void setLineType(int LineType);
    // 线宽
    int LineWidth() const;
    void setLineWidth(int LineWidth);
    //线起点
    QPointF LineStartPoint() const;
    void setLineStartPoint(const QPointF &LineStartPoint);
    //线终点
    QPointF LineEndPoint() const;
    void setLineEndPoint(const QPointF &LineEndPoint);

    //计算起点和终点的长度
    double GetLineLength();

protected:
    QColor m_lineColor; //线颜色
    int m_LineType;        //线类型
    int m_LineWidth;    //线宽
    //线起点
    QPointF m_LineStartPoint;
    //线终点
    QPointF m_LineEndPoint;

};

enum ArrowHeadType
{
    NoneArrowType = 0, //没有箭头
    StartArrowType, //起始箭头
    EndArrowType,   //结束箭头
    DoubleHeadType, //双向箭头
};

class MyArrowLine:public MyLineItem
{
public:
    MyArrowLine(QPointF startPointf,QPointF endPointf, QColor color ,int lineType,float width);

    //计算箭头的多边形，输入箭头角度
    QList<QPolygonF> CalArrowPolygonF(double arrowLength, double arrowDegree);

    int getArrowType() const;
    void setArrowType(int value);

    int getArrowLength() const;
    void setArrowLength(int arrowLength);

    int getArrowAngle() const;
    void setArrowAngle(int arrowAngle);

    QGraphicsPolygonItem*  getItem1();

    QGraphicsPolygonItem*  getItem2();

private:
    int m_arrowType;    //箭头类型
    int m_arrowLength;//箭头长度
    int m_arrowAngle;   //箭头角度
    QPointF m_mainLineVector; //表示主线向量
    QGraphicsPolygonItem* m_polyItem1;
    QGraphicsPolygonItem* m_polyItem2;
};

#endif // MYLINEITEM_H
