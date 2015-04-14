#pragma once

#include <sys/time.h>
#include <iostream>
#include <list>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "GameRenderer.hpp"
#include "GameEngine.hpp"
#include "Map.hpp"
#include "Entity.hpp"

#define WIN_WIDTH  1600
#define WIN_HEIGHT 1200

static const int    FPS = 10;
static const double MICRO_SEC = 1000000.;
