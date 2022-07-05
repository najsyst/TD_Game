#pragma once

#include "Object.h"
#include "TileMap.h"

/// <summary>
/// Klasa posiadajaca implementacje przeciwnika
/// </summary>
class Enemy : public Object
{
private:
	/// <summary>
	/// Zmienna pomocnicza do algorytmu chodzenia przeciwnika
	/// </summary>
	sf::Vector2f temp;

	/// <summary>
	/// Zmienna pomocnicza do algorytmu chodzenia przeciwnika
	/// </summary>
	int y_pom = -1;

	/// <summary>
	/// Zmienna pomocnicza do algorytmu chodzenia przeciwnika
	/// </summary>
	int x_pom = -1;

	/// <summary>
	/// Szybkosc przeciwnika
	/// </summary>
	float speed;

	/// <summary>
	/// Punkty zdrowia przeciwnika
	/// </summary>
	float health;

	/// <summary>
	/// Funkcja inicjalizujaca poczatkowe polozenie przeciwnika
	/// </summary>
	void initCoordinates();

	/// <summary>
	/// Funkcja zawierajaca algorytm chodzenia przeciwnika
	/// </summary>
	void move();


protected:

public:
	/// <summary>
	/// Konstruktor
	/// </summary>
	Enemy(GameState* gameState);

	/// <summary>
	/// Destruktor
	/// </summary>
	~Enemy();

	/// <summary>
	/// Funkcja zwracajaca aktualne zdrowie
	/// </summary>
	float getHealth();

	/// <summary>
	/// Funkcja zwracajaca aktualna szybkosc
	/// </summary>
	float getSpeed();

	/// <summary>
	/// Funkcja ustawiajaca zdrowie
	/// </summary>
	void setHealth(float damage);

	/// <summary>
	/// Funkcja sprawdzajaca czy przeciwnik zyje
	/// </summary>
	bool isAlive();

	/// <summary>
	/// Funkcja update przeciwnika
	/// </summary>
	void update();
};

