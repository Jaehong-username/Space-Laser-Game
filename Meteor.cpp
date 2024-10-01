#include "Meteor.h"

Meteor::Meteor(Vector2f initPos, sf::Color color) : Sprite()
{
	sf::Texture meteor;
	if (!meteor.loadFromFile("meteorBrown_big1")) cout << "The image is not correctly loaded from the file" << endl;
	this->setTexture(meteor);
	this->setColor(color);
	this->setPosition(initPos);
	this->setScale(0.5, 0.5);
	position = initPos;

	//meteorVelocity = 10.0f;
}

void Meteor::moveMeteor()
{
	Vector2f velocity;
	velocity.x = rand() % 10;
	velocity.y = rand() % 10;

	if (position.x < 0 || position.x > 1000 - 40) velocity.x *= -1;
	if (position.y < 0 || position.y > 900 - 40) velocity.y *= -1;

	this->move(velocity.x, velocity.y);

	position.x += velocity.x;
	position.y += velocity.y;

}

void Meteor::drawMeteor(sf::RenderWindow& window)
{
	window.draw(*this);
}
