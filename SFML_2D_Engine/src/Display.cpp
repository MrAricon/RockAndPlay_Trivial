#include "../headers/Game.h"
#include "../headers/Display.h"

void Display::quad(sf::Vector2f position, sf::Vector2f size, sf::Vector2f texSize, int suit, int number, sf::RenderWindow* window, sf::Texture texture)
{
	sf::VertexArray triangleStrip(sf::Quads, 4);

	triangleStrip[0].position = position;
	triangleStrip[1].position = sf::Vector2f(position.x + size.x, position.y);
	triangleStrip[2].position = sf::Vector2f(position.x + size.x, position.y + size.y);
	triangleStrip[3].position = sf::Vector2f(position.x, position.y + size.y);

	triangleStrip[0].texCoords = sf::Vector2f((0 + number) * texSize.x, (0 + suit) * texSize.y);
	triangleStrip[1].texCoords = sf::Vector2f(texSize.x * number + texSize.x, (0 + suit) * texSize.y);
	triangleStrip[2].texCoords = sf::Vector2f(texSize.x * number + texSize.x, texSize.y * suit + texSize.y);
	triangleStrip[3].texCoords = sf::Vector2f((0 + number) * texSize.x, texSize.y * suit + texSize.y);

	window->draw(triangleStrip, &texture);
}