#include "Bird.hpp"

Bird::Bird() {
  tex.loadFromFile("./assets/bird.png");
  rect.setSize(sf::Vector2f(17, 12));
  rect.setScale(2, 2);
  sprite.setScale(2, 2);
  sprite.setTexture(tex);
  rect.setPosition(100, 300);
  sprite.setPosition(rect.getPosition());
  // accelerationDown = 5;
  alive = true;
}

Bird::~Bird() { }

void Bird::draw(sf::RenderWindow &window) {
  window.draw(sprite);
}

void Bird::update() {
  velo += grav;
  rect.move(0, velo);
  if (rect.getPosition().y > 580) {
    velo = 0;
    grav = 0;
    lift = 0;
    kill();
  }
  sprite.setPosition(rect.getPosition());
}

void Bird::jump() {
  velo += lift;
}

bool Bird::isAlive() {
  return alive;
}

void Bird::increaseScore() {
  score++;
}

int Bird::getScore() {
  return score;
}

void Bird::kill() {
  alive = false;
}

sf::RectangleShape Bird::getRect() {
    return rect;
}
