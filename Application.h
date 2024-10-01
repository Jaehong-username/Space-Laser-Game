#pragma once

#pragma once

#include "Player.h"

#include "Enemy.h"

#include "Menu.h"

class Application
{
public:

	Application();

	static vector<Enemy> getEnemyVec();

	static vector<Meteor> getMeteorVec();

	void enemySpawn();
	void moveEnemies();
	void drawEnemies();
	void checkEnemyOut();

	
	void moveMeteors();
	void drawMeteors(sf::RenderWindow& window);

	void run();

private: //application class has a relationship with player class
	static vector<Enemy>enemyVec;

	static vector<Meteor>meteorVec;

	Player player;

	sf::RenderWindow window;

	int enemySpawnTime;
};



//#include "Application.h"
//
//void Application::run()
//{
//	//starting point
//	sf::RenderWindow renderWindow(sf::VideoMode(1000/*640*/, 900/* 480*/), "Hello WOrld!!"); //window
//
//	sf::Texture player1;
//	if (!player1.loadFromFile("playerShip1_blue.png"))
//	{
//		return; //just chose random code number 43
//	}
//	sf::Sprite spritePlayer1(player1);
//	sf::FloatRect bounds1(spritePlayer1.getLocalBounds()); //getting the bounds of the player
//
//	//putting in the center position
//	spritePlayer1.setPosition(renderWindow.getSize().x / 2 - (bounds1.left + bounds1.width / 2),
//		renderWindow.getSize().y / 2 - (bounds1.top + bounds1.height / 2));
//
//
//	
//	CircleShape laser1;
//	laser1.setFillColor(Color::Green);
//	laser1.setRadius(100.f);
//	laser1.setPosition(200,200);
//
//
//	std::vector<CircleShape> laser1Projectiles;
//	laser1Projectiles.push_back(CircleShape(laser1)); //vector defined in the space craft function
//
//	while (renderWindow.isOpen())
//	{
//	
//
//		renderWindow.draw(laser1);
//
//		//1/60 sec usually since the draw function
//		while (renderWindow.pollEvent(event)) //return false when there are no events //once event buffer has been cleared.
//		{ //like close move or mouse move etc
//			if (event.type == sf::Event::EventType::Closed)
//			{
//				renderWindow.close();
//			}
//		}
//
//			//here I am just gonna add more commands! like left or right
//			if (event.type == sf::Event::EventType::KeyPressed) //font or music // time   
//			{
//				printf("%d\n", (int)event.key.code);
//				// Event driven input handling
//				if (event.key.code == sf::Keyboard::Left)
//					spritePlayer1.move(-.1f, 0); //Relative transform
//				if (event.key.code == sf::Keyboard::Right)
//					spritePlayer1.move(.1f, 0);
//				if (event.key.code == sf::Keyboard::Up)
//					spritePlayer1.move(0, -.1f); //Relative transform
//				if (event.key.code == sf::Keyboard::Down)
//					spritePlayer1.move(0, .1f);
//
//
//
//				//shooting a laser
//				if (event.key.code == sf::Keyboard::Space)
//				{
//					/*sf::Sprite* pMem = new sf::Sprite();
//					laser1Vector.push_back(*pMem);
//					pMem->setPosition(spritePlayer1.getPosition().x, spritePlayer1.getPosition().y);
//					renderWindow.draw(*pMem);*/
//					//laser1.setPosition(spritePlayer1.getPosition());
//					//laser1Projectiles.push_back(laser1);
//					
//		
//				}
//
//				/*while (laser1Projectiles[i].getPosition().y >= 0)
//				{
//					laser1Projectiles[i].move(0.f, -.1f);
//				}*/
//
//			}
//
//			//Updating!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//			for (int i = 0; i < laser1Projectiles.size(); i++) //updating!! part after event polling
//			{
//				laser1Projectiles[i].move(0.f, -10.f); //
//
//				if (laser1Projectiles[i].getPosition().y < 0) //if the laser is outside of the windowe
//				{                                //pointer to the begining of the vector ptr arithmetic
//					laser1Projectiles.erase(laser1Projectiles.begin() + i);
//				}	
//			}
//			
//			
//
//
//
//			//output!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//			//then clear the window and display
//			renderWindow.clear(sf::Color::White);
//			//renderWindow.draw(text); //must be with in the display fuc!
//			renderWindow.draw(spritePlayer1);
//			for (int i = 0; i < laser1Projectiles.size(); i++)
//			{
//
//				
//			}
//
//			renderWindow.draw(laser1);
//			renderWindow.display();
//		
//	}
//	
//}
//
////void Application::handleEvent()
////{
////	//1/60 sec usually since the draw function
////	while (renderWindow.pollEvent(event)) //return false when there are no events //once event buffer has been cleared.
////	{ //like close move or mouse move etc
////		if (event.type == sf::Event::EventType::Closed)
////		{
////			renderWindow.close();
////		}
////		//here I am just gonna add more commands! like left or right
////		if (event.type == sf::Event::EventType::KeyPressed)
////		{
////			printf("%d\n", (int)event.key.code);
////			// Event driven input handling
////			if (event.key.code == sf::Keyboard::Left)
////				spritePlayer1.move(-15.f, 0); //Relative transform
////			if (event.key.code == sf::Keyboard::Right)
////				spritePlayer1.move(15.f, 0);
////			if (event.key.code == sf::Keyboard::Up)
////				spritePlayer1.move(0, -15.f); //Relative transform
////			if (event.key.code == sf::Keyboard::Down)
////				spritePlayer1.move(0, 15.f);
////			/*if (event.key.code == sf::Keyboard::Left && event.key.code == sf::Keyboard::Up)
////				spritePlayer1.move(-15.f, -15.f);
////			if (event.key.code == sf::Keyboard::Left && event.key.code == sf::Keyboard::Down)
////				spritePlayer1.move(-15.f, 15.f);
////			if (event.key.code == sf::Keyboard::Right && event.key.code == sf::Keyboard::Up)
////				spritePlayer1.move(15.f, -15.f);
////			if (event.key.code == sf::Keyboard::Right && event.key.code == sf::Keyboard::Down)
////				spritePlayer1.move(15.f, 15.f);*/
////
////
////				//shooting a laser
////			if (event.key.code == sf::Keyboard::Space)
////			{
////				/*sf::Sprite* pMem = new sf::Sprite();
////				laser1Vector.push_back(*pMem);
////				pMem->setPosition(spritePlayer1.getPosition().x, spritePlayer1.getPosition().y);
////				renderWindow.draw(*pMem);*/
////				laser1.setPosition(spritePlayer1.getPosition());
////				laser1Projectiles.push_back(laser1);
////			}
////		}
////	}
////}
//
////void Application::update()
////{
////	for (int i = 0; i < laser1Projectiles.size(); i++) //updating!! part after event polling
////	{
////		laser1Projectiles[i].move(0.f, -.1f); //
////
////		if (laser1Projectiles[i].getPosition().y < 0) //if the laser is outside of the windowe
////		{                                //pointer to the begining of the vector ptr arithmetic
////			laser1Projectiles.erase(laser1Projectiles.begin() + i);
////		}
////	}
////}
//
////void Application::output()
////{
////	//then clear the window and display
////	renderWindow.clear(sf::Color::White);
////	//renderWindow.draw(text); //must be with in the display fuc!
////	renderWindow.draw(spritePlayer1);
////	for (int i = 0; i < laser1Projectiles.size(); i++)
////	{
////
////		renderWindow.draw(laser1Projectiles[i]);
////	}
////
////	renderWindow.display();
////}

