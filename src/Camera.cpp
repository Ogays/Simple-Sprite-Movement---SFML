#include "../include/Camera.h"
#include <iostream>
#include <algorithm>

namespace Ogay {

    Camera::Camera() {
        _size = sf::Vector2f(CAMERA_WIDTH, CAMERA_HEIGHT);
        _camCenter = sf::Vector2f(100.0f, 100.0f);
        setSize(_size);
        setCenter(_camCenter);

        _deadZone = sf::Vector2f(70.0f, 70.0f);
        
        _minCamX = CAMERA_WIDTH / 2.f;
        _maxCamX = WORLD_WIDTH - (CAMERA_WIDTH / 2.f);
        _minCamY = CAMERA_HEIGHT / 2.f;
        _maxCamY = WORLD_HEIGHT - (CAMERA_HEIGHT / 2.f);
    }

    void Camera::move(sf::Vector2f playerPos) {
        _leftBound   = _camCenter.x - (_deadZone.x / 2.f);
        _rightBound  = _camCenter.x + (_deadZone.x / 2.f);
        _topBound    = _camCenter.y - (_deadZone.y / 2.f);
        _bottomBound = _camCenter.y + (_deadZone.y / 2.f);
        
        if (playerPos.x < _leftBound) {
            _camCenter.x -= (_leftBound - playerPos.x);
        } else if (playerPos.x > _rightBound) {
            _camCenter.x += (playerPos.x - _rightBound);
        }

        if (playerPos.y < _topBound) {
            _camCenter.y -= (_topBound - playerPos.y);
        } else if (playerPos.y > _bottomBound) {
            _camCenter.y += (playerPos.y - _bottomBound);
        }

        _camCenter.x = std::clamp(_camCenter.x, _minCamX, _maxCamX);
        _camCenter.y = std::clamp(_camCenter.y, _minCamY, _maxCamY);
        
        setCenter(_camCenter);
    }

    void Camera::draw(sf::RenderWindow& window) {
        window.setView(*this);
    }
}