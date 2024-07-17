#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>

using namespace std;

namespace Game {
  sf::Clock typedef Clock;
  sf::Time typedef Time;
  sf::Event typedef Event;
  sf::RenderWindow typedef Window;
  sf::VideoMode typedef VideoMode;
  sf::IntRect typedef Box;
  sf::RectangleShape typedef Rectangle;
  sf::CircleShape typedef Circle;
  sf::Sprite typedef Sprite;
  sf::Texture typedef Texture;
  sf::Keyboard typedef Keyboard;
  sf::Color typedef Color;

  template <typename T> 
    using Vector = sf::Vector2<T>;
};