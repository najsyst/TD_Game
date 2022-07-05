#include "State.h"

State::State(sf::RenderWindow* window, std::stack <State*>* states)
{
	this->window = window;
	this->states = states;
	quit = false;
}

State::~State()
{
}

bool State::getQuit()
{
	return quit;
}

void State::updateMousePosition()
{
	mousePosScreen = sf::Mouse::getPosition();
	mousePosWindow = sf::Mouse::getPosition(*window);
	mousePosView = window->mapPixelToCoords
	(sf::Mouse::getPosition(*window));
}


