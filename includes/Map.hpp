#pragma once

#include "pl.hpp"
#include "Texture.hpp"
#include "MapNode.hpp"

class Map {

using MapNodes = std::vector<std::unique_ptr<MapNode>>;

public:
    MapNodes                                      map;
    std::map<const std::string, const Texture>    textures;

    Map() = default;
    Map(const int x, const int y);
    Map(const Map & other) = default;
    ~Map() = default;

    Map     &operator=(const Map & rhs) = default;

    int     getSize() const { return mapX * mapY; }
    int     getX() const { return mapX; }
    int     getY() const { return mapY; }

private:
    int         mapX;
    int         mapY;

    void    addFloor();

};
