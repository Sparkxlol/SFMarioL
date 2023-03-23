#include "Spritesheet.h"

Spritesheet::Spritesheet(sf::Texture& texture, sf::Vector2u initialSize) {
	setTexture(texture);

	currentSpriteSize = initialSize;
	totalSpriteSize = getTexture()->getSize();

	currentSpriteLocation = sf::Vector2u(0, 0);
}

void Spritesheet::setCurrentSpriteSize(sf::Vector2u newSize) {
	if (newSize.x > totalSpriteSize.x || newSize.y > totalSpriteSize.y) {
		std::cerr << "Invalid sprite size at " << newSize.x << ", " << newSize.y << std::endl;
		return;
	}

	currentSpriteSize = newSize;
}

void Spritesheet::setSpriteLocationByPosition(sf::Vector2u newLocation) {
	if (newLocation.x + currentSpriteSize.x > totalSpriteSize.x || 
		newLocation.y + currentSpriteSize.y > totalSpriteSize.y) {
		std::cerr << "Invalid sprite location at " << newLocation.x << ", " << newLocation.y << std::endl;
		return;
	}

	currentSpriteLocation = newLocation;
}

// Moves the current location of the sprite "tileIndex" to the right
// Prevents change if out-of-bounds off the end of the spritesheet.
void Spritesheet::moveSpriteLocation(unsigned int tileIndex) {
	sf::Vector2u newLocation = currentSpriteLocation;

	unsigned int xChange = newLocation.x + (currentSpriteSize.x * tileIndex) % totalSpriteSize.x;
	unsigned int yChange = newLocation.y + (currentSpriteSize.x * tileIndex) / totalSpriteSize.x;

	newLocation.x += xChange;
	newLocation.y += yChange;

	if (newLocation.x + currentSpriteSize.x > totalSpriteSize.x ||
		newLocation.y + currentSpriteSize.y > totalSpriteSize.y) {
		std::cerr << "Invalid sprite location at " << newLocation.x << ", " << newLocation.y << std::endl;
		return;
	}

	currentSpriteLocation = newLocation;
}
