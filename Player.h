#pragma once

#include "Entity.h"

#include "Laser.h"

#include "Meteor.h"
class Player : public Entity
{
public:
	Player();

	//void createHealthBar(); //wanna hide it becuase should nbe accedded outside of the class,  only the contructor can access

	void movePlayer();

	int getInvincibleTime();
	void setInvincibleTime(int newInvincibleTime);

	std::vector<CircleShape> getHealthBar();
	int getScore();
	
	int getLaserTime();
	void setLaserTime(int newLaserTime);

	void invincibleTimeBuffer(int newInvincibleTime);
	void laserTimeBuffer(int newLaserTime);

	void shootLaser();
	void moveLaser();
	void drawLaser(sf::RenderWindow& window);
	bool checkLaserCollision();

	bool checkPlayerCollision();

	void updateScore();

private:
	bool alive;
	
	int score;

	int invincibleTime;
	int laserTime;

	

	//sf::Sprite sprite; //not inheritance  since player class has a relationship with sprite. composition!!!
	Laser laser;

	vector<Laser> laserVec;

	std::vector	<CircleShape> healthBar;
	//sf::CircleShape healthShape; no need because health bar has a circle shap
	//int health; no need
	void createHealthBar();


};

//dog is not a tail tail is not a dog but dog has a tail
//dog is an animal, defining as a part of st
