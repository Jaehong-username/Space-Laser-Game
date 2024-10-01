#pragma once

#include "SFML/Graphics.hpp"

#include <iostream>

class Menu
{
public:

	//Menu constructor
	Menu(float width, float height);

	//Draws the main menu
	void draw(sf::RenderWindow& window);

	//user able to interact with the main menu
	void Click(sf::RenderWindow& window, float width, float height);

private:
	sf::Sprite test[5];
	sf::Texture texture[5];

};
