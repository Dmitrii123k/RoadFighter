#include "opponent.h"

Opponent::Opponent(QPoint center, GLfloat width, GLfloat height, GLuint texture)
{
    this->center = center;
    this->width = width;
    this->height = height;
    this->texture = texture;
    this->speed = 5;
}

void Opponent::render()
{
    glColor3f(1, 0, 0);
    drawFillRect(this->center.x() - width / 2, this->center.y() + height / 2, this->center.x() + width / 2, this->center.y() - height / 2, texture);
}
