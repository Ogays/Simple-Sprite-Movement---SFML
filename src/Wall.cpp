#include "../include/Wall.h"

namespace Ogay {

    Wall::Wall() {
        if (!_texture.loadFromFile(SPRITE_WALL_FILEPATH))
            EXIT_FAILURE;

        _index = 0;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (WALLS[j][i] == 1) {
                    _sprite[_index].setTexture(_texture);
                    _sprite[_index].setPosition(sf::Vector2f(70.0f * i + 10.0f, 70.0f * j + 10.0f));
                    _index++;
                }
            }
        }
    }

    void Wall::draw(sf::RenderWindow& window) {
        for (int i = 0; i < _index; i++) {
            window.draw(_sprite[i]);
        }
    }

    bool Wall::isCollide(sf::FloatRect playerBounds) {
        for (int i = 0; i < _index; i++) {
            if (playerBounds.intersects(_sprite[i].getGlobalBounds())) {
                return true;
            }
        }
        return false;
    }
}
