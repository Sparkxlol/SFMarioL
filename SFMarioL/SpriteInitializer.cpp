#include "SpriteInitializer.h"

void SpriteInitializer::initializeTextures() {
	std::string spriteInfo;
	std::ifstream spriteFile("spriteInformation.txt");

	while (std::getline(spriteFile, spriteInfo)) {
		SpritesheetObject object = createSpriteInfoFromLine(spriteInfo);
		objectMap.insert({ createMapKeyBasedOnFile(object.fileName), object } );
	}

	spriteFile.close();
}

Spritesheet SpriteInitializer::createSpritesheet(std::string spriteKey) {
	if (objectMap.count(spriteKey) == 0) {
		std::cerr << spriteKey << " was not in the objectMap." << std::endl;
		return Spritesheet();
	}

	SpritesheetObject objectInfo = objectMap[spriteKey];
	return Spritesheet(objectInfo.texture, objectInfo.individualSize);
}

std::string SpriteInitializer::separateNextWord(std::string& initial, std::string separator) {
	int wordLength = initial.find(separator);
	std::string word = initial.substr(0, wordLength);
	word.erase(0, wordLength + separator.size());

	return word;
}

SpritesheetObject SpriteInitializer::createSpriteInfoFromLine(std::string spriteInfo) {
	std::string separator = " ";
	std::string fileName = separateNextWord(spriteInfo, separator);
	sf::Vector2i initialSpriteSize = sf::Vector2i(
		std::stoul(separateNextWord(spriteInfo, separator)),
		std::stoul(separateNextWord(spriteInfo, separator))
	);

	return SpritesheetObject(fileName, initialSpriteSize);
}

std::string SpriteInitializer::createMapKeyBasedOnFile(std::string fileName) {
	int lastDirectory = fileName.rfind("\\");
	int lastType = fileName.rfind(".");
	
	// Finds the last "/" and goes until the last "." and returns the new key.
	return fileName.substr(lastDirectory + 1, lastType - lastDirectory - 1);
}
