#pragma once

/* Lib includes */
#include <sys/time.h>
#include <iostream>
#include <list>

/* Graphic includes */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/* Includes */
#include "GameRenderer.hpp"
#include "GameEngine.hpp"
#include "Map.hpp"
#include "Entity.hpp"

/* Signals */
#include "literal/from.hpp"
#include "signal.hpp"

using namespace std::string_literals;

enum class Inputs {
    close
};

/* Defines */
#define WIN_WIDTH  1600
#define WIN_HEIGHT 1200

static const int    FPS = 10;
static const double MICRO_SEC = 1000000.;
