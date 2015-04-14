#include "GameEngine.hpp"

GameEngine::GameEngine(): quit(false) {
    signalsHandler();
}

GameEngine::~GameEngine() {
}

GameEngine      &GameEngine::operator=(const GameEngine & rhs) {
    if (this != &rhs) {
    }
    return *this;
}

void            GameEngine::signalsHandler() {
    using dispatcher_t = signals::literal::from<Inputs>;

    dispatcher_t::on<Inputs::close>([this] {
        this->quit = true;
    });
}

Entity          *GameEngine::createEntity() {
    Entity      *entity = new Entity();

    if (!entity->tex.loadFromFile("img/Character/Walk/Right/1L cien.png")) {
        std::cout << "Error loading texture" << std::endl;
        return nullptr;
    }

    entity->setPosition(100, 100);
    entity->setScale(1, 1);
    entity->setTexture(entity->tex);
    return entity;
}
