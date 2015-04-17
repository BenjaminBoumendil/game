#pragma once

#include "pl.hpp"
#include "Map.hpp"

class GameRenderer: public sf::RenderWindow {

public:
    GameRenderer(const int width, const int height);
    ~GameRenderer() = default;

    void                renderMap(Map & map);
    void                eventManager();

private:
    GameRenderer();
    GameRenderer(const GameRenderer & other) = default;

    GameRenderer        &operator=(const GameRenderer & rhs) = default;

};
