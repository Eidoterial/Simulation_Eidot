#include "Element_Environment.h"



Sm::Element_Environment::Element_Environment(){};


// Setter
void Sm::Element_Environment::set_Position(sf::Vector2i position) {
	this->position = position;
}
void Sm::Element_Environment::set_Type(int type) {
	this->type = type;
}


// Getter
sf::Vector2i Sm::Element_Environment::get_Position() {
	return this->position;
}
int Sm::Element_Environment::get_Type() {
	return this->type;
}