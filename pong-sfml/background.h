#pragma once

#include <SFML\Graphics.hpp>

class Background
{
private:
    sf::RectangleShape *_net;
    sf::RenderWindow *_window;
    sf::Text _player1Score;
    sf::Text _player2Score;
    sf::Font _font;
public:
    Background(sf::RenderWindow*);
    ~Background();

    void setPlayerOneScore(unsigned int);
    void setPlayerTwoScore(unsigned int);

    void draw();
};