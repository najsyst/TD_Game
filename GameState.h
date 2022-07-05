#pragma once
#include "TileMap.h"
#include "State.h"
#include "Button.h"
#include "Object.h"
#include "GObject.h"
#include "Archer.h"
#include "GArcher.h"
#include "Enemy.h"
#include "GEnemy.h"
#include "GBullet.h"
#include "Bullet.h"
#include "SharpShooter.h"
#include "GSharpShooter.h"

/// <summary>
/// Klasa posiadajaca implementajce stanu gry
/// </summary>
class GameState : public State
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
	/// Zmienna okreslajaca pewien czas
	/// </summary>
	sf::Time delta_time = sf::milliseconds(1000);
	/// <summary>
	/// Zmienna pomocnicza do tworzenia wiez
	/// </summary>
	int tower_number;
	/// <summary>
	/// Zmienne odpowiadajace za wyglad sceny
	/// </summary>
	sf::RectangleShape bottom, right_side;

	/// <summary>
	/// Zmienna okreslajaca trzcionke
	/// </summary>
	sf::Font font;

	/// <summary>
	/// Zmienna pomocnicza do przyciskow
	/// </summary>
	bool wasButtonSTARTpressed;

	/// <summary>
	/// Funkcja inicjalizujaca czcionke
	/// </summary>
	void initFonts();

	/// <summary>
	/// Funkcja inicjalizujaca przyciski
	/// </summary>
	void initButtons();
protected:
public:

	/// <summary>
	/// Wskaznik na obiekt klasy button trzymajacy klucze w postaci tesktu oraz przyciski
	/// </summary>
	std::map<std::string, Button*> buttons;
	
	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="window"> wskaznik na okno </param>
	/// <param name="states"> wskaznik do wektora wskaznikow </param>
	GameState(sf::RenderWindow* window, std::stack <State*>* states);

	/// <summary>
	/// Konstruktor
	/// </summary>
	~GameState();


	/// <summary>
	/// Wektor wskaznikow na obiekt klasy GObjects
	/// </summary>
	std::vector<GObject*> GObjects;

	/// <summary>
	/// Wektor wskaznikow na obiekt klasy Objects
	/// </summary>
	std::vector<Object*> Objects;

	/// <summary>
	/// Wskaznik na zmienna klasy TileMap
	/// </summary>
	TileMap* map;

	/// <summary>
	/// Funkcja update
	/// </summary>
	void update();

	/// <summary>
	/// Funkcja rysujaca wszystkie obiekty
	/// </summary>
	/// <param name="target"></param>
	void render(sf::RenderTarget* target);

	/// <summary>
	/// Funkcja do stworzenia przeciwnika
	/// </summary>
	void createEnemy();

	/// <summary>
	/// Funkcja do stworzenia wiezy
	/// </summary>
	void createTower();

	/// <summary>
	/// Funkcja do stworzenia pocisku
	/// </summary>
	void createBullet(Object* object, Object* object2);

	/// <summary>
	/// Funkcja update przycisku
	/// </summary>
	void updateButtons();

	/// <summary>
	/// Funkcja do rysowania przyciskow
	/// </summary>
	/// <param name="target"></param>
	void renderButtons(sf::RenderTarget* target);

	/// <summary>
	/// Funkcja update mapy
	/// </summary>
	void updateMap();
};

