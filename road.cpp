#include "road.h"
#include <iostream>
Road::Road()
{
    width = windowWidth * 0.6;
    stripHeight = 100;
    stripWidth = width / 8;
}

void Road::render()
{
    glColor3f(0.5, 0.5, 0.5);
    drawFillRect(windowWidth / 2 - width / 2, windowHeight, windowWidth / 2 + width / 2, 0);
    glColor3f(1, 1, 1);

    drawFillRect(stripArray[0][0], stripArray[0][1], stripArray[0][2], stripArray[0][3]);
    drawFillRect(stripArray[1][0], stripArray[1][1], stripArray[1][2], stripArray[1][3]);
    drawFillRect(stripArray[2][0], stripArray[2][1], stripArray[2][2], stripArray[2][3]);
    drawFillRect(stripArray[3][0], stripArray[3][1], stripArray[3][2], stripArray[3][3]);

    stripArray[0][1] -= speed;
    stripArray[0][3] -= speed;

    stripArray[1][1] -= speed;
    stripArray[1][3] -= speed;

    stripArray[2][1] -= speed;
    stripArray[2][3] -= speed;

    stripArray[3][1] -= speed;
    stripArray[3][3] -= speed;

    if(stripArray[0][1] < 0)
    {
        stripArray[0][1] += stripHeight * 8;
        stripArray[0][3] += stripHeight * 8;
    }
    if(stripArray[1][1] < 0)
    {
        stripArray[1][1] += stripHeight * 8;
        stripArray[1][3] += stripHeight * 8;
    }
    if(stripArray[2][1] < 0)
    {
        stripArray[2][1] += stripHeight * 8;
        stripArray[2][3] += stripHeight * 8;
    }
    if(stripArray[3][1] < 0)
    {
        stripArray[3][1] += stripHeight * 8;
        stripArray[3][3] += stripHeight * 8;
    }
}

void Road::setWindowSize(QSize size)
{
    this->windowWidth = size.width();
    this->windowHeight = size.height();

    width = windowWidth * 0.6;
    leftBoundary = windowWidth * 0.2;
    rightBoundary = windowWidth * 0.8;

    stripWidth = width * 0.05;
    stripHeight = (2 * windowHeight) / (2 * STRIP_COUNT);

    int i;
    int temp = 0;

    for(i = 0; i < STRIP_COUNT; i++)
    {
        stripArray[i][0] = windowWidth / 2.0 - stripWidth / 2.0;
        stripArray[i][1] = temp + stripHeight;
        stripArray[i][2] = windowWidth / 2.0 + stripWidth / 2.0;
        stripArray[i][3] = temp;
        temp += 2 * stripHeight;
    }
}
