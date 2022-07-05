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

class TileMap
{
private:
	std::vector<std::vector<sf::RectangleShape>> map;
	std::map<std::string, sf::Texture*> textures;

	float gridSize;

	void initTextures();
	void initMap();


protected:
public:
	TileMap(GameState* gameState);
	~TileMap();
	
	GameState* gameState;
	int maxSize_x, maxSize_y;
	std::vector<std::vector<int>> pom;
	int* t;

	void render(sf::RenderTarget* target);
	void update();
};

