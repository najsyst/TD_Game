#include "Game.h"

void Game::initWindow()
{
	sf::VideoMode window_bounds(1920, 1080);
	window = new sf::RenderWindow(window_bounds, "Tower Defense");
	window->setFramerateLimit(120);
	window->setVerticalSyncEnabled(false);
}

void Game::initStates()
{
	states.push(new MainMenu(window, &states));
}

Game::Game()
{
	initWindow();
	initStates();
}

Game::~Game()
{
	delete window;

	while (!states.empty())
	{
		delete states.top();
		states.pop();
	}
}

void Game::updateSFML()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window->close();
		}

		if (event.type == sf::Event::KeyPressed)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window->close();
		}
	}
}

void Game::update()
{
	updateSFML();

	if (!states.empty())
	{
		states.top()->update();
		if (states.top()->getQuit())
		{
			delete states.top();
			states.pop();
		}
	}
	else
	{
		window->close();
	}
}

void Game::render()
{
	window->clear();

	if (!states.empty())
	{
		states.top()->render();
	}

	window->display(); 
}

void Game::run()
{
	while (window->isOpen())
	{
		update();
		render();
	}
}
