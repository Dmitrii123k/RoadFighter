#ifndef TREE_H
#define TREE_H

#include "globject.h"

class Tree : public GLObject
{
public:
    Tree(QPoint center = QPoint(0, 0), GLfloat width = 10, GLfloat height = 0);
    QPoint center;
    GLfloat width;
    GLfloat height;
    virtual void render();
};

#endif // TREE_H
