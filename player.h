#ifndef PLAYER_H
#define PLAYER_H

#include "globject.h"
#include "opponent.h"
#include "opponentqueue.h"
#include <QQueue>

class Player : public GLObject
{
public:
    Player(QPoint center = QPoint(0, 0), GLfloat width = 10, GLfloat height = 0);

    int horizontalSpeed;
    GLfloat getPositionX() {return center.x();}
    GLfloat getPositionY() {return center.y();}
    void setBoundary(GLfloat left, GLfloat right) { leftBoundary = left; rightBoundary = right;}
    void moveLeft();
    void moveRight();
    void setHorizontalSpeed(GLint horizontalSpeed) {this->horizontalSpeed = horizontalSpeed;}
    virtual void render();
    void loadTexture();
    void loadCollisionTexture();
    void setSpeed(int speed);
    bool collision();
    void setOpponentQueue(OpponentQueue *opponentQueue) {this->opponentQueue = opponentQueue;}
    bool roadCollision();
    bool opponentCollision();
    GLfloat getLower() {return this->center.y() - height / 2;}
    GLfloat getUpper() {return this->center.y() + height / 2;}
    GLfloat getLeft() {return this->center.x() - width / 2;}
    GLfloat getRight() {return this->center.x() + width / 2;}
private:
    QPoint center;
    GLfloat width;
    GLfloat height;
    GLfloat leftBoundary;
    GLfloat rightBoundary;
    QColor playerColor;
    GLuint texture;
    OpponentQueue *opponentQueue;
};

#endif // PLAYER_H
