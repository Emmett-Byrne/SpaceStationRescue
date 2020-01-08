#include "Game.h"

Game::Game() :
	m_window{ sf::VideoMode{ 2000, 2000, 32 }, "Warp Break" },
	m_exitGame{ false },
	grid(50,50, 100),
	player(sf::Vector2f(100, 100), 5.0f, 30, grid)
{
}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (!m_exitGame)
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			m_exitGame = true;
		}

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::O)
			{
				grid.switchDrawLines();
			}
			if (event.key.code == sf::Keyboard::Up)
			{
				player.setMoveUp(true);
			}
			if (event.key.code == sf::Keyboard::Down)
			{
				player.setMoveDown(true);
			}
			if (event.key.code == sf::Keyboard::Left)
			{
				player.setMoveLeft(true);
			}
			if (event.key.code == sf::Keyboard::Right)
			{
				player.setMoveRight(true);
			}
		}

		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Up)
			{
				player.setMoveUp(false);
			}
			if (event.key.code == sf::Keyboard::Down)
			{
				player.setMoveDown(false);
			}
			if (event.key.code == sf::Keyboard::Left)
			{
				player.setMoveLeft(false);
			}
			if (event.key.code == sf::Keyboard::Right)
			{
				player.setMoveRight(false);
			}
		}

		sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
		if (mousePos.x >= 0 && mousePos.x < 2000 && mousePos.y >= 0 && mousePos.y < 2000)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				sf::Vector2i position = mousePos;
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i position = mousePos;
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				sf::Vector2i position = mousePos;
			}
		}
	}
}

void Game::update(sf::Time t_deltaTime)
{
	player.update(t_deltaTime);
}

void Game::render()
{
	m_window.clear(sf::Color::White);

	grid.render(m_window);
	player.render(m_window);

	m_window.display();
}
