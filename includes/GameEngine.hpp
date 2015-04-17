#pragma once

#include "pl.hpp"
#include "Entity.hpp"
#include "Player.hpp"

class GameEngine {

using Entities = std::vector<std::unique_ptr<Entity>>;

public:
    bool            quit;

    GameEngine();
    ~GameEngine() = default;

    void            eventManager();
    Entity          *createEntity();
    Player          *createPlayer();
    void            update(const Map & map);

private:
    int             gravity;
    Entities        entities;

    GameEngine(const GameEngine & other) = default;

    GameEngine      &operator=(const GameEngine & rhs) = default;

    void            signalsHandler();

};
