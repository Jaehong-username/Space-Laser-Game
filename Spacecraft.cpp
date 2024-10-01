#include "Spacecraft.h"



Spacecraft::Spacecraft(const sf::Vector2f &pos)
{
	health = 100;
	alive = true;
	xDir = 100;
	yDir = 100;
}

bool Spacecraft::isAlive()
{
	if (health == 0) return false;
	return true;
}



void Spacecraft::shootLasers()
{
	CircleShape laser;
	laser.setFillColor(Color::Green);
	laser.setRadius(5.f);
	laser.setPosition(xDir, yDir - 10);
	//Laser* laser = new Laser();
	vecLaser.push_back(laser);

	for (int i = 0; i < vecLaser.size(); i++) //updating!! part after event polling
	{
		vecLaser[i].move(0.f, -10.f); //

		if (vecLaser[i].getPosition().y < 0) //if the laser is outside of the windowe
		{                                //pointer to the begining of the vector ptr arithmetic
			vecLaser.erase(vecLaser.begin() + i);
		}
	}

}

float Spacecraft::getxDir()
{
	return xDir;
}

float Spacecraft::getyDir()
{
	return yDir;
}

void Spacecraft::setxDir(float newxDir)
{
	xDir = newxDir;
}

void Spacecraft::setyDir(float newyDir)
{
	yDir = newyDir;
}

bool Spacecraft::isHit(sf::Sprite enemyLaser)
{
	if (enemyLaser.getPosition().x == this->getxDir() && enemyLaser.getPosition().y == this->getyDir())
	{
		health = health - 10;
		return true;
	}
	
	return false;
}
