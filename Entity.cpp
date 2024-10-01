#include "Entity.h"

Entity::Entity() : Sprite()
{

    sf::Texture entity;
    if (!entity.loadFromFile("playerShip1_blue.png")) cout << "playerShip image is not loaded to the correct directory!\n" << endl;
    //sf::Sprite playerSprite1;
    this->setTexture(entity);
}

//Vector2f Entity::getPosition()
//{
//    return position;
//}
//
//void Entity::setPosition(Vector2f newPosition)
//{
//    position = newPosition;
//}
