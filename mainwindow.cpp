#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    frameLayout = new QHBoxLayout();
    mainFrame = new QFrame();
    mainFrame->setLayout(frameLayout);
    this->setCentralWidget(mainFrame);

    glMainWindow = new GLMainWindow();
    glMainWindow->setFixedSize(QSize(500, 650));

    scoreLabel = new QLabel("");
    frameLayout->addWidget(glMainWindow);
    frameLayout->addWidget(scoreLabel);
    connect(this, SIGNAL(keyPressEventSignal(QKeyEvent*)), glMainWindow, SLOT(keyPressEvent(QKeyEvent*)));
    connect(glMainWindow, SIGNAL(score(int)), this, SLOT(updateScore(int)));

}

void MainWindow::updateScore(int newScore)
{
    this->scoreLabel->setText(QString::number(newScore / 100));
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    emit keyPressEventSignal(event);
}
