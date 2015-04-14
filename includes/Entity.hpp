#pragma once

#include "pl.hpp"

class Entity: public sf::Sprite {

public:
    Entity();
    Entity(const Entity & other);
    ~Entity();

    sf::Texture     tex;

    Entity      &operator=(const Entity & rhs);

};
