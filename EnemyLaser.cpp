#include "EnemyLaser.h"

EnemyLaser::EnemyLaser() : Laser()
{
    sf::Texture laser;
    if (!laser.loadFromFile("laserBlue01.png")) std::cout << "laser image is not loaded to the correct directory!\n" << std::endl;

    this->setTexture(laser);
    this->setColor(sf::Color::Red);
    
    laserVelocity = 3.0f;
}

void EnemyLaser::moveLaser()
{
    this->move(0, +laserVelocity);
    laserPosition.y += laserVelocity;
}

bool EnemyLaser::checkLaserOut()
{
    if (laserPosition.y > 900) return true;

    return false;
}
