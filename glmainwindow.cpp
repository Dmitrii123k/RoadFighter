#include "glmainwindow.h"
#include <iterator>
#include <iostream>

GLMainWindow::GLMainWindow(QWidget *parent) :
    QGLWidget(parent)
{
    renderQueue = new QQueue<GLObject *>();

    road = new Road();
    opponentQueue = new OpponentQueue();

    player = new Player(QPoint(250, 100), 50, 100);

    renderQueue->append(road);
    renderQueue->append(player);
    renderQueue->append(opponentQueue);

    gameSpeed = 0;

    timer = new QTimer();
    timer->start(15);
    connect(timer, SIGNAL(timeout()), this, SLOT(repaint()));
}

void GLMainWindow::initializeGL()
{
    QGLWidget::initializeGL();
    glViewport(0, 0, this->size().width(), this->size().height());
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, this->size().width(), 0, this->size().height(), -1, 1);

    glClearColor(0, 0, 0, 0);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    player->loadTexture();
    player->setOpponentQueue(opponentQueue);
    opponentQueue->loadTexture();
    this->setGameSpeed();
    road->setWindowSize(this->size());

    currentScore = 0;
}

void GLMainWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    QList<GLObject *>::iterator i;
    for (i = renderQueue->begin(); i != renderQueue->end(); ++i)
    {
        GLObject *obj;
        obj = *i;
        obj->render();
    }

    emit score(currentScore += gameSpeed);

    if(player->collision())
    {
        player->loadCollisionTexture();
        this->gameSpeed = 0;
        setGameSpeed();
        timer->stop();
    }
}

void GLMainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Left:
    {
        player->moveLeft();
        break;
    }
    case Qt::Key_Right:
    {
        player->moveRight();
        break;
    }
    case Qt::Key_Up:
    {
        if(gameSpeed < MAX_SPEED)
            gameSpeed += 1;
        this->setGameSpeed();
        break;
    }
    case Qt::Key_Down:
    {
        if(gameSpeed > 0)
            gameSpeed -= 1;
        this->setGameSpeed();
        break;
    }
    }
}

void GLMainWindow::resizeEvent(QResizeEvent *event)
{
    glViewport(0, 0, event->size().width(), event->size().height());
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, event->size().width(), 0, event->size().height(), -1, 1);
    road->setWindowSize(event->size());
    player->setBoundary(road->getLeftBoundary(), road->getRightBoundary());
    opponentQueue->setBoundary(road->getLeftBoundary(), road->getRightBoundary(), event->size().height());
}

void GLMainWindow::setGameSpeed()
{
    QList<GLObject *>::iterator i;
    for (i = renderQueue->begin(); i != renderQueue->end(); ++i)
    {
        GLObject *obj;
        obj = *i;
        obj->setSpeed(gameSpeed);
    }
}
