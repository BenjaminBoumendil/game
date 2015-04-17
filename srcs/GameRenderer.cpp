#include "GameRenderer.hpp"

GameRenderer::GameRenderer():
sf::RenderWindow::RenderWindow(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT),
                               "WINDOW BETON",
                               sf::Style::Titlebar |
                               sf::Style::Resize |
                               sf::Style::Close)
{
}

GameRenderer::GameRenderer(const int width, const int height):
sf::RenderWindow::RenderWindow(sf::VideoMode(width, height),
                               "WINDOW BETON",
                               sf::Style::Titlebar |
                               sf::Style::Resize |
                               sf::Style::Close)
{
}

void                GameRenderer::renderMap(Map & map) {
    for (auto & node:map.map)
        draw(*node);
}

void             GameRenderer::eventManager() {
    using dispatcher_t = signals::literal::from<Inputs>;
    sf::Event   event;

    while (pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            close();
            dispatcher_t::emit<Inputs::close>();
        }
        else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Left)
                dispatcher_t::emit<Inputs::moveLeft>();
            else if (event.key.code == sf::Keyboard::Right)
                dispatcher_t::emit<Inputs::moveRight>();
        }
    }
}
