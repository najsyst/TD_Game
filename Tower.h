#pragma once

#include "Object.h"
#include "Enemy.h"
class Button;

/// <summary>
/// Klasa bazowa dla wiez
/// </summary>
class Tower : public Object
{
private:
	/// <summary>
	/// Zmienna odliczajaca czas
	/// </summary>
	sf::Clock clock;

	/// <summary>
	/// Zmienna mierzaca czas
	/// </summary>
	sf::Time elapsed_time;

	/// <summary>
	/// Funkcja przy wywolaniu ktorej wieza oddaje strzal
	/// </summary>
	/// <param name="enemy"> przeciwnik do ktorego strzela wieza </param>
	void shoot(Object* enemy);

protected:
	/// <summary>
	/// Zasieg wiezy
	/// </summary>
	float range;

	/// <summary>
	/// Szybkosc ataku wiezy
	/// </summary>
	float attack_speed;

	/// <summary>
	/// Obrazenia wiezy
	/// </summary>
	float damage;

	/// <summary>
	/// Funkcja inicjalizujaca polozenie wiezy
	/// </summary>
	/// <param name="button"> przycisk odpowiadajacy za dana wieze </param>
	void initCoordinates(Button* button);

	/// <summary>
	/// Funkcja sprawdzajaca czy przeciwnik jest w zasiegu wiezy
	/// </summary>
	/// <param name="enemy"> przeciwnik </param>
	/// <param name="range"> zasieg </param>
	/// <returns> true jesli przeciwnik jest w zasiegu, false jesli nie </returns>
	bool inRange(Enemy* enemy, float range);

public:
	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="gameState"> wskaznik na obiekt klasy GameState</param>
	Tower(GameState* gameState);

	/// <summary>
	/// Destruktor
	/// </summary>
	~Tower();
	
	/// <summary>
	/// Funkcja zwracajaca obrazenia
	/// </summary>
	float getDamage();

	/// <summary>
	/// Funkcja zwracajaca zasieg
	/// </summary>
	float getRange();

	/// <summary>
	/// Funkcja zwracajaca szybkosc ataku
	/// </summary>
	float getAttack_speed();

	/// <summary>
	/// Funkcja update
	/// </summary>
	void update();
};

