#include "level.h"
#include "Menu.h"
#include <sstream>



level::level(float width, float height)
{



	if (!font.loadFromFile("CoffieBold.otf"))
	{
		//It handle itself
	}


	score[0].setFont(font);																		//score number
	score[0].setFillColor(sf::Color::White);
	score[0].setPosition(width / 12, height / 600);

	score[1].setFont(font);																		//score text
	score[1].setFillColor(sf::Color::White);
	score[1].setString("Score: ");
	score[1].setPosition(width / 500, height / 600);

	score[2].setFont(font);																		//Losing text
	score[2].setFillColor(sf::Color::White);
	score[2].setString("Game Over");
	score[2].setCharacterSize(100);
	score[2].setPosition(width / 3, height / 2);

	score[3].setFont(font);																		//Winning text
	score[3].setFillColor(sf::Color::White);
	score[3].setString("You Win!!");
	score[3].setCharacterSize(100);
	score[3].setPosition(width / 3, height / 2);



	success = 0;
}
void level::level_1(sf::RenderWindow& window)
{
	int i = 0;
	Menu goBack(window.getSize().x, window.getSize().y);


	while (success == 0)
	{
		scoreText(i, window);
		window.display();

		std::cout << "1: Win | 0: none | 2: lose" << std::endl;
		std::cin >> success;
		//player logic code

		if (success == 1)
		{
			win(window);
			window.display();
			system("pause");
		}

		if (success == 2)
		{
			lose(window);
			window.display();
			system("pause");
		}
	}


}



void level::scoreText(int& i, sf::RenderWindow& window)
{
	std::stringstream ss;


	i++;  //just replace the score logic here
	ss << i;  //<- ss is stringStream which converts int to string


	score[0].setString(ss.str().c_str());
	window.clear(sf::Color::Black);

	for (int j = 0; j < 2; j++)
	{
		window.draw(score[j]);
	}

}


void level::win(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	window.draw(score[3]);
}



void level::lose(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	window.draw(score[2]);
}