#pragma once

/* Lib includes */
#include <sys/time.h>
#include <iostream>
#include <list>
#include <map>

/* Graphic includes */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/* Signals */
#include "literal/from.hpp"
#include "signal.hpp"

using namespace std::string_literals;

enum class Inputs {
    close,
    moveRight,
    moveLeft
};

/* Defines */
#define WIN_WIDTH  1600
#define WIN_HEIGHT 1200
#define GRAVITY    20

static const int    FPS = 10;
static const double MICRO_SEC = 1000000.;
