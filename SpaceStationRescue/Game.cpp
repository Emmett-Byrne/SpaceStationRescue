#include "Game.h"

Game::Game() :
	m_window{ sf::VideoMode{ 1920, 1080, 32 }, "Rescue" },
	m_exitGame{ false },
	m_grid(30,30, 200),
	m_miniMap(m_window.getDefaultView()),
	m_player(sf::Vector2f(100, 100), 8.0f, 30, m_grid),
	//m_predator(sf::Vector2f(1900, 1900), 8.0f, 30, m_grid,m_player),
	
	m_worker1(sf::Vector2f(100, 1500), 8.0f, 30, m_grid, m_player),
	m_worker2(sf::Vector2f(100, 1500), 8.0f, 30, m_grid, m_player),
	m_worker3(sf::Vector2f(100, 1500), 8.0f, 30, m_grid, m_player),

	
	m_missile(sf::Vector2f(6000,100), 8.0f, 8.0f, m_grid, sf::Vector2f(6000,100), m_player),
	m_nest(sf::Vector2f(6000,100), 30.0f, m_grid, 500, m_player, m_missile),

	m_missile2(sf::Vector2f(100, 5200), 8.0f, 8.0f, m_grid, sf::Vector2f(100, 5200), m_player),
	m_nest2(sf::Vector2f(100, 5200), 30.0f, m_grid, 500, m_player, m_missile2),

	m_powerUp(sf::Vector2f(1000, 100), 60, m_grid, m_player)
{
	m_miniMap.zoom(6.0f);
	m_miniMap.setCenter(3600, 2200);
	m_miniMap.setViewport(sf::FloatRect(0.8f, 0.0f, 0.25f, 0.25f));
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
				m_player.fire(sf::Vector2f(mousePos.x, mousePos.y) - sf::Vector2f(1920 /2, 1080 / 2) + m_player.getPosition());
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
	//m_predator.update(t_deltaTime); 
	//m_nest.update(t_deltaTime);
	//m_nest2.update(t_deltaTime);

	m_worker1.update(t_deltaTime);
	m_worker2.update(t_deltaTime);
	//m_worker3.update(t_deltaTime);

	m_powerUp.update(t_deltaTime);
}

void Game::render()
{
	m_window.clear(sf::Color::Blue);

	
	m_window.setView(m_window.getDefaultView());


	sf::Vector2f offset = -m_player.getPosition() + sf::Vector2f(1920/2, 1080/2);

	m_grid.render(m_window, offset);

	m_missile.render(m_window, offset, sf::Color::Cyan);
	m_nest.render(m_window, offset, sf::Color::Yellow);

	m_missile2.render(m_window, offset, sf::Color::Cyan);
	m_nest2.render(m_window, offset, sf::Color::Yellow);

	m_powerUp.render(m_window, offset, sf::Color::White);

	m_player.render(m_window, offset, sf::Color::Green);

	m_worker1.render(m_window, offset, sf::Color::Cyan);
	m_worker2.render(m_window, offset, sf::Color::Cyan);
	m_worker3.render(m_window, offset, sf::Color::Cyan);


	//-------------------------------------------------------------------
	
	m_window.setView(m_miniMap);

	m_grid.render(m_window, offset);

	m_missile.render(m_window, offset, sf::Color::Cyan);
	m_nest.render(m_window, offset, sf::Color::Yellow);

	m_missile2.render(m_window, offset, sf::Color::Cyan);
	m_nest2.render(m_window, offset, sf::Color::Yellow);

	m_powerUp.render(m_window, offset, sf::Color::White);

	m_player.render(m_window, offset, sf::Color::Green);

	m_worker1.render(m_window, offset, sf::Color::Cyan);
	m_worker2.render(m_window, offset, sf::Color::Cyan);
	m_worker3.render(m_window, offset, sf::Color::Cyan);
	


	m_window.display();
}
