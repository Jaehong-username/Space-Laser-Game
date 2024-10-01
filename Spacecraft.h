#pragma once

#include "SFML/Graphics.hpp"

#include <iostream>

#include <vector>

using std::vector;
using sf::CircleShape;
using sf::Color;

class Spacecraft
{
public:

	Spacecraft(const sf::Vector2f& pos);

	bool isAlive();

	void shootLasers();

	float getxDir();
	float getyDir();
	void setxDir(float newxDir);
	void setyDir(float newyDir);

	bool isHit(sf::Sprite enemyLaser);

private:

	float xDir;
	float yDir;
	int health;
	bool alive;

	vector<CircleShape> vecLaser;


};
