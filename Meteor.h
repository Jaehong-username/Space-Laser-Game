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

class Meteor : public Sprite
{
public:
	Meteor(Vector2f initPos, sf::Color color);
	void moveMeteor();
	void drawMeteor(sf::RenderWindow& window);
private:
	Vector2f position;
	//float meteorVelocity;
};