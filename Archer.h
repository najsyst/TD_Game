#pragma once

#include "Tower.h"

/// <summary>
/// Klasa posiadajaca inicjalizacje strzelca
/// </summary>
class Archer : public Tower
{
private:
protected:
public:
	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="gameState"> wskaznik na obiekt klasy gameState </param>
	Archer(GameState* gameState);

	/// <summary>
	/// Destruktor
	/// </summary>
	~Archer();
};