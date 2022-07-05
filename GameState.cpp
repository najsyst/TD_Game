#include "GameState.h"

void GameState::initFonts()
{
	if (!this->font.loadFromFile("Fonts\\arial.ttf"))
	{
		std::cout << "Could not load";
	}
}

void GameState::initButtons()
{
	buttons["TOWER1"] = new Button(1650, 100, 128, 128, "Sprite\\tower1.png",
		sf::Color(150, 150, 150, 255),
		sf::Color(100, 100, 100, 240),
		sf::Color(255, 255, 255, 255));

	buttons["TOWER2"] = new Button(1650, 500, 128, 128, "Sprite\\tower2.png",
		sf::Color(150, 150, 150, 255),
		sf::Color(100, 100, 100, 240),
		sf::Color(255, 255, 255, 255));

	buttons["START"] = new Button(450, 900, 200, 60, "START", &font,
		sf::Color(100, 100, 100, 255),
		sf::Color(150, 150, 150, 150),
		sf::Color(20, 20, 20, 150));
	
	buttons["STOP"] = new Button(850, 900, 200, 60, "STOP", &font,
		sf::Color(100, 100, 100, 255),
		sf::Color(150, 150, 150, 150),
		sf::Color(20, 20, 20, 150));
}

GameState::GameState(sf::RenderWindow* window, std::stack <State*>* states) : State(window, states)
{
	map = new TileMap(this);

	initFonts();
	initButtons();
	bottom.setSize(sf::Vector2f(420, 800));
	bottom.setPosition(sf::Vector2f(1500, 0));
	bottom.setFillColor(sf::Color(150, 75, 40));
	right_side.setSize(sf::Vector2f(1920, 280));
	right_side.setPosition(sf::Vector2f(0, 800));
	right_side.setFillColor(sf::Color(150, 75, 40));
	buttons["TOWER1"]->gameState = this;
	buttons["TOWER2"]->gameState = this;
}

GameState::~GameState()
{
	map = NULL;
	delete map;

	auto it = buttons.begin();
	for (it = buttons.begin(); it != buttons.end(); ++it)
	{
		delete it->second;
	}
}




void GameState::update()
{
	updateMap();
	updateMousePosition();

	updateButtons();

	for (int i = 0; i < Objects.size(); i++)
	{
		if (Enemy* enemy = dynamic_cast<Enemy*>(Objects[i]))
		{
			if (enemy->isAlive() == false || enemy->getCoordinates().x > 1450)
			{
				GObjects.erase(GObjects.begin()+i);
				Objects.erase(Objects.begin() + i);
				break;
			}
		}
		if (Bullet* bullet = dynamic_cast<Bullet*>(Objects[i]))
		{
			if (bullet->DidItHit() == true)
			{
				GObjects.erase(GObjects.begin() + i);
				Objects.erase(Objects.begin() + i);
				break;
			}
		}
		Objects[i]->update();
	}

	if (buttons["TOWER1"]->isPressed())
	{
		buttons["TOWER1"]->drag(mousePosView);
		buttons["TOWER1"]->wasButtonreleased = true;
	}
	else if (buttons["TOWER1"]->wasButtonreleased == true && sf::Event::MouseButtonReleased)
	{
		tower_number = 1;
		createTower();
		buttons["TOWER1"]->wasButtonreleased = false;
	}

	if (buttons["TOWER2"]->isPressed())
	{
		buttons["TOWER2"]->drag(mousePosView);
		buttons["TOWER2"]->wasButtonreleased = true;
	}
	else if (buttons["TOWER2"]->wasButtonreleased == true && sf::Event::MouseButtonReleased)
	{
		tower_number = 2;
		createTower();
		buttons["TOWER2"]->wasButtonreleased = false;
	}

	if (buttons["START"]->isPressed())
	{
		wasButtonSTARTpressed = true;
		clock.restart();
	}
	if (buttons["STOP"]->isPressed())
	{
		wasButtonSTARTpressed = false;
	}
	if (wasButtonSTARTpressed == true)
	{
		elapsed_time += clock.restart();
		while (elapsed_time >= delta_time)
		{
			createEnemy();
			elapsed_time -= delta_time;
		}
	}
}

void GameState::render(sf::RenderTarget* target = nullptr)
{
	if (!target)
		target = window;
	target->draw(right_side);
		target->draw(bottom);
	map->render(target);
	renderButtons(target);

	for (int i = 0; i < GObjects.size(); i++)
	{
		GObjects[i]->draw(target);
	}
}

void GameState::createEnemy()
{
	int temp = Objects.size();
	Objects.push_back(new Enemy(this));
	GObjects.push_back(new GEnemy(Objects[temp]));
}



void GameState::createTower()
{
	if (mousePosView.x < 1500 && mousePosView.y < 800)
	{
		int temp = Objects.size();
		if (tower_number == 1)
		{
			Objects.push_back(new Archer(this));
			GObjects.push_back(new GArcher(Objects[temp]));
		}
		if (tower_number == 2)
		{
			Objects.push_back(new SharpShooter(this));
			GObjects.push_back(new GSharpShooter(Objects[temp]));
		}

	}
}


void GameState::updateButtons()
{
	for (auto& it : buttons)
	{
		it.second->update(mousePosView);
	}
}

void GameState::renderButtons(sf::RenderTarget* target = nullptr)
{
	for (auto& it : buttons)
	{
		it.second->render(target);
	}
}

void GameState::createBullet(Object* object, Object* object2)
{
	int temp = Objects.size();
	Objects.push_back(new Bullet(this, object, object2));
	GObjects.push_back(new GBullet(Objects[temp]));
}

void GameState::updateMap()
{
	map->update();
}
