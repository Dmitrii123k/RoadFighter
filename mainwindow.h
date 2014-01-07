#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QHBoxLayout>
#include "ui_mainwindow.h"
#include "glmainwindow.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT
    
    QFrame *mainFrame;
    QLabel *scoreLabel;
    QHBoxLayout *frameLayout;

public:
    explicit MainWindow(QWidget *parent = 0);
    GLMainWindow *glMainWindow;
    void keyPressEvent(QKeyEvent *);

signals:
    void keyPressEventSignal(QKeyEvent *);
public slots:
    void updateScore(int);
};

#endif // MAINWINDOW_H
