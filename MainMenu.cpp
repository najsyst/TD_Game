#include "MainMenu.h"

void MainMenu::initFonts()
{
	font.loadFromFile("Fonts\\arial.ttf");
}

void MainMenu::initButtons()
{
	buttons["START"] = new Button(860, 440, 200, 60, "START", &font,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200));

	buttons["EXIT"] = new Button(860, 540, 200, 60, "EXIT", &font,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200));
}

MainMenu::MainMenu(sf::RenderWindow* window, std::stack <State*>* states) : State(window, states)
{
	initFonts();
	initButtons();

	texture.loadFromFile("Textures\\TD169.jpg");
	sprite.setTexture(texture);
}

MainMenu::~MainMenu()
{
	auto it = buttons.begin();
	for (it = buttons.begin(); it != buttons.end(); ++it)
	{
		delete it->second;
	}
}

void MainMenu::update()
{
	updateMousePosition();
	updateButtons();

	if (buttons["START"]->isPressed())
	{
		states->pop();
		states->push(new GameState(window, states));
	}

	if (buttons["EXIT"]->isPressed())
	{
		quit = true;
	}
}

void MainMenu::render(sf::RenderTarget* target = nullptr)
{
	if (!target)
		target = window;

	target->draw(sprite);
	renderButtons(target);
}

void MainMenu::updateButtons()
{
	for (auto& it : buttons)
	{
		it.second->update(mousePosView);
	}
}

void MainMenu::renderButtons(sf::RenderTarget* target = nullptr)
{
	for (auto& it : buttons)
	{
		it.second->render(target);
	}
}