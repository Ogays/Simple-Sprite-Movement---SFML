#pragma once

#include <string>

const int WALLS[9][9] = {
        {1, 1, 1, 1, 1, 1, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 1, 0, 0},
        {1, 0, 0, 1, 1, 1, 1, 1, 1}
};

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

const int SCREEN_WIDTH = 200;
const int SCREEN_HEIGHT = 200;

const float CAMERA_WIDTH = 200.f;
const float CAMERA_HEIGHT = 200.f;

const float WORLD_WIDTH = 650.f;
const float WORLD_HEIGHT = 650.f;

const std::string SPRITE_UP_FILEPATH = "res/up.png";
const std::string SPRITE_DOWN_FILEPATH = "res/down.png";
const std::string SPRITE_LEFT_FILEPATH = "res/left.png";
const std::string SPRITE_RIGHT_FILEPATH = "res/right.png";
const std::string SPRITE_WALL_FILEPATH = "res/wall.png";