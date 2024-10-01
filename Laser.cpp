#include"Laser.h"
#include <iostream>
Laser::Laser() : Sprite()
{
    sf::Texture laser;
    if (!laser.loadFromFile("laserBlue01.png")) std::cout << "laser image is not loaded to the correct directory!\n" << std::endl;

    this->setTexture(laser);
	laserVelocity = 15.0f;

    //initially
    laserPosition.x = 0;
    laserPosition.y = 0;
}

void Laser::moveLaser()
{
    this->move(0, -laserVelocity);
    laserPosition.y -= laserVelocity;
}

bool Laser::checkLaserOut()
{
    if (laserPosition.y < 0) return true;
   
    return false;
}



