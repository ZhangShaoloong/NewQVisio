#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUndoStack>
#include <QUndoView>
#include <QGraphicsView>
#include "QMySence.h"
#include "QMyView.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    //初始化UI
    void initUI();
    //初始化菜单
    void initMenu();
    //创建子窗口
    QGraphicsView* createChildWindows();


    //菜单快捷键
private slots:
    //新建场景
    void newCondition();
    //新建文件
    void newFile();
    //鼠标位置更新
    void mousepositionChanged(int x, int y);

private:
    Ui::MainWindow *ui;
    QUndoStack*    m_undoStack;
    QUndoView*     m_undoView;
};

#endif // MAINWINDOW_H
