#pragma once

#include <SFML/Graphics.hpp>

class Pipe {
  public:
    Pipe(int h, int gap);
    ~Pipe();
    void draw(sf::RenderWindow &window);
    void update();
    bool shouldSpawn();
    bool shouldIncreaseScore();
    bool shouldRemove();
    bool collides(sf::RectangleShape rectToCollide);
  private:
    sf::RectangleShape rectUp;
    sf::RectangleShape rectDown;

    bool hasScore = true;
};