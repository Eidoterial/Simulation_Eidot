#include "Environment.h"

/// CONSTRUCTOR
/// /////////////////////////////////////////////
Sm::Environment::Environment(sf::Vector2i size) {
	this->get_Config_Zone_Manager().count_environment_zone = size;

	for (int i{ 0 }; i < size.y; i++) {
		this->get_Config_Zone_Manager().zones_information.push_back(std::vector<int>(size.x));

	}

}
/// /////////////////////////////////////////////

/// GET CONFIG
/// ///////////////////////////////////////////////////
Sm::Environment_config& Sm::Environment::get_Config() {
	return this->config;

}
/// ///////////////////////////////////////////////////
