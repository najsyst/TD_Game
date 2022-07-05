#include "TileMap.h"

void TileMap::initTextures()
{
	textures["grass"] = new sf::Texture();
	textures["grass"]->loadFromFile("Sprite\\grass.png");

	textures["dirt"] = new sf::Texture();
	textures["dirt"]->loadFromFile("Sprite\\dirt.png");

	textures["track"] = new sf::Texture();
	textures["track"]->loadFromFile("Sprite\\track.png");
}

void TileMap::initMap()
{
	for (int x = 0; x < maxSize_x; x++)
	{
		pom.push_back(std::vector<int>());
		for (int y = 0; y < maxSize_y; y++)
		{
			pom[x].push_back(maxSize_y);
		}
	}

	t = new int[maxSize_x * maxSize_y]
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		2, 2, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 2, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 2, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0,
		0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0,
		0, 0, 2, 2, 2, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0,
		0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0,
		0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0,
		0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0,
		0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 2, 0, 0, 0,
		0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0,
		0, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 2, 2, 2, 2,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	for (int x = 0; x < maxSize_x; x++)
	{
		map.push_back(std::vector<sf::RectangleShape>());
		for (int y = 0; y < maxSize_y; y++)
		{
			pom[x][y] = t[maxSize_x * y + x];

			map[x].push_back(sf::RectangleShape());

			map[x][y].setPosition(sf::Vector2f(gridSize * x, gridSize * y));
			map[x][y].setSize(sf::Vector2f(gridSize, gridSize));
			map[x][y].setTexture(textures["grass"]);

			switch (pom[x][y])
			{
			case 0:
				break;
			case 1:
				map[x][y].setTexture(textures["dirt"]);
				break;
			case 2:
				map[x][y].setTexture(textures["track"]);
				break;
			}
		}
	}
}

TileMap::TileMap(GameState* gameState)
{
	this->gameState = gameState;
	maxSize_x = 30;
	maxSize_y = 16;
	gridSize = 50;
	initTextures();
	initMap();
}

TileMap::~TileMap()
{
	delete[] t;

	auto it = textures.begin();
	for (it = textures.begin(); it != textures.end(); ++it)
	{
		delete it->second;
	}

	for (auto& x : map)
	{
		x.clear();
	}
	map.clear();
}

void TileMap::render(sf::RenderTarget* target)
{
	for (auto& x : map)
	{
		for (auto& y : x)
		{
			target->draw(y);
		}
	}
}

void TileMap::update()
{

}
