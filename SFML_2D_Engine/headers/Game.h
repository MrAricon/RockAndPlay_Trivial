#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <windows.h>
#include <shellapi.h>

#include "ocilib.hpp"

class Game
{
public:
	sf::RenderWindow* window = nullptr;
	sf::VideoMode videoMode;
	sf::Image ico;
	sf::Event ev;
	sf::Vector2f mousePosition;

	sf::Font font;

	sf::Text username;
	sf::Text password;

	std::string strUsername;
	std::string strPassword;
	std::string strPasswordLength = "";

	bool userInput = false;
	bool passInput = false;

	int count = 0;

	int button = 0;
	int selector[10] = { 0 };
	int respuestas[10] = { 2, 3, 2, 2, 1, 1, 3, 3, 2, 3 };

	int puntuacion = 0;

	bool login = false;
	bool respuesta = false;
	bool loginError = false;

	void getText(std::string &text);
	void getPoints();

	void initWindow();
	void pollEvents();
	bool mousePos(int x, int y, int width, int height);
	void render();
	void update();
};