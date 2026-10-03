#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITION.h"

namespace Ogay {

    class Wall {
    public:
        Wall();
        void draw(sf::RenderWindow& window);
        bool isCollide(sf::FloatRect playerBounds);

    private:
        sf::Texture _texture;
        sf::Sprite _sprite[50];
        int _index;
    };
}