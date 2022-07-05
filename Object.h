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

/// <summary>
/// Klasa bazowa dla wszystkich obiektow gry
/// </summary>
class Object
{
private:
	/// <summary>
	/// Wektor zawieraj¹cy informacjie o polozeniu obiektu
	/// </summary>
	sf::Vector2f coordinates;

	/// <summary>
	/// Funkcja inicjalizujaca pocz¹tkowe polozenie obiektu
	/// </summary>
	virtual void initCoordinates();

protected:
	
public:

	/// <summary>
	/// Wskaznik na obiekt klasy GameState
	/// </summary>
	GameState* gameState;

	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="gameState"> Wskaznik na obiekt klasy GameState</param>
	Object(GameState* gameState);

	/// <summary>
	/// Destruktor
	/// </summary>
	~Object();

	/// <summary>
	/// Funkcja zwracajaca polozenie obiektu
	/// </summary>
	/// <returns> polozenie obiektu </returns>
	sf::Vector2f getCoordinates();

	/// <summary>
	/// Funkcja ustawiajaca koordynaty obiektu
	/// </summary>
	/// <param name=""></param>
	void setCoordinates(float x, float y);


	/// <summary>
	/// Wirtualna funkcja update
	/// </summary>
	virtual void update() = 0;
};

