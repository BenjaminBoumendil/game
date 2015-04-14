#include "GameEngine.hpp"

GameEngine::GameEngine(): quit(false) {
}

GameEngine::~GameEngine() {
}

GameEngine      &GameEngine::operator=(const GameEngine & rhs) {
    if (this != &rhs) {
    }
    return *this;
}
