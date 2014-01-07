#include "tree.h"

Tree::Tree(QPoint center, GLfloat width, GLfloat height)
{
    this->center = center;
    this->width = width;
    this->height = height;
}

void Tree::render()
{
    glColor3f(1, 1, 0);
    drawFillRect(this->center.x() - width / 2, this->center.y() + height / 2, this->center.x() + width / 2, this->center.y() - height / 2);
}
