#pragma once

#include "SFML/Graphics.hpp"

#include "Laser.h"

#include <iostream>

#include <vector>

using std::vector;
using sf::CircleShape;
using sf::Color;
using sf::Sprite;
using sf::Vector2f;

using std::cin;
using std::cout;
using std::endl;

using std::vector;

class Entity : virtual public sf::Sprite
{
public:
	Entity();
	/*Vector2f getPosition();
	void setPosition(Vector2f newPosition);*/ //no need!!!

protected:
	Vector2f position;
	
	//Entity has a laser;
};