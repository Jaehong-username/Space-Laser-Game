// PA9GameDevelopment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//#include "SFML/Graphics.hpp"
//
//#include <iostream>
//#include <vector>
//using std::vector;
//using sf::Sprite;
//using sf::CircleShape;
//using sf::Color;
//
//int main(int argc, char** argv)
//{
//	sf::RenderWindow renderWindow(sf::VideoMode(1000/*640*/,900/* 480*/), "Hello WOrld!!");
//
//	sf::Event event; //x wanna be within the while loop if we wanna use it over over over again
//
//	//sf::Font font;
//	//if (!font.loadFromFile("calibri.ttf"))
//	//{
//	//	return 42; //just chose random code number 42
//	//}
//	//sf::Text text("Hello WOrld", font, 64);
//	//text.setFillColor(sf::Color::Red); //setFillColor!
//
//	sf::Texture player1;
//	if (!player1.loadFromFile("playerShip1_blue.png"))
//	{
//		return 43; //just chose random code number 43
//	}
//	sf::Sprite spritePlayer1(player1);
//
//	sf::FloatRect bounds1(spritePlayer1.getLocalBounds());
//
//	spritePlayer1.setPosition(renderWindow.getSize().x/2 - (bounds1.left + bounds1.width / 2),
//		                      renderWindow.getSize().y/2 - (bounds1.top + bounds1.height / 2));
//	//sprite is all about positioning and drawing!!! sprite is light heavy class
//
//	//sf::Texture laser1;
//	//if (!laser1.loadFromFile("laserBlue01.png"))
//	//{
//	//	return 42; //just chose random code number 42
//	//}
//	////sf::Sprite laser1(laser1);
//	//vector<sf::Sprite> laser1Vector;
//	
//	//Laser!
//	CircleShape laser1;
//	laser1.setFillColor(Color::Green);
//	laser1.setRadius(5.f);
//	std::vector<CircleShape> laser1Projectiles;
//	laser1Projectiles.push_back(CircleShape(laser1)); 
//
//
//
//
//
//
//	while (renderWindow.isOpen())
//	{
//		//1/60 sec usually since the draw function
//		while (renderWindow.pollEvent(event)) //return false when there are no events //once event buffer has been cleared.
//		{ //like close move or mouse move etc
//			if (event.type == sf::Event::EventType::Closed)
//			{
//				renderWindow.close();
//			}
//			//here I am just gonna add more commands! like left or right
//			if (event.type == sf::Event::EventType::KeyPressed)
//			{
//				printf("%d\n", (int)event.key.code);
//				// Event driven input handling
//				if (event.key.code == sf::Keyboard::Left)
//					spritePlayer1.move(-15.f, 0); //Relative transform
//				if (event.key.code == sf::Keyboard::Right)
//					spritePlayer1.move(15.f, 0);
//				if (event.key.code == sf::Keyboard::Up)
//					spritePlayer1.move(0, -15.f); //Relative transform
//				if (event.key.code == sf::Keyboard::Down)
//					spritePlayer1.move(0, 15.f);
//				/*if (event.key.code == sf::Keyboard::Left && event.key.code == sf::Keyboard::Up)
//					spritePlayer1.move(-15.f, -15.f);
//				if (event.key.code == sf::Keyboard::Left && event.key.code == sf::Keyboard::Down)
//					spritePlayer1.move(-15.f, 15.f);
//				if (event.key.code == sf::Keyboard::Right && event.key.code == sf::Keyboard::Up)
//					spritePlayer1.move(15.f, -15.f);
//				if (event.key.code == sf::Keyboard::Right && event.key.code == sf::Keyboard::Down)
//					spritePlayer1.move(15.f, 15.f);*/
//
//
//					//shooting a laser
//				if (event.key.code == sf::Keyboard::Space)
//				{
//					 /*sf::Sprite* pMem = new sf::Sprite();
//					 laser1Vector.push_back(*pMem);
//					 pMem->setPosition(spritePlayer1.getPosition().x, spritePlayer1.getPosition().y);
//					 renderWindow.draw(*pMem);*/
//					laser1.setPosition(spritePlayer1.getPosition());
//					laser1Projectiles.push_back(laser1);
//
//
//				}
//
//			}
//
//			
//		}
//
//		for (int i = 0; i < laser1Projectiles.size(); i++) //updating!! part after event polling
//		{
//			laser1Projectiles[i].move(0.f, -.1f); //
//
//			if (laser1Projectiles[i].getPosition().y < 0) //if the laser is outside of the windowe
//			{                                //pointer to the begining of the vector ptr arithmetic
//				laser1Projectiles.erase(laser1Projectiles.begin() + i);
//			}
//		}
//
//		//then clear the window and display
//		renderWindow.clear(sf::Color::White);
//		//renderWindow.draw(text); //must be with in the display fuc!
//		renderWindow.draw(spritePlayer1);
//		for (int i = 0; i < laser1Projectiles.size(); i++)
//		{
//
//			renderWindow.draw(laser1Projectiles[i]);
//		}
//
//		renderWindow.display();
//
//		
//	}
//
//}
//
//
//
////int main()
////{
////    std::cout << "Hello World!\n";
////}
//
//// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
//// Debug program: F5 or Debug > Start Debugging menu
//
//// Tips for Getting Started: 
////   1. Use the Solution Explorer window to add/manage files
////   2. Use the Team Explorer window to connect to source control
////   3. Use the Output window to see build output and other messages
////   4. Use the Error List window to view errors
////   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
////   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
//
//
//
//
//int main{
//
//	startup part which is initializing like vector for example this part goes to the private sector of
//	Application class.
//
//	//main loop function (this is a main func). while (window.isopen()
//
//	//handle events: while (event poll( {  handke events}
//
//	//upadting move projectiles after the handle event parts. (should be written outside of the inner loop)
//
//	//draw projectiles : thiws is more of an displaying an outpuit after the going through handle events and update.
//
//	//order handle events -> update -> draw  this 3-step cycle goes on and on and on.
//
//
//
//
//	gets inputs and stores them on the poll event buffer after the all elements on the biffer removed
//	no we can move on to the update function part. (gets inputs within timeframe of 1/60 seconds on the buffer)
//
//	Update (laser whiuch instantiated from handle event by pressing keyboard) will keep moving until
//	the laser goes out of the screen
//
//
//
//	class Application
//{
//public:
//	//four func needed
//	1. main loop while the window is opene (within this main func, 2 3 4 func will be inclueded)
//	2. handle events func
//	3. update function
//	4. draw function
//
//
//private:
//	Player1;
//	vecotr laser;
//	vector enemies;
//	Map; etc
//}
//
//
//int main()
//{
//	Application app;
//	app.run();
//	return 0;
//}
//
//
////randomly spawn enemies we gonna destroy the enemies randomly data structure queue and stack out because
//both two are not meant to be accessed randomnly rather we should use vector not array becuase array is not resizable
//vecotor is a good choice in terms of randomly respawning the enemy.