#include "Astroid.h"

Astroid::Astroid(sf::Shape* shape, sf::Vector2f position)
{
	position.x = 15.f;
	position.y = 15.f;
	this->shape = shape;

	xVelocity = 3.f;
	yVelocity = 3.f;
}
	

Astroid Astroid::createOctagon() // create an astroid object by calling create octagon.
{
	

	sf::Vector2f octagonPos(15.f, 15.f);
	
	sf::CircleShape* octagon = new CircleShape (20.f, 8); //not passing by reference
	
	octagon->setFillColor(Color::Blue);
	
	Astroid astroid(octagon, octagonPos);
	

	return astroid;
}

Astroid Astroid::createTriangle()
{
	sf::Vector2f trianglePos(25.f, 25.f);
	sf::CircleShape* triangleShape = new CircleShape(20.f, 3);
	triangleShape->setFillColor(Color::Yellow);
	Astroid astroid(triangleShape, trianglePos);
	return astroid;

}


Astroid Astroid::createPentagon()
{
	sf::Vector2f pentagonPos(25.f, 25.f);
	sf::CircleShape* pentagonShape = new sf::CircleShape(20.f, 5);
	pentagonShape->setFillColor(Color::Yellow);
	Astroid astroid(pentagonShape, pentagonPos);
	return astroid;


}

Astroid Astroid::createRect()
{
	sf::Vector2f rectanglePos(75.f, 75.f);

	sf::Vector2f rectangleSize(100, 10);
	sf::RectangleShape* rectangleShape = new sf::RectangleShape(rectangleSize);
	rectangleShape->setFillColor(Color::Magenta);
	Astroid astroid(rectangleShape,rectanglePos);
	return astroid;
}


sf::Vector2f Astroid::getPosition()
{
	return position;
}

sf::Shape* Astroid::getShape()
{
	return shape;
}

void Astroid::moveAstroid()
{
	if (position.x < 0 || position.x > 640 - 40) xVelocity *= -1;
	if (position.y < 0 || position.y > 480 - 40) yVelocity *= -1;

	position.x += xVelocity;
	position.y += yVelocity;
}

void Astroid::setPosition(sf::Vector2f newPosition)
{
	position = newPosition;
}
