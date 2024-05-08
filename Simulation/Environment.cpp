#include "Environment.h"


Sm::Environment::Environment(sf::Vector2i size) {
	this->config.count_environment_zone = size;

	this->zones_information = new int* [size.y];
	for (int i{ 0 }; i < size.y; i++) {
		this->zones_information[i] = new int[size.x];

		for (int j{ 0 }; j < size.x; j++) {
			this->zones_information[i][j] = 0;

		}

	}

}

/// Getter
int** Sm::Environment::get_Zones_Information() {
	return this->zones_information;

}

Sm::Environment_config& Sm::Environment::get_Config() {
	return this->config;

}
