#ifndef ROAD_H
#define ROAD_H

#include "globject.h"
#include <QSize>

class Road : public GLObject
{
public:
    static const int STRIP_COUNT = 5;
    Road();
    GLfloat getLeftBoundary() {return leftBoundary;}
    GLfloat getRightBoundary() {return rightBoundary;}
    void setWindowSize(QSize size);
    virtual void render();

private:
    GLint stripArray[STRIP_COUNT][4];
    GLint windowWidth;
    GLint windowHeight;
    GLfloat width;
    GLfloat stripWidth;
    GLfloat stripHeight;
    GLfloat leftBoundary;
    GLfloat rightBoundary;

};

#endif // ROAD_H
