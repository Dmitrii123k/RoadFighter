#ifndef GLOBJECT_H
#define GLOBJECT_H

#include <QGLWidget>
#include <SOIL/SOIL.h>
#include <iostream>

class GLObject
{
public:
    GLObject();
    virtual void render() = 0;
    virtual void setSpeed(int speed) {this->speed = speed;}
    GLint getSpeed() {return speed;}
    int speed;
    void drawFillRect(QPoint center, GLint height, GLint width);
    void drawFillRect(QPoint topLeft, QPoint bottomRight);
    void drawFillRect(GLint x1, GLint y1, GLint x2, GLint y2);
    void drawFillRect(GLint x1, GLint y1, GLint x2, GLint y2, GLuint texture);
};

#endif // GLOBJECT_H
