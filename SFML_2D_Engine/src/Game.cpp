#include "../headers/Game.h"
#include "../headers/Textures.h"
#include "../headers/Display.h"
#include "../headers/DB.h"

void Game::getText(std::string &text)
{
	if (ev.text.unicode != 8)
	{
		text += static_cast<char>(ev.text.unicode);
	}
	else {
		if (text.length() > 0)
		{
			text.pop_back();
		}
	}
}

void Game::getPoints()
{
	for (int i = 0; i < 10; i++)
	{
		if (selector[i] == respuestas[i])
		{
			puntuacion += 100;
		}
	}
	DB::insert(strUsername, strPassword, puntuacion, respuesta);
}

void Game::initWindow()
{
	videoMode.width = 1080;
	videoMode.height = 720;
	window = new sf::RenderWindow(videoMode, "Rock And Play - La Sagrera Trivia", sf::Style::Titlebar | sf::Style::Close);
	//window->setPosition(sf::Vector2i(150, 100));
	window->setFramerateLimit(60);
	window->setPosition(sf::Vector2i(100, -1000));
	ico.loadFromFile(".\\assets\\logo.png");
	window->setIcon(ico.getSize().x, ico.getSize().y, ico.getPixelsPtr());

	font.loadFromFile("COPRGTB.TTF");
}

void Game::pollEvents()
{
	while (window->pollEvent(ev))
	{
		sf::Vector2i winPos = window->getPosition();
		sf::Vector2i mouse = sf::Mouse::getPosition();
		switch (ev.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			switch (ev.key.code)
			{
			case sf::Keyboard::Escape:
				window->close();
				break;
			default:
				std::cout << ev.key.code << "\n";
				break;
			}
			break;
		case sf::Event::TextEntered:
			if (passInput == true)
			{
				getText(strPassword);
				if (ev.text.unicode != 8)
				{
					strPasswordLength += ".";
				}
				else {
					if (strPasswordLength.length() > 0)
					{
						strPasswordLength.pop_back();
					}
				}
			}
			if (userInput == true)
			{
				getText(strUsername);
			}
			break;
		case sf::Event::MouseButtonPressed:
			if (login == true)
			{
				if (mousePos(870, 580, 48, 93) == true && count != 0)
				{
					button = 1;
					count--;
				}
				if (mousePos(980, 580, 48, 93) == true && count != 9)
				{
					button = 2;
					count++;
				}
				if (mousePos(180, 270, 30, 35) == true)
				{
					if (selector[count] == 1)
					{
						selector[count] = 0;
					}
					else
					{
						selector[count] = 1;
					}
				}
				if (mousePos(180, 410, 30, 35) == true)
				{
					if (selector[count] == 2)
					{
						selector[count] = 0;
					}
					else
					{
						selector[count] = 2;
					}
				}
				if (mousePos(180, 540, 30, 35) == true)
				{
					if (selector[count] == 3)
					{
						selector[count] = 0;
					}
					else
					{
						selector[count] = 3;
					}
				}
				if (mousePos(660, 640, 180, 35) == true)
				{
					respuesta = false;
					getPoints();
				}
			}
			else
			{
				if (mousePos(160, 330, 310, 50) == true)
				{
					userInput = true;
					passInput = false;
				}
				else if (mousePos(160, 450, 310, 50) == true)
				{
					passInput = true;
					userInput = false;
				}
				else
				{
					passInput = false;
					userInput = false;
				}

				if (mousePos(160, 520, 310, 30) == true)
				{
					respuesta = false;
					DB::login(strUsername, strPassword, login, loginError, respuesta);
				}
				if (mousePos(160, 570, 310, 30) == true)
				{
					ShellExecute(0, 0, L"http://rockandplay.sytes.net/entradas.php", 0, 0, SW_SHOW);
				}
			}
			break;
		case sf::Event::MouseButtonReleased:
			mousePosition.x = mouse.x - winPos.x - 8;
			mousePosition.y = mouse.y - winPos.y - 30;
			std::cout << mousePosition.x << " " << mousePosition.y << "\n";
			button = 0;
			break;
		}
	}
}

bool Game::mousePos(int x, int y, int width, int height)
{
	sf::Vector2i winPos = window->getPosition();
	sf::Vector2i mousePos = sf::Mouse::getPosition();
	int mouseX = mousePos.x - winPos.x - 9;
	int mouseY = mousePos.y - winPos.y - 30;

	if (x < mouseX && x + width > mouseX && y < mouseY && y + height > mouseY)
	{
		return true;
	}
	return false;
}

void Game::render()
{
	window->clear();
}

void Game::update()
{
	pollEvents();
}