#include "../headers/Game.h"
#include "../headers/Textures.h"

void Textures::initTextures()
{
	texture.loadFromFile(".\\assets\\bk.png");
	bckgrn.setSize(sf::Vector2f(1080.0f, 720.0f));
	bckgrn.setTexture(&texture);

	buttons.loadFromFile(".\\assets\\buttons.png");
	buttonl.loadFromFile(".\\assets\\buttonl.png");
	buttonr.loadFromFile(".\\assets\\buttonr.png");

	selector.loadFromFile(".\\assets\\selector.png");
	selector1.loadFromFile(".\\assets\\selector1.png");
	selector2.loadFromFile(".\\assets\\selector2.png");
	selector3.loadFromFile(".\\assets\\selector3.png");

	menu.loadFromFile(".\\assets\\menu.png");

	error.loadFromFile(".\\assets\\error.png");
	respuesta.loadFromFile(".\\assets\\respuesta.png");

	send.loadFromFile(".\\assets\\send.png");

	std::string preg1 = ".\\assets\\p";
	std::string preg2 = ".png";
	std::string res1 = ".\\assets\\r";
	std::string res2 = ".png";

	for (int i = 0; i < 10; i++)
	{
		pregTextureArray[i].loadFromFile(preg1 + std::to_string(1+i) + preg2);
		resTextureArray[i].loadFromFile(res1 + std::to_string(1 + i) + res2);
	}
}