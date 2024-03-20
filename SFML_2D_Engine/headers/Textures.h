#pragma once

class Textures
{
public:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::RectangleShape bckgrn;

	sf::Texture p1;
	sf::Texture r1;
	sf::Texture p2;
	sf::Texture r2;
	sf::Texture p3;
	sf::Texture r3;
	sf::Texture p4;
	sf::Texture r4;
	sf::Texture p5;
	sf::Texture r5;
	sf::Texture p6;
	sf::Texture r6;
	sf::Texture p7;
	sf::Texture r7;
	sf::Texture p8;
	sf::Texture r8;
	sf::Texture p9;
	sf::Texture r9;
	sf::Texture p10;
	sf::Texture r10;

	sf::Texture buttons;
	sf::Texture buttonl;
	sf::Texture buttonr;

	sf::Texture selector;
	sf::Texture selector1;
	sf::Texture selector2;
	sf::Texture selector3;

	sf::Texture menu;

	sf::Texture error;
	sf::Texture respuesta;

	sf::Texture send;

	sf::Texture pregTextureArray[10] = { p1, p2, p3, p4, p5, p6, p7, p8, p9, p10 };
	sf::Texture resTextureArray[10] = { r1, r2, r3, r4, r5, r6, r7, r8, r9, r10 };

	void initTextures();
};