#pragma once

#include <SFML/Graphics.hpp>

class Paddle : public sf::RectangleShape
{
private:
    int _score = 0;
public:
    Paddle(sf::Vector2f size) : RectangleShape(size) {};

    void moveUp();
    void moveDown();
    void increaseScore();
};



class Ball : public sf::CircleShape
{
private:
    float _speedX = 10.f;
    float _speedY = 10.f;

    void spawn();
public:
    Ball(float size) : sf::CircleShape(size) {};


    void move(sf::Vector2u);
};