#pragma once

#include "pl.hpp"

class Texture: public sf::Texture {

public:
    Texture();
    Texture(const Texture & other) = default;
    Texture(const std::string & path);
    ~Texture();

    Texture     &operator=(const Texture & rhs) = default;

};
