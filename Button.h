#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include <iostream>
#include <ctime>
#include <stack>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
class GameState;

enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };


class Button
{
private:

	sf::RectangleShape shape;
	sf::Text text;
	sf::Font* font;
	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;
	sf::Texture texture;

public:
	bool wasButtonreleased;
	short unsigned buttonState;
	sf::Sprite sprite, sprite2;
	GameState* gameState;
	Button(float x, float y, float width, float height, std::string text,
		sf::Font* font, sf::Color idleColor, sf::Color hoverColor,
		sf::Color activeColor);

	Button(float x, float y, float width, float height, std::string file,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);

	~Button();

	bool isPressed();
	sf::Vector2f getPosition();
	void drag(sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
	void update(sf::Vector2f mousePos);
};

