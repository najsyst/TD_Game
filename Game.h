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
	/// Wska�nik na obiekt klasy sf::RenderWindow
	/// </summary>
	sf::RenderWindow* window;

	/// <summary>
	/// Obiekt typu sf::Event
	/// </summary>
	sf::Event event;

	/// <summary>
	/// Wektor wska�nik�w do obiekt�w klasy State
	/// </summary>
	std::stack<State*> states;

	/// <summary>
	/// Funckja tworz�ca okno
	/// </summary>
	/// Funkcja opdowiada za tworzenie okna
	void initWindow();

	/// <summary>
	/// Funkcja tworz�ca stany gry
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
	/// Funkcja sprawdza czy gracz chce opu�ci� gr�
	/// </summary>
	void updateSFML();

	/// <summary>
	/// Funkcja aktualizuj�ca gr�
	/// </summary>
	void update();

	/// <summary>
	/// Funkcja renderuj�ca wszystkie obiekty u�ywane grze
	/// </summary>
	void render();

	/// <summary>
	/// Funkcja zawieraj�ca g��wn� p�tl� programu
	/// </summary>
	void run();
};