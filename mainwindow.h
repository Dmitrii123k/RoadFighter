#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "glmainwindow.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    GLMainWindow *glMainWindow;
    void keyPressEvent(QKeyEvent *);

signals:
    void keyPressEventSignal(QKeyEvent *);
};

#endif // MAINWINDOW_H
