#pragma once

#include "pl.hpp"

class Entity {

public:
    Entity();
    Entity(const Entity & other);
    ~Entity();

    Entity      &operator=(const Entity & rhs);

};
