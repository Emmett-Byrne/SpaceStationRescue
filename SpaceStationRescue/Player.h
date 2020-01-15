#pragma once
#include "Character.h"
class Player : public Character
{
public:
	Player(sf::Vector2f pos, float speed, float size, Grid& grid);
	void update(sf::Time t_deltaTime);

	void setMoveUp(bool b) { moveUp = b; };
	void setMoveDown(bool b) { moveDown = b; };
	void setMoveLeft(bool b) { moveLeft = b; };
	void setMoveRight(bool b) { moveRight = b; };
	void fire(sf::Vector2f target);

private:
	bool moveUp;
	bool moveDown;
	bool moveLeft;
	bool moveRight;
};

