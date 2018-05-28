#include "Pipe.hpp"

Pipe::Pipe(int h, int gap) {
  rectUp.setFillColor(sf::Color(244, 78, 78));
  rectDown.setFillColor(sf::Color(244, 78, 78));
  rectUp.setSize(sf::Vector2f(20, h));
  rectDown.setSize(sf::Vector2f(20, 600 - gap - h));
  rectUp.setPosition(1000, 0);
  rectDown.setPosition(1000, h + gap);
}

Pipe::~Pipe() { }

void Pipe::draw(sf::RenderWindow &window) {
  window.draw(rectUp);
  window.draw(rectDown);
}

bool Pipe::shouldSpawn() {
  if (rectUp.getPosition().x >= 600 && rectUp.getPosition().x < 603) {
    return true;
  }
}

bool Pipe::shouldRemove() {
  return rectUp.getPosition().x < -25;
}

void Pipe::update() {
  rectUp.move(-3, 0);
  rectDown.move(-3, 0);
}

bool Pipe::shouldIncreaseScore() {
  if (rectUp.getPosition().x <= 80 && hasScore) {
    hasScore = false;
    return true;
  }
  return false;
}

bool Pipe::collides(sf::RectangleShape rectToCollide) {
  return (rectUp.getGlobalBounds().intersects(rectToCollide.getGlobalBounds()) || 
          rectDown.getGlobalBounds().intersects(rectToCollide.getGlobalBounds()));
}