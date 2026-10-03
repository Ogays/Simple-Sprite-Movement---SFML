#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "include/DEFINITION.h"
#include "include/Player.h"
#include "include/Wall.h"
#include "include/Camera.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Simple Sprite Move - SFML");

    Ogay::Player player;
    Ogay::Wall wall;
    Ogay::Camera camera;

    bool isMoving = false;
    sf::Vector2f delta;
    sf::Vector2f oldPosition;
    sf::Clock clock;
    float speed = 75.f;
    Direction direction = Direction::DOWN;

    while (window.isOpen()) {

        float deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        oldPosition = player.getPositions();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            delta = sf::Vector2f(-speed * deltaTime, 0.0f);
            direction = Direction::LEFT;
            isMoving = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            delta = sf::Vector2f(speed * deltaTime, 0.0f);
            direction = Direction::RIGHT;
            isMoving = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            delta = sf::Vector2f(0.0f, -speed * deltaTime);
            direction = Direction::UP;
            isMoving = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            delta = sf::Vector2f(0.0f, speed * deltaTime);
            direction = Direction::DOWN;
            isMoving = true;
        }

        if (event.type == sf::Event::KeyReleased) {
            delta = sf::Vector2f(0.0f, 0.0f);
            isMoving = false;
        }

        player.moves(delta, direction);

        if (wall.isCollide(player.getGlobalBound())) {
            player.setPositions(oldPosition);
            isMoving = false;
        }
        player.setMovement(isMoving, deltaTime);
        camera.move(player.getPositions());

        window.clear(sf::Color(80, 03, 192));
        camera.draw(window);
        player.draw(window);
        wall.draw(window);

        window.display();
    }

    return 0;
}