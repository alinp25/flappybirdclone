#pragma once

#include <SFML/Graphics.hpp>

class Bird {
  public:
    Bird();
    ~Bird();

    void draw(sf::RenderWindow &window);
    void update();
    void jump();
    bool isAlive();
    void increaseScore();
    int getScore();
    void kill();
    sf::RectangleShape getRect();
  private:
    sf::RectangleShape rect;
    sf::Texture tex;
    sf::Sprite sprite;

    float lift = -10;
    float velo = 0;
    float grav = 0.3;

    int score = 0;

    bool alive;
};