#pragma once
#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>

enum class InputDirection {
	Up, Down, Left, Right,
};

class InputHandler
{
public:
	static void recordInput();
	static void clearInputs();

	static bool inputExists(sf::Event);

private:
	InputHandler() { eventActive = false; }

	static sf::Event activeEvent;
	static bool eventActive;
};

