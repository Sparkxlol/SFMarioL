#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class DefaultTest
{
public:
	virtual void update() = 0;

protected:
	sf::Clock clock;
	float testDuration = 0.0f;
};

