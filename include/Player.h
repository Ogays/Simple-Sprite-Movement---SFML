#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "DEFINITION.h"

namespace Ogay {

    class Player : private sf::Sprite {
    public:

        Player();
        void moves(sf::Vector2f delta, Direction direction);
        void draw(sf::RenderWindow& window);
        sf::FloatRect getGlobalBound();
        sf::Vector2f getPositions();
        void setPositions(sf::Vector2f position);
        void setMovement(bool isMoving, float deltaTime);

    private:
        sf::Texture _textureUp;
        sf::Texture _textureDown;
        sf::Texture _textureLeft;
        sf::Texture _textureRight;
        Direction _direction;
        int _currentFrame = 0;
        int _frameCount = 5;
        float _switchTime;
        float _totalTime;
    };
}