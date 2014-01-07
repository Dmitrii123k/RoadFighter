#include "globject.h"

GLObject::GLObject()
{
    speed = 0;
}

void GLObject::drawFillRect(QPoint center, GLint height, GLint width)
{
    drawFillRect(QPoint(center.x() - width / 2, center.y() + height / 2), QPoint(center.x() + width / 2, center.y() - width / 2));
}

void GLObject::drawFillRect(QPoint topLeft, QPoint bottomRight)
{
    glBegin(GL_QUADS);
    glVertex2f(topLeft.x(), topLeft.y());
    glVertex2f(topLeft.x(), bottomRight.y());
    glVertex2f(bottomRight.x(), bottomRight.y());
    glVertex2f(bottomRight.x(), topLeft.y());
    glEnd();
}

void GLObject::drawFillRect(GLint x1, GLint y1, GLint x2, GLint y2)
{
    drawFillRect(QPoint(x1, y1), QPoint(x2, y2));
}


void GLObject::drawFillRect(GLint x1, GLint y1, GLint x2, GLint y2, GLuint texture)
{
    glColor4f(1, 1, 1, 1);

    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);

    glTexCoord2f(0, 0);
    glVertex2f(x1, y1);

    glTexCoord2f(1, 0);
    glVertex2f(x2, y1);

    glTexCoord2f(1, 1);
    glVertex2f(x2, y2);

    glTexCoord2f(0, 1);
    glVertex2f(x1, y2);

    glEnd();

}
