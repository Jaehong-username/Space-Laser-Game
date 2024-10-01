#pragma once

#include<iostream>
#include<vector>
#include<ctime>
#include"SFML/Graphics.hpp"
#include"SFML/System.hpp"
#include"SFML/Window.hpp"

#include "Player.h"

#include "EnemyLaser.h"

class Enemy : public Entity
{
public:
	Enemy();

	void moveEnemy(); //move the enemy downward at a random velocity and update the position

	void enemyShootLaser();
	void enemyLaserMove();
	void enemyLaserDraw(sf::RenderWindow& window);

	bool checkEnemyOut();
	


private:

	//has a laser function
	float enemyVelocity;
	EnemyLaser enemyLaser;
	vector<EnemyLaser>enemyLaserVec;
};





//class Enemy
//{
//public:
//	Enemy(float og_x, float og_y)
//	{
//		
//		this->shape.setPosition(og_x, og_y);
//		this->shape.setFillColor(sf::Color::White);
//		this->shape.setSize(sf::Vector2f(25.f, 25.f));
//
//	}
//	~Enemy();
//	void move_enemy();
//	void render(sf::RenderWindow& window);
//	bool touches_bottom();
//	sf::FloatRect enemy_boundary();
//
//private:
//
//	sf::RectangleShape shape;
//
//};