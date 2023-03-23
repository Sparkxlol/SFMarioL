#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Spritesheet : sf::Sprite
{
public:
	Spritesheet() {};
	Spritesheet(sf::Texture& texture, sf::Vector2u initialSize);

	void setCurrentSpriteSize(sf::Vector2u newSize);
	void setSpriteLocationByPosition(sf::Vector2u newLocation);
	void moveSpriteLocation(unsigned int tileIndex);

private:
	sf::Vector2u totalSpriteSize;
	sf::Vector2u currentSpriteSize;

	sf::Vector2u currentSpriteLocation;
};


