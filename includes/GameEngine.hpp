#pragma once

#include "pl.hpp"

class Entity;

class GameEngine {

public:
    bool            quit;

    GameEngine();
    ~GameEngine();

    void            eventManager();
    Entity          *createEntity();

private:
    GameEngine(const GameEngine & other);

    GameEngine      &operator=(const GameEngine & rhs);

    void            signalsHandler();

};
