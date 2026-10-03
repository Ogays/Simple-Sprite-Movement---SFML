#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <algorithm>
#include "../include/Player.h"

namespace Ogay {

    Player::Player() {
        if (!_textureUp.loadFromFile(SPRITE_UP_FILEPATH))
            EXIT_FAILURE;
        if (!_textureDown.loadFromFile(SPRITE_DOWN_FILEPATH))
            EXIT_FAILURE;
        if (!_textureLeft.loadFromFile(SPRITE_LEFT_FILEPATH))
            EXIT_FAILURE;
        if (!_textureRight.loadFromFile(SPRITE_RIGHT_FILEPATH))
            EXIT_FAILURE;

        setTexture(_textureDown);
        _direction = Direction::DOWN;
        setTextureRect(sf::IntRect(0, 0, 32, 32));
        setOrigin(15.f, 15.f);
        setPosition(sf::Vector2f(100.0f, 100.0f));
        _switchTime = 0.1f;
        _totalTime = 0.0f;
    }

    void Player::draw(sf::RenderWindow& window) {
        window.draw(*this);
    }

    void Player::moves(sf::Vector2f delta, Direction direction) {
        float newX = getPosition().x + delta.x;
        float newY = getPosition().y + delta.y;
        setPosition(std::clamp(newX, 0.f, 650.f), std::clamp(newY, 0.f, 650.f));

        switch (direction) {
            case Direction::UP:
                setTexture(_textureUp);
                break;
            case Direction::DOWN:
                setTexture(_textureDown);
                break;
            case Direction::LEFT:
                setTexture(_textureLeft);
                break;
            case Direction::RIGHT:
                setTexture(_textureRight);
                break;
        }
    }

    sf::FloatRect Player::getGlobalBound() {
        return this->getGlobalBounds();
    }

    sf::Vector2f Player::getPositions() {
        return this->getPosition();
    }

    void Player::setPositions(sf::Vector2f position) {
        this->setPosition(position);
    }

    void Player::setMovement(bool isMoving, float deltaTime) {
        if (isMoving) {
            _totalTime += deltaTime;
            if (_totalTime >= 0.1f) {
                _totalTime -= _switchTime;
                _currentFrame = (_currentFrame + 1) % _frameCount;
            }
        } else {
            _currentFrame = 0;
        }
        setTextureRect(sf::IntRect(_currentFrame * 32, 0, 32, 32));
    }
}