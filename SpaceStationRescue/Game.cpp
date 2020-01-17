#include "Game.h"

Game::Game() :
	m_window{ sf::VideoMode{ 1920, 1080, 32 }, "Rescue" },
	m_exitGame{ false },
	m_grid(30,30, 200),
	m_player(sf::Vector2f(100, 100), 8.0f, 30, m_grid),
	m_predator(sf::Vector2f(1900, 1900), 8.0f, 30, m_grid,m_player),
	m_worker(sf::Vector2f(100,100), 8.0f, 30, m_grid)
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
				m_player.setMoveUp(true);
			}
			if (event.key.code == sf::Keyboard::Down)
			{
				m_player.setMoveDown(true);
			}
			if (event.key.code == sf::Keyboard::Left)
			{
				m_player.setMoveLeft(true);
			}
			if (event.key.code == sf::Keyboard::Right)
			{
				m_player.setMoveRight(true);
			}

			if (event.key.code == sf::Keyboard::Space)
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
				m_player.fire(sf::Vector2f(mousePos.x, mousePos.y));
			}
		}

		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Up)
			{
				m_player.setMoveUp(false);
			}
			if (event.key.code == sf::Keyboard::Down)
			{
				m_player.setMoveDown(false);
			}
			if (event.key.code == sf::Keyboard::Left)
			{
				m_player.setMoveLeft(false);
			}
			if (event.key.code == sf::Keyboard::Right)
			{
				m_player.setMoveRight(false);
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
	m_player.update(t_deltaTime);
	std::cout << m_player.getPosition().x << ", " << m_player.getPosition().y << std::endl;
	m_predator.update(t_deltaTime); 
}

void Game::render()
{
	m_window.clear(sf::Color::Blue);

	sf::Vector2f offset = -m_player.getPosition() + sf::Vector2f(1920/2, 1080/2);

	m_grid.render(m_window, offset);
	m_player.render(m_window, offset, sf::Color::Green);
	m_predator.render(m_window, offset, sf::Color::Red); 

	m_worker.render(m_window, offset, sf::Color::Cyan);

	m_window.display();
}
