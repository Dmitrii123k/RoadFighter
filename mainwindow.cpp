#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    glMainWindow = new GLMainWindow();
    connect(this, SIGNAL(keyPressEventSignal(QKeyEvent*)), glMainWindow, SLOT(keyPressEvent(QKeyEvent*)));
    this->setCentralWidget(glMainWindow);
    glMainWindow->setFixedSize(QSize(500, 650));
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    emit keyPressEventSignal(event);
}
