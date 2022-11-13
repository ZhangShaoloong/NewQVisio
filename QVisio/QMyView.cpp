#include "QMyView.h"

QMyView::QMyView(QGraphicsScene* scene):QGraphicsView(scene)
{

}

void QMyView::mouseMoveEvent(QMouseEvent* event)
{
    QPointF pt =mapToScene(event->pos());
    emit mousePositionMove( pt.x() , pt.y() );
    QGraphicsView::mouseMoveEvent(event);
}

//放大
void QMyView::zoomOut()
{
    scale(1.2,1.2);
    this->scene()->update();
}
//缩小
void QMyView::zoomIn()
{
    scale(1/1.2,1/1.2);
     this->scene()->update();
}
