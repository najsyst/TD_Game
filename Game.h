#pragma once

#include "GameState.h"
#include "MainMenu.h"
/// <summary>
///  Klasa odpowiada za tworzenie gry
/// </summary>
 
class Game
{
private:
	/// <summary>
	/// WskaŸnik na obiekt klasy sf::RenderWindow
	/// </summary>
	sf::RenderWindow* window;

	/// <summary>
	/// Obiekt typu sf::Event
	/// </summary>
	sf::Event event;

	/// <summary>
	/// Wektor wskaŸników do obiektów klasy State
	/// </summary>
	std::stack<State*> states;

	/// <summary>
	/// Funckja tworz¹ca okno
	/// </summary>
	/// Funkcja opdowiada za tworzenie okna
	void initWindow();

	/// <summary>
	/// Funkcja tworz¹ca stany gry
	/// </summary>
	/// Funkcja tworzy stany gry
	void initStates();

protected:
public:
	/// <summary>
	/// Konstruktor
	/// </summary>
	/// Tworzy obiekt klasy Game
	Game();

	/// <summary>
	/// Destruktor
	/// </summary>
	/// Niszczy obiekt klasy Game
	~Game();

	/// <summary>
	/// Funkcja sprawdza czy gracz chce opuœciæ grê
	/// </summary>
	void updateSFML();

	/// <summary>
	/// Funkcja aktualizuj¹ca grê
	/// </summary>
	void update();

	/// <summary>
	/// Funkcja renderuj¹ca wszystkie obiekty u¿ywane grze
	/// </summary>
	void render();

	/// <summary>
	/// Funkcja zawieraj¹ca g³ówn¹ pêtlê programu
	/// </summary>
	void run();
};