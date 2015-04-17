#include "MapNode.hpp"

MapNode::MapNode(const sf::Vector2f & size):
sf::RectangleShape(size), collider(false)
{
}
