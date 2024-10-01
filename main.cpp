
#include "Application.h"

int main(void)
{
    srand(time(NULL));
	Application program;
	program.run();
	//program.run();*/
 //   // create the window  //640 480  
 //   sf::RenderWindow window(sf::VideoMode(1000, 900), "PA9 Spacecraft shooter game!"); //constructor
 //   window.setFramerateLimit(60);
 //   //window.setKeyRepeatEnabled(true);

 //   Menu menu(1000, 900);
 //   

 //   sf::Texture player1;
 //   if (!player1.loadFromFile("playerShip1_blue.png")) cout << "playerShip image is not loaded to the correct directory!\n" << endl;
 //   sf::Sprite playerSprite1;
 //   playerSprite1.setTexture(player1);
 //   //playerSprite1.setPosition(sf::Vector2f(10.f, 50.f)); // absolute position
 //   //playerSprite1.move(sf::Vector2f(5.f, 10.f)); //( offset relative to the current position
 //   sf::FloatRect bounds1(playerSprite1.getLocalBounds()); //getting the bounds of the player
 //   playerSprite1.setPosition(window.getSize().x / 2 - (bounds1.left + bounds1.width / 2),
 //       window.getSize().y / 2 - (bounds1.top + bounds1.height / 2));

 //   sf::Vector2f playerPos(playerSprite1.getPosition()); //player Position vector


 //   sf::Texture laser;
 //   if (!laser.loadFromFile("laserBlue01.png")) cout << "laser image is not loaded to the correct directory!\n" << endl;
 //   sf::Sprite laserSprite;
 //   laserSprite.setTexture(laser);
 //   sf::Vector2f laserPos;
 //   

 //   std::vector<sf::Sprite> laserProjectiles;

 //   
 //   
 //   std::vector<Enemy> enemyVector;


 //   //asteroids!!!
 //   float xVelocity = 3.f;
 //   float yVelocity = 3.f;

 //   sf::CircleShape octagon(20.f, 8);
 //   octagon.setFillColor(Color::Blue);
 //   sf::Vector2f octagonPos(15.f, 15.f);

 //   sf::CircleShape triangle(20.f, 3);
 //   triangle.setFillColor(Color::Green);
 //   sf::Vector2f trianglePos(25.f, 25.f);

 //   sf::CircleShape pentagon(20.f, 5);
 //   triangle.setFillColor(Color::Yellow);
 //   sf::Vector2f pentagonPos(50.f, 50.f);

 //   sf::RectangleShape rect;
 //   sf::Vector2f rectanglePos(75.f, 75.f);
 //   rect.setPosition(rectanglePos);
 //   rect.setSize(sf::Vector2f (100,100));
 //   rect.setFillColor(Color::Magenta);



 //   std::vector<CircleShape> healthBar;
 //   float updatedxPos = 5.f;
 //   for (int i = 0; i < 10; i++)
 //   {
 //       sf::CircleShape healthShape;
 //       healthShape.setFillColor(Color:: Red);
 //       healthShape.setRadius(10.f);
 //       healthShape.setPosition(updatedxPos, 20.f);
 //       healthBar.push_back(healthShape);

 //       updatedxPos += 20.f;
 //   }
 //  

 //   


 //   int invincibleTime = 100;
 //   int laserTime = 20;
 //  
 //   int score = 0;

 //   int enemySpawnTime = 30;


 //   // run the program as long as the window is open
 //   while (window.isOpen()) //load the window process
 //   {
 //      
 //       // check all the window's events that were triggered since the last iteration of the loop
 //       sf::Event event;
 //       while (window.pollEvent(event))
 //       {
 //        
 //           // "close requested" event: we close the window
 //           if (event.type == sf::Event::Closed)
 //               window.close();

 //           if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && laserTime >= 20)
 //           {
 //               laserSprite.setPosition(playerPos.x + 45, playerPos.y - 55);
 //               laserProjectiles.push_back(laserSprite);
 //               laserTime = 0;
 //           }
 //       }

 //       
 //       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && playerSprite1.getPosition().x >= 0)
 //       {
 //           playerSprite1.move(-20.f, 0);
 //           playerPos.x -= 20.f;
 //       }

 //       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && playerSprite1.getPosition().x <= 1000 - 100)
 //       {
 //           playerSprite1.move(+20.f, 0);
 //           playerPos.x += 20.f;
 //       }

 //       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && playerSprite1.getPosition().y >= 0)
 //       {
 //           playerSprite1.move(0, -20.f);
 //           playerPos.y -= 20.f;
 //       }

 //       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && playerSprite1.getPosition().y <= 900 - 100)
 //       {
 //           playerSprite1.move(0, +20.f);
 //           playerPos.y += 20.f;
 //       }

 //       
 //       /////////////////////////////////////////Update//////////////////////////////////////////////////////////////////

 //       Enemy enemy(rand() % 500, 0);
 //        //Enemy creation/////////////////////////////////////////////////
 //       if (enemySpawnTime == 30)
 //       {
 //           enemyVector.push_back(enemy);
 //           enemySpawnTime = 0;
 //       }

 //       for (int i = 0; i < laserProjectiles.size(); i++)
 //       {
 //           
 //           laserProjectiles[i].move(0, -15.f);
 //           laserProjectiles[i].setPosition(laserProjectiles[i].getPosition().x, laserProjectiles[i].getPosition().y -15.f);
 //           //printf("%d, %d\n", laserProjectiles[i].getPosition().x, laserProjectiles[i].getPosition().y);
 //           /*if (laserProjectiles[i].getPosition().y < 0)
 //           {
 //               laserProjectiles.erase(laserProjectiles.begin()+i);
 //           }*/
 //          
 //           if (octagon.getGlobalBounds().intersects(laserProjectiles[i].getGlobalBounds()) ||
 //               triangle.getGlobalBounds().intersects(laserProjectiles[i].getGlobalBounds()) || 
 //               pentagon.getGlobalBounds().intersects(laserProjectiles[i].getGlobalBounds()) || 
 //               rect.getGlobalBounds().intersects(laserProjectiles[i].getGlobalBounds()))
 //           {
 //               cout << "Hit it with the laser! Score +1!" << endl;
 //               score++;
 //               laserProjectiles.erase(laserProjectiles.begin() + i);
 //               printf("Current Score: %d\n", score);
 //           }
 //        
 //       }


 //       if (octagonPos.x < 0 || octagonPos.x > 1000 - 40) xVelocity *= -1;
 //       if (octagonPos.y < 0 || octagonPos.y > 900 - 40) yVelocity *= -1;
 //       if (trianglePos.x < 0 || trianglePos.x > 1000 - 40) xVelocity *= -1;
 //       if (trianglePos.y < 0 || trianglePos.y > 900 - 40) yVelocity *= -1;
 //       if (pentagonPos.x < 0 || pentagonPos.x > 1000 - 40) xVelocity *= -1;
 //       if (pentagonPos.y < 0 || pentagonPos.y > 900 - 40) xVelocity *= -1;

 //       if (rectanglePos.x < 0 || rectanglePos.x > 1000 - 100) xVelocity *= -1;
 //       if (rectanglePos.y < 0 || rectanglePos.y > 900 - 100) xVelocity *= -1;

 //       

 //       octagonPos.x += xVelocity;
 //       octagonPos.y += yVelocity;
 //       trianglePos.x += xVelocity;
 //       trianglePos.x += yVelocity;
 //       pentagonPos.x += xVelocity;
 //       pentagonPos.x += yVelocity;

 //       rectanglePos.x += xVelocity;
 //       rectanglePos.y += yVelocity;

 //       octagon.setPosition(octagonPos);
 //       triangle.setPosition(trianglePos);
 //       pentagon.setPosition(pentagonPos);

 //       rect.setPosition(rectanglePos);

 //       ///////////////////////////////Move enemy part!?????????????????????????????/
 //       for (int i = 0; i < enemyVector.size(); i++)
 //       {
 //           enemyVector[i].move_enemy();
 //           if (enemyVector[i].touches_bottom())
 //           {
 //               enemyVector.erase(enemyVector.begin());
 //           }
 //       }


 //      /////////////////////////////// //collision part!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 //       
 //       if (octagon.getGlobalBounds().intersects(playerSprite1.getGlobalBounds()) && invincibleTime >= 100 ||
 //           triangle.getGlobalBounds().intersects(playerSprite1.getGlobalBounds()) && invincibleTime >= 100 ||
 //           pentagon.getGlobalBounds().intersects(playerSprite1.getGlobalBounds()) && invincibleTime >= 100 ||
 //           rect.getGlobalBounds().intersects(playerSprite1.getGlobalBounds()) && invincibleTime >= 100)
 //       {
 //           cout << "Collision detected!" << endl;
 //           healthBar.erase(healthBar.end() -1);
 //           invincibleTime = 0;
 //           invincibleTime++;
 //           if (healthBar.size() == 0)
 //           {
 //               cout << "\n\n\nGame over\n" << endl;
 //               cout << "Final score: " << score << endl << endl;
 //               system("pause");
 //               break;
 //           }
 //       }
 //       
 //  
 //       for (int i = 0; i < enemyVector.size(); i++)
 //       {
 //           if (playerSprite1.getGlobalBounds().intersects(enemyVector[i].enemy_boundary()) && invincibleTime >= 100)
 //           {
 //               cout << "Collision detected!" << endl;
 //               healthBar.erase(healthBar.end() - 1);
 //               invincibleTime = 0;
 //               invincibleTime++;
 //               if (healthBar.size() == 0)
 //               {
 //                   cout << "\n\n\nGame over\n" << endl;
 //                   cout << "Final score: " << score << endl << endl;
 //                   system("pause");
 //                   break;
 //               }

 //           }

 //       }


 //       for (int i = 0; i < laserProjectiles.size(); i++)
 //       {
 //           for (int j = 0; j < enemyVector.size(); j++)
 //           {
 //               if (laserProjectiles[i].getGlobalBounds().intersects(enemyVector[j].enemy_boundary()))
 //               {
 //                   cout << "Hit the enemy with the laser! Score +10!" << endl;
 //                   score+= 10;
 //                   laserProjectiles.erase(laserProjectiles.begin() + i);
 //                   enemyVector.erase(enemyVector.begin() + j);
 //                   printf("Current Score: %d\n", score);
 //                   break;
 //               }

 //           }
 //       }


 //       ////////////////////////////////////Skil Buffer//////////////////////////////////////////////////////
 //       if (invincibleTime < 100) invincibleTime++;
 //       if (laserTime < 20) laserTime++;
 //       if (enemySpawnTime < 30) enemySpawnTime++;

 //       ////////////////////////////////////////////////Output////////////////////////////////////////////////////////////////
 //       // clear the window with black color
 //       window.clear(sf::Color::Black);
 //       
 //       // draw everything here...   //draw it somewhere in the back hidden space 
 //       // window.draw(...);
 //       //window.draw(healthIndexSprite1); //draw function 

 //       menu.draw(window);

 //       window.draw(playerSprite1);

 //       for (int i = 0; i < healthBar.size(); i++)
 //       {
 //           window.draw(healthBar[i]);
 //       }
 //       
 //       window.draw(octagon);
 //       window.draw(triangle);
 //       window.draw(pentagon);
 //       window.draw(rect);
 //      
 //       

 //       for (int i = 0; i < laserProjectiles.size(); i++)
 //       {
 //           window.draw(laserProjectiles[i]);
 //       }
 //       

 //       for (int i = 0; i < enemyVector.size(); i++)
 //       {
 //           enemyVector[i].render(window);
 //       }
 //       
 //       // end the current frame    //we need to call display to swap it to the main scene.
 //       window.display(); //need this display func oterwise nothing shows up and crashes
 //       //hidden buffer of what happened through code copied over to the window
 //   }

	return 0;
}