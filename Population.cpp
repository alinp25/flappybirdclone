#include "Population.hpp"

Population::Population(int x) {
  for (int i = 0; i < x; i++) {
    Bird brd;
    birds.push_back(brd);
  }
}

Population::~Population() { }

void Population::draw(sf::RenderWindow &window) {
  for (int i = 0; i < birds.size(); i++) {
    if (birds[i].isAlive()) {
      birds[i].draw(window);
    }
  }
}

