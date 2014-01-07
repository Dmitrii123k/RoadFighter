

#include "opponentqueue.h"

OpponentQueue::OpponentQueue()
{
    oppWidth = 50;
    oppHeight = 75;

    opponentQueue = new QQueue<Opponent *>();
    timer = DEFAULT_TIMER;
}

void OpponentQueue::render()
{
    QList<Opponent *>::Iterator i;
    glEnable(GL_TEXTURE_2D);
    for(i = opponentQueue->begin(); i != opponentQueue->end(); ++i)
    {
        Opponent *opp;
        opp = *i;
        opp->render();
        opp->setCenterY(opp->getCenterY() - speed);
        if(opp->getCenterY() < 0)
        {
            opponentQueue->erase(i);
        }
    }
    glDisable(GL_TEXTURE_2D);
    timer -= speed;
    if(timer <= 0)
    {
        Opponent *opp = new Opponent(QPoint(rand() % (rightBoundary - leftBoundary) + leftBoundary, startY + 25), oppWidth, oppHeight, texture);
        opp->setSpeed(speed);
        opponentQueue->append(opp);
        timer = DEFAULT_TIMER;
    }
}

void OpponentQueue::loadTexture()
{
    texture = SOIL_load_OGL_texture("opponent.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    if(texture == 0)
    {
        std::cout << "Unable to load texture" << std::endl;
    }
}

void OpponentQueue::setSpeed(int speed)
{
    this->speed = speed;
    QList<Opponent *>::Iterator i;
    for(i = opponentQueue->begin(); i != opponentQueue->end(); ++i)
    {
        Opponent *opp;
        opp = *i;
        opp->setSpeed(this->speed);
    }
}
