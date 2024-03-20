#include "../headers/Game.h"
#include "../headers/Display.h"
#include "../headers/Textures.h"

int main()
{
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

	Textures texture;
	texture.initTextures();

	Game game;
	game.initWindow();

	Display hud;

	while (game.window->isOpen())
	{
		game.window->draw(texture.bckgrn);

		hud.quad(sf::Vector2f(250.0f, 25.0f), sf::Vector2f(800.0f, 150.0f), sf::Vector2f(800.0f, 150.0f), 0, 0, game.window, texture.pregTextureArray[game.count]);
		hud.quad(sf::Vector2f(250.0f, 250.0f), sf::Vector2f(800.0f, 450.0f), sf::Vector2f(800.0f, 450.0f), 0, 0, game.window, texture.resTextureArray[game.count]);

		switch (game.button)
		{
		case 0:
			hud.quad(sf::Vector2f(850.0f, 600.0f), sf::Vector2f(200.0f, 100.0f), sf::Vector2f(200.0f, 150.0f), 0, 0, game.window, texture.buttons);
			break;
		case 1:
			hud.quad(sf::Vector2f(850.0f, 600.0f), sf::Vector2f(200.0f, 100.0f), sf::Vector2f(200.0f, 150.0f), 0, 0, game.window, texture.buttonl);
			break;
		case 2:
			hud.quad(sf::Vector2f(850.0f, 600.0f), sf::Vector2f(200.0f, 100.0f), sf::Vector2f(200.0f, 150.0f), 0, 0, game.window, texture.buttonr);
			break;
		}

		switch (game.selector[game.count])
		{
		case 0:
			hud.quad(sf::Vector2f(100.0f, 250.0f), sf::Vector2f(150.0f, 400.0f), sf::Vector2f(150.0f, 400.0f), 0, 0, game.window, texture.selector);
			break;
		case 1:
			hud.quad(sf::Vector2f(100.0f, 250.0f), sf::Vector2f(150.0f, 400.0f), sf::Vector2f(150.0f, 400.0f), 0, 0, game.window, texture.selector1);
			break;
		case 2:
			hud.quad(sf::Vector2f(100.0f, 250.0f), sf::Vector2f(150.0f, 400.0f), sf::Vector2f(150.0f, 400.0f), 0, 0, game.window, texture.selector2);
			break;
		case 3:
			hud.quad(sf::Vector2f(100.0f, 250.0f), sf::Vector2f(150.0f, 400.0f), sf::Vector2f(150.0f, 400.0f), 0, 0, game.window, texture.selector3);
			break;
		}

		if (game.login == false)
		{
			hud.quad(sf::Vector2f(120.0f, 240.0f), sf::Vector2f(400.0f, 400.0f), sf::Vector2f(400.0f, 400.0f), 0, 0, game.window, texture.menu);

			game.username.setString(game.strUsername);
			game.username.setFont(game.font);
			game.username.setPosition(167.0f, 340.0f);

			game.password.setString(game.strPasswordLength);
			game.password.setFont(game.font);
			game.password.setPosition(167.0f, 453.0f);

			game.window->draw(game.username);
			game.window->draw(game.password);

			if (game.loginError == true)
			{
				hud.quad(sf::Vector2f(120.0f, 600.0f), sf::Vector2f(400.0f, 90.0f), sf::Vector2f(400.0f, 90.0f), 0, 0, game.window, texture.error);
			}
		}
		
		if (game.respuesta == true)
		{
			hud.quad(sf::Vector2f(80.0f, 600.0f), sf::Vector2f(650.0f, 90.0f), sf::Vector2f(650.0f, 90.0f), 0, 0, game.window, texture.respuesta);
		}

		if (game.count == 9)
		{
			hud.quad(sf::Vector2f(650.0f, 580.0f), sf::Vector2f(200.0f, 100.0f), sf::Vector2f(200.0f, 100.0f), 0, 0, game.window, texture.send);
		}

		game.update();

		game.window->display();

		game.render();
	}
	
	return 0;
}