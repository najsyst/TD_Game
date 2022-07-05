#include "Button.h"
#include "GameState.h"

Button::Button(float x, float y, float width, float height,
	std::string text, sf::Font* font, sf::Color idleColor,
	sf::Color hoverColor, sf::Color activeColor)
{
	buttonState = BTN_IDLE;
	shape.setPosition(sf::Vector2f(x, y));
	shape.setSize(sf::Vector2f(width, height));
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setCharacterSize(12);
	this->text.setPosition(shape.getPosition().x + (shape.getSize().x / 2.f) - this->text.getGlobalBounds().width / 2.f,
		shape.getPosition().y + (shape.getSize().y / 2.f) - this->text.getGlobalBounds().width / 2.f);
	this->idleColor = idleColor;
	this->activeColor = activeColor;
	this->shape.setFillColor(idleColor);
}

Button::Button(float x, float y, float width, float height, std::string file,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	buttonState = BTN_IDLE;
	shape.setPosition(sf::Vector2f(x, y));
	shape.setSize(sf::Vector2f(width, height));
	this->idleColor = idleColor;
	this->activeColor = activeColor;
	this->shape.setFillColor(idleColor);
	texture.loadFromFile(file);
	sprite.setTexture(texture);
	sprite.scale(2, 2);
	sprite.setPosition(x, y);
}

Button::~Button()
{
}

bool Button::isPressed()
{
	if (buttonState == BTN_ACTIVE)
	{
		return true;
	}
	return false;
}

sf::Vector2f Button::getPosition()
{
	return sprite2.getPosition();
}

void Button::drag(sf::Vector2f mousePos)
{
		buttonState = BTN_ACTIVE;
		sprite2.setTexture(texture);
		sprite2.setOrigin(32, 32);
		sprite2.setPosition(mousePos.x - 32, mousePos.y - 32);
}

void Button::render(sf::RenderTarget* target)
{
	target->draw(shape);
	target->draw(text);
	target->draw(sprite);
	if (gameState != NULL)
	{
		if (wasButtonreleased == true)
		{
			target->draw(sprite2);
		}
	}
}

void Button::update(sf::Vector2f mousePos)
{
	if (shape.getGlobalBounds().contains(mousePos))
	{
		buttonState = BTN_HOVER;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			buttonState = BTN_ACTIVE;
		}
	}
	else
	{
		if ((buttonState == BTN_ACTIVE) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
		{
		}
		else
		{
			buttonState = BTN_IDLE;
		}
	}
	switch (buttonState)
	{
	case BTN_IDLE:
		shape.setFillColor(idleColor);
		break;
	case BTN_HOVER:
		shape.setFillColor(hoverColor);
		break;
	case BTN_ACTIVE:
		shape.setFillColor(activeColor);
		break;
	default:
		shape.setFillColor(sf::Color::Red);
		break;
	}
}

