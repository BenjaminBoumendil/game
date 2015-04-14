#pragma once

#include "pl.hpp"

class Map {

public:
    std::list<sf::RectangleShape>           map;
    sf::Texture                             floorTex;

    Map();
    Map(const int x, const int y);
    Map(const Map & other);
    ~Map();

    Map     &operator=(const Map & rhs);

    int     getSize() const { return mapX * mapY; }
    int     getX() const { return mapX; }
    int     getY() const { return mapY; }
    void    addFloor();

private:
    int         mapX;
    int         mapY;

};
