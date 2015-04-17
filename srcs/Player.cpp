#include "Player.hpp"

Player::Player(const std::string & path): Entity::Entity(path), textures({
    { "idleLeft", Texture("img/Character/Walk/Right/1L cien.png") },
    { "idleRight", Texture("img/Character/Walk/Left/000.png") }}
)
{
    signalHandler();
}

void            Player::signalHandler() {
    using dispatcher_t = signals::literal::from<Inputs>;

    dispatcher_t::on<Inputs::moveRight>([this] {
        setTexture(textures["idleRight"]);
        move(50, 0);
    });

    dispatcher_t::on<Inputs::moveLeft>([this] {
        setTexture(textures["idleLeft"]);
        move(-50, 0);
    });
}
