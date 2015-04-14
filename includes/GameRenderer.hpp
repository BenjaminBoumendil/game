#pragma once

#include "pl.hpp"

class Map;

class GameRenderer: public sf::RenderWindow {

public:
    GameRenderer(const int width, const int height);
    ~GameRenderer();

    void                renderMap(Map map);
    void                eventManager();

private:
    GameRenderer();
    GameRenderer(const GameRenderer & other);

    GameRenderer        &operator=(const GameRenderer & rhs);

};
