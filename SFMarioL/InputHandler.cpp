#include "InputHandler.h"

void InputHandler::recordInputs() {

}

void InputHandler::clearInputs() {
	eventActive = false;
}

bool InputHandler::inputExists(sf::Event checkedEvent) {
	return checkedEvent == activeEvent;
}