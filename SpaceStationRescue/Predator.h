#pragma once
#include "Character.h"
#include "Player.h"
#include<ctime>



class Predator : public Character
{
public:
	Predator(sf::Vector2f pos, float speed, float size, Grid& grid, Player& p);
	void update(sf::Time t_deltaTime);

	void respawn();

	bool getAlive();

private:
	bool collidesWithPlayer();
	bool collidesWithBullet();
	bool playerCollidseWithBullet();
	Player& player;

	float fireRange;
	sf::Time fireCooldown;


	sf::Vector2f m_respawnPos;
	sf::Time m_timer;
};

