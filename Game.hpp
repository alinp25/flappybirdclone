#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bird.hpp"
#include "Pipe.hpp"

#include <vector>

class Game {
  public:
    Game();
    ~Game();
    void run();
  private:
    sf::RenderWindow window;

    bool isRunning;

    Bird bird;
    std::vector<Pipe> pipes;
};