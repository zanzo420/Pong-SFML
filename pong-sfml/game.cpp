#include "game.h"

Game::Game()
{
    _window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Pong");
    _window->setVerticalSyncEnabled(false);
    _window->setFramerateLimit(120);

    _volley = 0;
    this->init();
}

Game::~Game()
{
    delete _player1;
    _player1 = nullptr;
    delete _player2;
    _player2 = nullptr;
}

void Game::init()
{
    // create ball
    _ball = new Ball(10.f);

    _ball->setPosition(50, 50);
    _ball->setFillColor(sf::Color::White);

    // create players
    _player1 = new Paddle(sf::Vector2f(100, 200));
    _player2 = new Paddle(sf::Vector2f(100, 200));
    _player2->setPosition(924.f, 0.f);

}


void Game::render()
{
    _window->clear();
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

        _window->getSize();

        //_ball->move(0.2f, 0.2f);
        _ball->move(_window->getSize());
    }
}

void Game::hotkeyListener()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        _player1->moveDown();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        _player1->moveUp();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
        _player2->moveUp();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        _player2->moveDown();
    
}

void Game::start()
{
    this->loop();
}