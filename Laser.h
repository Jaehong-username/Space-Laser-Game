#pragma once

#include<ctime>
#include"SFML/Graphics.hpp"
#include"SFML/System.hpp"
#include"SFML/Window.hpp"

#include <iostream>

//Laser is a sprite!!!
class Laser : public sf::Sprite
{
public:
	Laser();
	
	virtual void moveLaser();

	virtual bool checkLaserOut();

protected:
	sf::Vector2f laserPosition;
	float laserVelocity;

};