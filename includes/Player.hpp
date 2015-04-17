#pragma once

#include "pl.hpp"
#include "Entity.hpp"
#include "Texture.hpp"

class Player: public Entity {

public:
    Player() = default;
    Player(const Player & other) = default;
    Player(const std::string & path);
    ~Player() = default;

    Player          &operator=(const Player & rhs) = default;

private:
    std::map<const std::string, const Texture>       textures;

    void            signalHandler();

};
