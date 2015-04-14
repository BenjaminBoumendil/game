#pragma once

#include "pl.hpp"

class GameEngine {

public:
    bool            quit;

    GameEngine();
    ~GameEngine();

    void            eventManager();

private:
    GameEngine(const GameEngine & other);

    GameEngine      &operator=(const GameEngine & rhs);

};
