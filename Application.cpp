#include "Application.h"

Application::Application()
{
	sf::RenderWindow window(sf::VideoMode(1000, 900), "PA9 Spacecraft shooter game!"); //constructor
	window.setFramerateLimit(60);
	enemySpawnTime = 30;

	//Meteor meteor1((0,0), Color Red);
	//meteorVec.push_back(meteor1);
	//Meteor meteor2();
	//meteorVec.push_back(meteor2);
	//Meteor meteor3();
	//meteorVec.push_back(meteor3);
	
}

vector<Enemy> Application::getEnemyVec()
{
	return enemyVec;
}

vector<Meteor> Application::getMeteorVec()
{
	return meteorVec;
}

void Application::enemySpawn()
{
	if (enemySpawnTime >= 30)
	{
		Enemy enemy; //create an enemy object
		enemy.setPosition(rand() % 1000, 0); //set position randomly
		enemyVec.push_back(enemy);
		enemySpawnTime = 0;
	}
	

}

void Application::moveEnemies()
{
	for (int i = 0; enemyVec.size(); i++)
	{
		enemyVec[i].moveEnemy();
	}
}

void Application::drawEnemies() //draw the enemy
{
	for (int i = 0; enemyVec.size(); i++)
	{
		window.draw(enemyVec[i]);
	}
}

void Application::checkEnemyOut()
{
	for (int i = 0; enemyVec.size(); i++)
	{
		if (enemyVec[i].getPosition().y > window.getSize().y)
		{
			enemyVec.erase(enemyVec.begin() + i);
		}
	}
}



void Application::moveMeteors()
{
	for (int i = 0; i < meteorVec.size(); i++)
	{
		meteorVec[i].moveMeteor();
	}
}

void Application::drawMeteors(sf::RenderWindow& window)
{
	for (int i = 0; i < meteorVec.size(); i++)
	{
		meteorVec[i].drawMeteor(window);
	}
}

void Application::run()
{
	Menu menu(1000, 900);

	// run the program as long as the window is open
	while (window.isOpen()) //load the window process
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player.getLaserTime() >= 20)
			{
				player.shootLaser();
				player.setPosition(player.getPosition().x + 45, player.getPosition().y - 55);

				player.setLaserTime(0);
			}
		}

		//////////////////////////////////////////Update//////////////////////////////////////////////
		player.movePlayer();
		player.moveLaser();
		
		this->enemySpawn();
		this->moveEnemies();

		this->moveMeteors();
		////////////////////////////////////Skil Buffer//////////////////////////////////////////////////////
		if (player.getInvincibleTime() < 100) player.setInvincibleTime(player.getInvincibleTime() + 1);
		if (player.getLaserTime() < 20) player.setLaserTime(player.getLaserTime() + 1);
		if (enemySpawnTime < 30) enemySpawnTime++;

		////////////////////////////////////////output///////////////////////////////////////////////////
		 // clear the window with black color
		window.clear(sf::Color::Black);
		player.drawLaser(window);
		this->drawEnemies();
		this->drawMeteors(window);

		window.display();
			
	}

}
