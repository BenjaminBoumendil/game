#include "Entity.hpp"

Entity::Entity() { }

Entity::Entity(const Entity & other) { (void)other; }

Entity::~Entity() { }

Entity      &Entity::operator=(const Entity & rhs) {
    if (this != &rhs) {
    }
    return *this;
}
