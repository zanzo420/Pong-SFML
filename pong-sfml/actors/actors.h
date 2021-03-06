#pragma once

#include <SFML/Graphics.hpp>
#include <ctime>

enum SCORE
{
    NONE,
    PLAYER1,
    PLAYER2
};

class Paddle : public sf::RectangleShape
{
private:
    unsigned int _score = 0;

public:
    Paddle(sf::Vector2f size) : RectangleShape(size) {};

    void moveUp(sf::Vector2u);
    void moveDown(sf::Vector2u);
    void increaseScore();
    unsigned int getScore();
};



class Ball : public sf::CircleShape
{
private:
    const float _defaultSpeed = 4.0f;
    float _speedX = 4.0f;
    float _speedY = 4.0f;
    
public:
    static bool score;
    static int lastScored;

    Ball(float size) : sf::CircleShape(size) {
        std::srand(time(NULL));
        std::rand();
    };

    

    void reset(sf::Vector2u);
    void move(sf::Vector2u, Paddle*, Paddle*);
};