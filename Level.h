#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

class level
{
public:


	//level constructor
	level(float width, float height);


	//player logic, winning, losing, and enemy logic
	void level_1(sf::RenderWindow& window);


	//prints out plyaer new score
	void scoreText(int& i, sf::RenderWindow& window);


	//prints out win if player win
	void win(sf::RenderWindow& window);


	//prints our lose if player lose
	void lose(sf::RenderWindow& window);

private:

	int success = 0;
	sf::Text score[5];
	sf::Font font;
};
