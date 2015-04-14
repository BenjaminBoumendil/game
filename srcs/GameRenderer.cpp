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

GameRenderer::GameRenderer(const GameRenderer & other) { (void)other; }

GameRenderer::~GameRenderer() { }

GameRenderer        &GameRenderer::operator=(const GameRenderer & rhs) {
    if (this != &rhs) {
    }
    return *this;
}

void                GameRenderer::renderMap(Map map) {
    std::list<sf::RectangleShape>::iterator   it = map.map.begin();

    while (it != map.map.end())
    {
        draw(*it);
        it++;
    }
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
        // else if (event.type == sf::Event::KeyPressed)
            // return event.key.code;
    }
}
