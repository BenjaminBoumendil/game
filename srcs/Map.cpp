#include "Map.hpp"

Map::Map() { }

Map::Map(const int x, const int y): map(), mapX(x), mapY(y) {
    sf::RectangleShape      rec(sf::Vector2f(WIN_WIDTH / x, WIN_HEIGHT / y));

    for (int i = 0; i < y; i++) {
        for (int c = 0; c < x; c++) {
            rec.setPosition(c * WIN_WIDTH / x, i * WIN_HEIGHT / y);
            rec.setOutlineThickness(1);
            rec.setOutlineColor(sf::Color::Red);
            rec.setFillColor(sf::Color(0, 184, 245));
            map.push_back(rec);
        }
    }
}

Map::Map(const Map & other) {
    map = other.map;
    mapX = other.mapX;
    mapY = other.mapY;
    floorTex = other.floorTex;
}

Map::~Map() { }

Map         &Map::operator=(const Map & rhs) {
    if (this != &rhs) {
        map = rhs.map;
        mapX = rhs.mapX;
        mapY = rhs.mapY;
        floorTex = rhs.floorTex;
    }
    return *this;
}

void        Map::addFloor() {
    std::list<sf::RectangleShape>::iterator     it = map.begin();

    while (it != map.end())
    {
        if (it->getPosition().y == ((mapY - 1) * WIN_HEIGHT / mapY)) {
            it->setFillColor(sf::Color::White);
            it->setTexture(&floorTex);
        }
        it++;
    }
}
