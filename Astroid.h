#pragma once

#include "SFML/Graphics.hpp"

#include <iostream>

#include <vector>

using sf::Color;
using sf::CircleShape;
using sf::RectangleShape;



static class Astroid
{
public:
	//dummy constructoor
	Astroid(sf::Shape* shape, sf::Vector2f position); //for the sake of creatibng Astroid objecgt

	//named constructors.
	static Astroid createOctagon(); //rather than onan instance you operate on a class
	static Astroid createTriangle();
	static Astroid  createPentagon();
	static Astroid  createRect();

	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f newPosition);

	sf::Shape* getShape();

	void moveAstroid();

private:
	sf::Shape *shape;  //Shape is an abstract class. allocate an a memory
	sf::Vector2f position;

	//velocity
	float xVelocity;
	float yVelocity;
};
