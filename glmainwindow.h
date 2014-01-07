#ifndef GLMAINWINDOW_H
#define GLMAINWINDOW_H

#include <QGLWidget>
#include <QQueue>
#include "globject.h"
#include "player.h"
#include "tree.h"
#include "road.h"
#include "opponentqueue.h"
#include <QResizeEvent>
#include <QTimer>
#include <QKeyEvent>

#define MAX_SPEED 10

class GLMainWindow : public QGLWidget
{
    Q_OBJECT

public:
    explicit GLMainWindow(QWidget *parent = 0);
    QTimer *timer;
    QQueue<GLObject *> *renderQueue;
    Player *player;
    Road *road;
    OpponentQueue *opponentQueue;
    GLint gameSpeed;
    void setGameSpeed();
    void paintGL();
    void initializeGL();
    void resizeEvent(QResizeEvent *);
    int currentScore;
signals:
    void score(int newScore);

public slots:
    void keyPressEvent(QKeyEvent *);

};

#endif // GLMAINWINDOW_H
