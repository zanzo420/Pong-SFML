#include "actors.h"

void Paddle::moveUp()
{
    this->setPosition(this->getPosition().x, this->getPosition().y - 10.f);
}

void Paddle::moveDown()
{
    this->setPosition(this->getPosition().x, this->getPosition().y + 10.f);
}

void Paddle::increaseScore()
{
    this->_score++;
}


void Ball::move(sf::Vector2u pos)
{
    if (getPosition().x >= pos.x || getPosition().x <= 0)
        _speedX *= -1;
    
    if (getPosition().y >= pos.y || getPosition().y <= 0)
        _speedY *= -1;

    this->setPosition(this->getPosition().x + _speedX, this->getPosition().y + _speedY);
}

void Ball::spawn()
{

}