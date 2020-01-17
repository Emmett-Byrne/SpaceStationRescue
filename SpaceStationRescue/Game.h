#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "Player.h"
#include "Predator.h"
#include "Worker.h"
#include "Nest.h"
#include "Missile.h"
#include "PowerUp.h"


class Game
{
public:
	Game();
	~Game();
	void run();

private:
	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	Grid m_grid;
	Player m_player;
	//Predator m_predator;
	
	Worker m_worker;

	Nest m_nest;
	Missile m_missile;

	Nest m_nest2;
	Missile m_missile2;

	PowerUp m_powerUp;


	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message

	sf::View m_miniMap;

	bool m_exitGame; // control exiting game
};

