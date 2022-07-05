#pragma once

#include <vector>
#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include <map>
#include <stack>

/// <summary>
/// Klasa bazowa dla stan�w gry
/// </summary>
class State
{
private:

protected:
	/// <summary>
	/// Wska�nik na obiekt klasy sf::RenderWindow
	/// </summary>
	sf::RenderWindow* window;

	/// <summary>
	/// Wska�nik na wektor wska�nik�w do obiekt�w klasy State
	/// </summary>
	std::stack <State*>* states;

	/// <summary>
	/// Zmienna decyduj�ca o opusczeniu programu
	/// </summary>
	bool quit;

	/// <summary>
	/// Po�o�enie myszki na ekranie
	/// </summary>
	sf::Vector2i mousePosScreen;

	/// <summary>
	/// Po�o�enie myszki na oknie
	/// </summary>
	sf::Vector2i mousePosWindow;

	/// <summary>
	/// Po�o�enie myszki na widoku
	/// </summary>
	sf::Vector2f mousePosView;

public:
	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="window"> Wskaznik do okna gry </param> 
	/// <param name="states"> Wskaznik na wektor wska�nik�w do do obiektow klasy State </param>
	State(sf::RenderWindow* window, std::stack <State*>* states);

	/// <summary>
	/// Destruktor
	/// </summary>
	~State();

	/// <summary>
	/// Sprawdza zawartosc stanu zmiennej quit
	/// </summary>
	/// <returns> wartosc zmiennej quit </returns>
	bool getQuit();

	/// <summary>
	/// Funckja sluzaca do aktualizacji zmiennych polozenia myszki
	/// </summary>
	virtual void updateMousePosition();

	/// <summary>
	/// Wirtualna funkcja update
	/// </summary>
	virtual void update() = 0;

	/// <summary>
	/// Wirtualna funkcja render
	/// </summary>
	/// <param name="target"></param>
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

