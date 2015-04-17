#pragma once

#include "pl.hpp"
#include "Texture.hpp"

class Map;

class Entity: public sf::Sprite {

public:
    Texture         *tex;

    Entity() = default;
    Entity(const Entity & other) = default;
    Entity(const std::string & path);
    ~Entity() = default;

    Entity      &operator=(const Entity & rhs) = default;

    void        update(const Map & map);

private:
    void            applyGravity(const Map & map);
    sf::Vector2f    moveToCollision(const int offsetX, const int offsetY,
                                    const Map & map);

};
