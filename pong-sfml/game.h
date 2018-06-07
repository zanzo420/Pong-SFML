#pragma once

#include <SFML\Graphics.hpp>

#include "actors\actors.h"

class Game
{
private:
    const float _paddleSizeX = 50;
    const float _paddleSizeY = 100;

    sf::RenderWindow *_window;

    Paddle *_player1;
    Paddle *_player2;

    Ball *_ball;

    int _volley;

    void loop();
    void hotkeyListener();
public:
    Game();
    ~Game();

    void init();
    void render();
    void start();
    void score();
};