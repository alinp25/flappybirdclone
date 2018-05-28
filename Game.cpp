#include "Game.hpp"

#include <cstdlib>
#include <ctime>

int randomHeight() {
  return rand() % 450;
}

int randomGap() {
  return rand() % 150 + 150;
}

Game::Game() {
  window.create(sf::VideoMode(800, 600), "Flappy Bird!");
  window.setFramerateLimit(60);

  srand(time(NULL));

  Pipe pip(randomHeight(), randomGap());
  pipes.push_back(pip);
}

Game::~Game() { }

void Game::run() {
  std::cout << "Game Started!";
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space && bird.isAlive()) {
          bird.jump();
        }
      }
    }

    window.clear(sf::Color(171, 158, 237));

    if (bird.isAlive()) {
      bird.update();
    }
    for (int i = 0; i < pipes.size(); i++) {
      pipes[i].update();
      if (pipes[i].shouldSpawn()) {
        Pipe pip(randomHeight(), randomGap());
        pipes.push_back(pip);
      }
      if (pipes[i].shouldRemove()) {
        pipes.erase(pipes.begin() + 0);
      }

      if (pipes[i].shouldIncreaseScore()) {
        if (bird.isAlive()) {
          bird.increaseScore();
          std::cout << bird.getScore() << "\n";
        }
      }
    }

    for (int i = 0; i < pipes.size(); i++) {
      pipes[i].draw(window);
      if (pipes[i].collides(bird.getRect())) {
        bird.kill();
      }
    }

    if (bird.isAlive()) {
      bird.draw(window);
    }
    window.display();
  }
}