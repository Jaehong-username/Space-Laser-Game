#include"Enemy.h"

//Enemy::~Enemy()
//{
//
//}
//
//void Enemy::move_enemy()
//{
//	this->shape.move(0.1f, 5.f); //this will move the ship 
//}
//
//void Enemy::render(sf::RenderWindow& window)
//{
//	window.draw(this->shape); 
//}
//
//bool Enemy::touches_bottom()//will return yes if touches the bottom
//{
//	return this->shape.getPosition().y + this->shape.getSize().y >= 900;
//}
//
//sf::FloatRect Enemy::enemy_boundary()
//{
//	return shape.getGlobalBounds();//this will return the boundary
//}

Enemy::Enemy() : Entity() //public inheritance to Entity
{
	this->setColor(Color::Red); //change the color to red
	this->setScale(0.5f, 0.5f); //change the size
	this->setPosition(rand() % 1000, 0); //set the position to random

	enemyVelocity = rand() % 20 + 1;
}

void Enemy::moveEnemy()
{
	this->move(0, enemyVelocity);
	this->setPosition(this->getPosition().x, this->getPosition().y + enemyVelocity);
}

void Enemy::enemyShootLaser()
{
	EnemyLaser enemyLaser;
	enemyLaser.setPosition(this->getPosition().x + 45, this->getPosition().x + 55);
	enemyLaserVec.push_back(enemyLaser);
}

void Enemy::enemyLaserMove()
{
	for (int i = 0; i < enemyLaserVec.size(); i++)
	{
		enemyLaserVec[i].moveLaser();

		if (enemyLaserVec[i].checkLaserOut())
		{
			enemyLaserVec.erase(enemyLaserVec.begin() + i);
		}
	}
}

void Enemy::enemyLaserDraw(sf::RenderWindow& window) //draw the enemy laser
{
	for (int i = 0; i < enemyLaserVec.size(); i++)
	{
		window.draw(enemyLaserVec[i]);
	}
}

bool Enemy::checkEnemyOut()
{
	return false;
}
