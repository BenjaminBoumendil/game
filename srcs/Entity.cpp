#include "Entity.hpp"

Entity::Entity(): sf::Sprite() { }

Entity::Entity(const Entity & other): sf::Sprite() {
    (void)other;
}

Entity::~Entity() { }

Entity      &Entity::operator=(const Entity & rhs) {
    if (this != &rhs) {
    }
    return *this;
}
