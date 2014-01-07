#ifndef OPPONENT_H
#define OPPONENT_H

#include "globject.h"

class Opponent : public GLObject
{
public:
    Opponent(QPoint center = QPoint(0, 0), GLfloat width = 10, GLfloat height = 0, GLuint texture = 0);
    void setCenterY(GLfloat y) { this->center.setY(y); }
    GLfloat getCenterY() {return this->center.y(); }
    GLfloat getLower() {return this->center.y() - height / 2;}
    GLfloat getUpper() {return this->center.y() + height / 2;}
    GLfloat getLeft() {return this->center.x() - width / 2;}
    GLfloat getRight() {return this->center.x() + width / 2;}
    QPoint center;
    GLfloat width;
    GLfloat height;
    GLuint texture;
    virtual void render();
};

#endif // OPPONENT_H
