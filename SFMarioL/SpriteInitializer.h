#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include "Spritesheet.h"

struct SpritesheetObject 
{
public:
	SpritesheetObject(std::string fileName, sf::Vector2i individualSize) {
		if (!this->texture.loadFromFile(fileName))
			std::cerr << fileName << " failed to construct." << std::endl;

		this->fileName = fileName; 
		this->individualSize = individualSize; 
	}

	sf::Texture texture;
	std::string fileName;
	sf::Vector2u individualSize;
};

class SpriteInitializer
{
public:
	void initializeTextures();
	Spritesheet createSpritesheet(std::string);
	
private:
	SpriteInitializer() {}
	std::string separateNextWord(std::string& initial, std::string separator);
	SpritesheetObject createSpriteInfoFromLine(std::string spriteInfo);
	std::string createMapKeyBasedOnFile(std::string fileName);

	std::unordered_map<std::string, SpritesheetObject> objectMap;
};

