#include "QMySence.h"
#include <QDebug>
#include "MyLineItem.h"
QMySence::QMySence(QObject *parent):QGraphicsScene(parent)
{
    this->setSceneRect(QRectF(0,0,800,600));
    setCoordOriginalPoint(420,350);
    m_grid = new QGridTool();

}

void QMySence::setCoordOriginalPoint(int x, int y)
{
    this->sceneRect();
    m_originalPointX =  -(this->sceneRect().width()/2) + x;
    m_originalPointY =  -(this->sceneRect().height()/2) + y;
    qDebug()<<m_originalPointX<<m_originalPointY;
}

void QMySence::drawBackground(QPainter *painter, const QRectF &rect)
{
    if(m_grid)
    {
        m_grid->PrintGrid(painter,rect);
    }
    \
    MyArrowLine* arrowLine = new MyArrowLine(QPointF(30,20),QPointF(180,150), Qt::black,Qt::SolidLine,1.5);
    this->addItem(arrowLine);
    this->addItem(arrowLine->getItem1());
    this->addItem(arrowLine->getItem2());
}
