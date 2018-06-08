#include "game.h"

#if _DEBUG
#include <iostream>
#endif

#include <thread>
#include <chrono>
#include "bin/log.h"

Game::Game()
{
    _window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Pong");
    _window->setVerticalSyncEnabled(false);
    _window->setFramerateLimit(120);
    _background = new Background(_window);

    _volley = 0;
    this->init();
}

Game::~Game()
{
    delete _player1;
    _player1 = nullptr;
    delete _player2;
    _player2 = nullptr;

    delete _ball;
    _ball = nullptr;

    delete _background;
    _background = nullptr;
}

void Game::init()
{
    
    // create ball
    _ball = new Ball(10.f);

    _ball->reset(_window->getSize());
    _ball->setFillColor(sf::Color::Red);

    // create players
    _player1 = new Paddle(sf::Vector2f(_paddleSizeX, _paddleSizeY));
    _player2 = new Paddle(sf::Vector2f(_paddleSizeX, _paddleSizeY));
    _player2->setPosition(_window->getSize().x - _paddleSizeX, 0.f);
    
#if _DEBUG
    std::cout << "( " << _window->getPosition().x << ", " << _window->getPosition().y << " )" << std::endl;
#endif
}


void Game::render()
{
    _window->clear();
    _background->draw();
    _window->draw(*_ball);
    _window->draw(*_player1);
    _window->draw(*_player2);

    _window->display();
}

void Game::loop()
{
    while (_window->isOpen())
    {
        sf::Event event;
        while (_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window->close();
        }
        render();
        hotkeyListener();

        if (!_ball->score)
            _ball->move(_window->getSize(), _player1, _player2);
        else
        {
            score();
        }
    }
}

void Game::hotkeyListener()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        _player1->moveDown(_window->getSize());

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        _player1->moveUp(_window->getSize());

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
        _player2->moveUp(_window->getSize());

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        _player2->moveDown(_window->getSize());
    
}

void Game::start()
{
    this->loop();
}

void Game::score()
{
    _ball->reset(_window->getSize());
    _background->setPlayerOneScore(_player1->getScore());
    _background->setPlayerTwoScore(_player2->getScore());

    /*
    std::thread([=]() {
        std::this_thread::sleep_for(std::chrono::seconds(3))
    }).join();
    */
}