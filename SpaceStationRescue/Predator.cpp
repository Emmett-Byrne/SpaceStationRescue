#include "Predator.h"

Predator::Predator(sf::Vector2f pos, float speed, float size, Grid& grid, Player& p) :
	Character(pos, speed, size, grid),
	player(p)
{
}

void Predator::update(sf::Time t_deltaTime)
{
	Character::pathTo(player.getPosition());
	Character::followPath();
}
