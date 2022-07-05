#pragma once

#include "Object.h"
#include "Tower.h"

/// <summary>
/// Klasa posiadajaca implementacje pociskow
/// </summary>
class Bullet : public Object
{
private:
	/// <summary>
	/// Wskaznik na zmienna klasy Object
	/// </summary>
	Object* enemy;

	/// <summary>
	/// Funkcja inicjalizuj¹ca poczatkowe polozenie pocisku
	/// </summary>
	void initCoordinates();

	/// <summary>
	/// Funkcja posiadajaca algorytm poruszania sie pocisku
	/// </summary>
	void move();
protected:

public:
	/// <summary>
	/// Wskaznik na zmienna klasy Object
	/// </summary>
	Object* tower;

	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="gameState"> wskaznik do obiektu klasy GameState </param>
	Bullet(GameState* gameState, Object* object, Object* object2);

	/// <summary>
	/// Destruktor
	/// </summary>
	~Bullet();

	/// <summary>
	/// Funkcja sprawdzajaca czy pocisk trafil przeciwnika
	/// </summary>
	/// <returns> true lub false</returns>
	bool DidItHit();

	/// <summary>
	/// Funkcja update pocisku
	/// </summary>
	void update();
};

