#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "Player.h"
#include "Predator.h"
#include "Worker.h"


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
	Predator m_predator;
	
	Worker m_worker;


	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message

	bool m_exitGame; // control exiting game
};

