#include "Player.h" //has a relationship with laser class

#include "Application.h"
//#include "Enemy.h"; //if for the sake of referencing then state

Player::Player() : Entity()
{ 
    //sf::FloatRect bounds1(this->getLocalBounds()); //getting the bounds of the player
    //this->setPosition(window.getSize().x / 2 - (bounds1.left + bounds1.width / 2),
    //    window.getSize().y / 2 - (bounds1.top + bounds1.height / 2));
    
    this->setPosition(500, 450);

    laser.setPosition(this->getPosition().x + 45.f, this->getPosition().y - 55.f);

    alive = true;

    invincibleTime = 100;
    laserTime = 20;
    score = 0;

    //health = 10; //no really need becuase health vector can get the size
    createHealthBar();
}

void Player::movePlayer()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && position.x >= 0)
    {
        this->move(-20.f, 0);
        position.x -= 20.f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && position.x <= 1000 - 100)
    {
        this->move(+20.f, 0);
        position.x += 20.f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && position.y >= 0)
    {
        this->move(0, -20.f);
        position.y -= 20.f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && position.y <= 900 - 100)
    {
        this->move(0, +20.f);
        position.y += 20.f;
    }
}



int Player::getInvincibleTime()
{
    return invincibleTime;
}

void Player::setInvincibleTime(int newInvincibleTime)
{
    invincibleTime = newInvincibleTime;
}


std::vector<CircleShape> Player::getHealthBar()
{
    return healthBar;
}

int Player::getScore()
{
    return score;
}

int Player::getLaserTime()
{
    return laserTime;
}

void Player::setLaserTime(int newLaserTime)
{
    laserTime = newLaserTime;
}



void Player::invincibleTimeBuffer(int newInvincibleTime)
{
    if (invincibleTime < 100) invincibleTime++;
}

void Player::laserTimeBuffer(int newLaserTime)
{
    if (laserTime < 20) laserTime++;
}


void Player::shootLaser() //instantiate when pressing space
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && laserTime >= 20)
    {
        laserVec.push_back(laser);
    }
}

void Player::moveLaser() //update laser!
{
    for (int i = 0; i << laserVec.size(); i++)
    {
        laserVec[i].moveLaser();
        if (laserVec[i].checkLaserOut()) //if laser out of the screen is true
        {
            laserVec.erase(laserVec.begin() + i); //remove that laser out of the vector
        }
    }
}

void Player::drawLaser(sf::RenderWindow& window) //draw the laser!!!
{
    for (int i = 0; i << laserVec.size(); i++)
    {
        window.draw(laserVec[i]);
    }
}

bool Player::checkLaserCollision()
{
    for (int i = 0; i << laserVec.size(); i++)
    {
        for (int j = 0; j << Application::getEnemyVec().size(); j++)
        {
            if (laserVec[i].getGlobalBounds().intersects(Application::getEnemyVec()[j].getGlobalBounds()) && invincibleTime >= 100)
            {
                laserVec.erase(laserVec.begin() + i);
                Application::getEnemyVec().erase(Application::getEnemyVec().begin() + j);
                return true; //break;     
            }
        }
        
    }
    return false;
}



bool Player::checkPlayerCollision()
{
    for (int i = 0; i << Application::getEnemyVec().size(); i++)
    {
        if (this->getGlobalBounds().intersects(Application::getEnemyVec()[i].getGlobalBounds()))
        {
            cout << "Collision with enemy detected! Lose one health!" << endl;
            healthBar.erase(healthBar.end() - 1);
            return true;
        }
    }

    if (this->getGlobalBounds().intersects(Application::getEnemyVec()[i].getGlobalBounds())) //checking if its collided with meteor
    {
        cout << "Collision with Meteor detected Lose one health!" << endl;
        healthBar.erase(healthBar.end() - 1);
        return true;
    }

    return false;
}


void Player::updateScore()
{
    if (checkLaserCollision())
    {
        cout << "Hit the enemy with the laser! Score +10!" << endl;
        score += 10;
        printf("Current Score: %d\n", score);
    }
    
}



void Player::createHealthBar()
{
    float updatedxPos = 5.f;
    for (int i = 0; i < 10; i++)
    {
        sf::CircleShape healthShape;
        healthShape.setFillColor(Color::Red);
        healthShape.setRadius(10.f);
        healthShape.setPosition(updatedxPos, 20.f);
        healthBar.push_back(healthShape);

        updatedxPos += 20.f;
    }
}

