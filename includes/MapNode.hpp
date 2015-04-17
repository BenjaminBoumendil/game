#pragma once

#include "pl.hpp"

class MapNode: public sf::RectangleShape {

public:
    bool        collider;

    MapNode() = default;
    MapNode(const sf::Vector2f & size);
    MapNode(const MapNode & other) = default;
    ~MapNode() = default;

    MapNode         &operator=(const MapNode & rhs) = default;

};
