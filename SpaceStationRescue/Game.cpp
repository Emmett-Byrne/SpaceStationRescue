#include "Game.h"

Game::Game() :
	m_window{ sf::VideoMode{ 1920, 1080, 32 }, "Rescue" },
	m_exitGame{ false },
	grid(30,30, 200),
	player(sf::Vector2f(100, 100), 8.0f, 30, grid),
	predator(sf::Vector2f(1900, 1900), 8.0f, 30, grid,player)
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
			m_exitGame = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			m_exitGame = true;
		}

		if (event.type == sf::Event::KeyPressed)
		{
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
	std::cout << player.getPosition().x << ", " << player.getPosition().y << std::endl;
	predator.update(t_deltaTime);
}

void Game::render()
{
	m_window.clear(sf::Color::Blue);

	sf::Vector2f offset = -player.getPosition() + sf::Vector2f(1920/2, 1080/2);

	grid.render(m_window, offset);
	player.render(m_window, offset, sf::Color::Green);
	predator.render(m_window, offset, sf::Color::Red);

	m_window.display();
}
