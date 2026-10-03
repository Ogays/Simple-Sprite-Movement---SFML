#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITION.h"

namespace Ogay {

    class Camera : private sf::View {
    public:
        Camera();
        void move(sf::Vector2f delta);
        void draw(sf::RenderWindow& window);

    private:
        sf::Vector2f _size;
        sf::Vector2f _camCenter;
        sf::Vector2f _deadZone;
        
        float _leftBound;
        float _rightBound;
        float _topBound;
        float _bottomBound;
        
        float _minCamX;
        float _maxCamX;
        float _minCamY;
        float _maxCamY;
    };
}