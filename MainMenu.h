#pragma once

#include "State.h"
#include "Button.h"
#include "GameState.h"

class MainMenu : public State
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Font font;

	std::map<std::string, Button*> buttons;

	void initFonts();
	void initButtons();


protected:
public:
	MainMenu(sf::RenderWindow* window, std::stack <State*>* states);
	~MainMenu();

	void update();
	void render(sf::RenderTarget* target);
	void updateButtons();
	void renderButtons(sf::RenderTarget* target);
};

