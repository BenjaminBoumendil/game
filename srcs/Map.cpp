#include "Map.hpp"

Map::Map(const int x, const int y): textures({
    { "wallRight", Texture("tex/Rendered Textures/Walls/Wall 1 NE.png") },
    { "wallLeft" , Texture("tex/Rendered Textures/Walls/Wall 1 NW.png") },
    { "wallUp"   , Texture("tex/Rendered Textures/Walls/Wall 2 NW.png") },
    { "wallDown" , Texture("tex/Rendered Textures/Walls/Wall 2 NE.png") },}
), mapX(x), mapY(y)
{
    MapNode     *rec;

    for (int i = 0; i < y; i++) {
        for (int c = 0; c < x; c++) {
            rec = new MapNode(sf::Vector2f(WIN_WIDTH / x, WIN_HEIGHT / y));
            rec->setPosition(c * WIN_WIDTH / x, i * WIN_HEIGHT / y);
            rec->setOutlineThickness(1);
            rec->setOutlineColor(sf::Color::Red);
            rec->setFillColor(sf::Color::Black);
            map.emplace_back(rec);
        }
    }
    addFloor();
}

void        Map::addFloor() {
    for (auto & node:map)
    {
        if (node->getPosition().y == ((mapY - 1) * WIN_HEIGHT / mapY)) {
            node->setFillColor(sf::Color::White);
            if (node->getPosition().x == 0)
                node->setTexture(&textures["wallLeft"]);
            else if (node->getPosition().x == ((mapX - 1) * WIN_WIDTH / mapX))
                node->setTexture(&textures["wallRight"]);
            else
                node->setTexture(&textures["wallUp"]);
            node->collider = true;
        }
    }
}
