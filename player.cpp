#include "player.h"

Player::Player(QPoint center, GLfloat width, GLfloat height)
{
    playerColor = QColor(0, 255, 0);
    this->center = center;
    this->width = width;
    this->height = height;
}

void Player::render()
{
    glColor3f(playerColor.red() / 255.0, playerColor.green() / 255.0, playerColor.blue() / 255.0);
    glEnable(GL_TEXTURE_2D);
    drawFillRect(this->center.x() - width / 2, this->center.y() + height / 2, this->center.x() + width / 2, this->center.y() - height / 2, texture);
    glDisable(GL_TEXTURE_2D);
}

void Player::loadTexture()
{
    texture = SOIL_load_OGL_texture("images/player.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    if(texture == 0)
    {
        std::cout << "Unable to load texture" << std::endl;
    }
}

void Player::loadCollisionTexture()
{
    texture = SOIL_load_OGL_texture("images/playerCrash.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    if(texture == 0)
    {
        std::cout << "Unable to load texture" << std::endl;
    }
}

void Player::moveLeft()
{
    if(this->center.x()  > leftBoundary)
        this->center.setX(this->center.x() - horizontalSpeed);
}
void Player::moveRight()
{
    if(this->center.x() < rightBoundary)
        this->center.setX(this->center.x() + horizontalSpeed);
}

void Player::setSpeed(int speed)
{
    GLObject::setSpeed(speed);
    this->setHorizontalSpeed(speed);
}

bool Player::collision()
{
    bool retVal = roadCollision() || opponentCollision();
    return retVal;
}

bool Player::roadCollision()
{
    if(this->center.x() - width / 2 <= leftBoundary || this->center.x() + width / 2 >= rightBoundary)
        return true;
    return false;
}

bool Player::opponentCollision()
{
    QList<Opponent *>::Iterator i;
    for(i = opponentQueue->opponentQueue->begin(); i != opponentQueue->opponentQueue->end(); ++i)
    {
        Opponent *opp;
        opp = *i;
        if(opp->getLower() <= this->getUpper() && opp->getLower() >= this->getLower())
        {
            if(opp->getLeft() >= this->getLeft() && opp->getLeft() <= this->getRight())
            {
                return true;
            }
            else if(opp->getRight() >= this->getLeft() && opp->getRight() <= this->getRight())
            {
                return true;
            }
        }
        else if(opp->getUpper() <= this->getUpper() && opp->getUpper() >= this->getLower())
        {
            if(opp->getLeft() >= this->getLeft() && opp->getLeft() <= this->getRight())
            {
                return true;
            }
            else if(opp->getRight() >= this->getLeft() && opp->getRight() <= this->getRight())
            {
                return true;
            }
        }
    }
    return false;
}
