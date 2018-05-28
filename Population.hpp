#pragma once
#include "Bird.hpp"
#include <vector>


class Population {
  public:
    Population(int x);
    ~Population();
    void draw(sf::RenderWindow &window);
  private:
    std::vector<Bird> birds;
};