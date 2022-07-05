#pragma once

#include "Tower.h"

/// <summary>
/// Klasa posiadajaca inicjalizacje strzelca
/// </summary>
class SharpShooter : public Tower
{
private:
protected:
public:
	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="gameState"> wskaznik na obiekt klasy gameState </param>
	SharpShooter(GameState* gameState);

	/// <summary>
	/// Destruktor
	/// </summary>
	~SharpShooter();
};

