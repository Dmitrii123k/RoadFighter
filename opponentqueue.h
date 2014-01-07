#ifndef OPPONENTQUEUE_H
#define OPPONENTQUEUE_H

#include "opponent.h"
#include "globject.h"
#include <QQueue>
#define DEFAULT_TIMER 150
class OpponentQueue : public GLObject
{
public:
    GLint startY;
    GLint leftBoundary;
    GLint rightBoundary;
    GLuint texture;
    OpponentQueue();
    virtual void render();
    void setBoundary(GLfloat left, GLfloat right, GLfloat top) { leftBoundary = left; rightBoundary = right; startY = top; }
    QQueue<Opponent *> *opponentQueue;
    void loadTexture();
    void setSpeed(int speed);
    int oppHeight;
    int oppWidth;
    int timer;
};

#endif // OPPONENTQUEUE_H
