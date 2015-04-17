#include "Entity.hpp"

Entity::Entity(const std::string & path): sf::Sprite(), tex(new Texture(path)) { }

void            Entity::update(const Map & map) {
    applyGravity(map);
}

sf::Vector2f    Entity::moveToCollision(const int offsetX, const int offsetY,
                                        const Map & map) {
    return sf::Vector2f(offsetX, offsetY);
}

void            Entity::applyGravity(const Map & map) {
    move(moveToCollision(0, GRAVITY, map));
}
