#include "GameEngine.hpp"

GameEngine::GameEngine(): quit(false) {
    signalsHandler();
}

void            GameEngine::signalsHandler() {
    using dispatcher_t = signals::literal::from<Inputs>;

    dispatcher_t::on<Inputs::close>([this] {
        this->quit = true;
    });
}

Entity          *GameEngine::createEntity() {
    Entity      *entity = new Entity("img/Character/Walk/Right/1L cien.png");

    entity->setPosition(100, 1000);
    entity->setScale(1, 1);
    entity->setTexture(*entity->tex);
    return entity;
}

Player          *GameEngine::createPlayer() {
    Player      *player = new Player("img/Character/Walk/Right/1L cien.png");

    player->setPosition(100, 100);
    player->setTexture(*player->tex);
    entities.emplace_back(player);
    return player;
}

void            GameEngine::update(const Map & map) {
    for (auto & entity:entities)
        entity->update(map);
}
