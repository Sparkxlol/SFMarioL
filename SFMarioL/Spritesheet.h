#pragma once
#include <SFML/Graphics.hpp>

class Spritesheet : sf::Sprite
{
public:
	Spritesheet();
	Spritesheet(sf::Texture& texture, sf::Vector2f initialSize);
	

private:
	sf::Vector2f totalSpriteSize;
	sf::Vector2f currentSpriteSize;
};


