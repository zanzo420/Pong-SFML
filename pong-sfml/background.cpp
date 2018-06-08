#include "background.h"

#include <iostream>

Background::Background(sf::RenderWindow *window)
{
    _window = window;
    _net = new sf::RectangleShape({ 10.0f, (float)_window->getSize().y });
    _net->setPosition((_window->getSize().x / 2), 0);
    _net->setFillColor(sf::Color::White);

    if (!_font.loadFromFile("The 27 Club.otf"))
    {
        std::cout << "error" << std::endl;
    }

    _player1Score.setFont(_font);
    _player2Score.setFont(_font);

    _player1Score.setString("0");
    _player2Score.setString("0");
    _player1Score.setPosition((_window->getSize().x / 2) - 100, 10);
    _player2Score.setPosition((_window->getSize().x / 2) + 100, 10);



    _player1Score.setCharacterSize(60);
    _player2Score.setCharacterSize(60);

}

Background::~Background()
{
    delete _net;
    _net = nullptr;
}

void Background::draw()
{
    _window->draw(*_net);
    _window->draw(_player1Score);
    _window->draw(_player2Score);
}

void Background::setPlayerOneScore(unsigned int score)
{
    _player1Score.setString(std::to_string(score));
}

void Background::setPlayerTwoScore(unsigned int score)
{
    _player2Score.setString(std::to_string(score));
}