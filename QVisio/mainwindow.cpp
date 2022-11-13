#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUI();
    initMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI()
{
    ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    m_undoStack = new QUndoStack(this);
    m_undoView = new QUndoView(m_undoStack);
    m_undoView->setWindowTitle(tr("Command List"));
    m_undoView->setAttribute(Qt::WA_QuitOnClose, false);

    ui->undo_dockWidget_2->setWidget(m_undoView);
}

void MainWindow::initMenu()
{
    //Q_ASSERT(connect(ui->actionNewCondition,SIGNAL(triggered()),this,SIGNAL(newCondition())));
  Q_ASSERT(connect(ui->actionNewFile,SIGNAL(triggered()),this,SLOT(newFile())));
}

QGraphicsView* MainWindow::createChildWindows()
{
        QMySence *scene = new QMySence(this);

        QRectF rc = QRectF(0 , 0 , 800, 600);

        scene->setSceneRect(rc);
        qDebug()<<rc.bottomLeft()<<rc.size() << rc.topLeft();

        QMyView *view = new QMyView(scene);
        scene->setBackgroundBrush(Qt::darkGray);

        ui->mdiArea->addSubWindow(view);

        view->showMaximized();

        Q_ASSERT(connect(view,SIGNAL(mousePositionMove(int,int)),this,SLOT(mousepositionChanged(int,int))));
        Q_ASSERT(connect(ui->actionZoomIn,SIGNAL(triggered()), view, SLOT(zoomIn())));
        Q_ASSERT(connect(ui->actionZoomOut,SIGNAL(triggered()), view, SLOT(zoomOut())));

        return view;

   // return NULL;
}

//新建场景
void MainWindow::newCondition()
{

}
//新建文件
void MainWindow::newFile()
{
    createChildWindows();
}

void MainWindow::mousepositionChanged(int x, int y)
{
    QString pos= QString("%1,%2").arg(x).arg(y);
    ui->statusBar->showMessage(pos);
}
