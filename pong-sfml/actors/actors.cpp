#include "actors.h"

#if _DEBUG
#include <iostream>
#endif

// Move the paddle up
void Paddle::moveUp(sf::Vector2u window)
{
    if(this->getPosition().y > 0)
        this->setPosition(this->getPosition().x, this->getPosition().y - 10.f);
}

// moves the paddle down
void Paddle::moveDown(sf::Vector2u window)
{
    if (this->getPosition().y <= window.y - this->getSize().y)
        this->setPosition(this->getPosition().x, this->getPosition().y + 10.f);
}


void Paddle::increaseScore()
{
    this->_score++;
}


bool Ball::score = false;

int Ball::lastScored = NONE;

// moves the ball
void Ball::move(sf::Vector2u window, Paddle *player1, Paddle *player2)
{


    if (this->getPosition().x >= window.x || this->getPosition().x <= 0)
        _speedX *= -1;
    
    if (this->getPosition().y >= window.y || this->getPosition().y <= 0)
        _speedY *= -1;





    // player 1 check
    if (this->getPosition().x <= player1->getSize().x && (this->getPosition().y > player1->getPosition().y && this->getPosition().y < (player1->getPosition().y + player1->getSize().y)))
    {
        _speedX *= -1;

#if _DEBUG
        std::cout << "Player 1 Collided" << std::endl;
#endif
    }

    // player 2 check
    else if (this->getPosition().x >= window.x - player2->getSize().x && (this->getPosition().y > player2->getPosition().y && this->getPosition().y < player2->getPosition().y + player1->getSize().y))
    {
        _speedX *= -1;

#if _DEBUG
        std::cout << "Player 2 Collided" << std::endl;
#endif
    }

    else if (this->getPosition().x < player1->getSize().x)
    {
        this->score = true;
        player2->increaseScore();

#if _DEBUG
        std::cout << "Player 2 Scored" << std::endl;
#endif
    }


    else if (this->getPosition().x > window.x - player2->getSize().x)
    {
        this->score = true;
        player1->increaseScore();
        
#if _DEBUG
        std::cout << "Player 1 Scored" << std::endl;
#endif
    }

    this->setPosition(this->getPosition().x + this->_speedX, this->getPosition().y + this->_speedY);
}


unsigned int Paddle::getScore()
{
    return _score;
}

void Ball::reset(sf::Vector2u window)
{
    int posY = std::rand() % (window.y - 200);

    this->setPosition((window.x / 2), posY);

    int direction = std::rand() % 100;

    if (direction % 2 == 0)
        this->_speedX *= 1;

    this->score = false;
}