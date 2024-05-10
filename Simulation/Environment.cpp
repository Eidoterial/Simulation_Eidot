#include "Environment.h"

/// CONSTRUCTOR /////////////////////////////////
Sm::Environment::Environment(sf::Vector2i size) {
	this->config.count_environment_zone = size;

	for (int i{ 0 }; i < size.y; i++) {
		this->zones_information.push_back(std::vector<int>(size.x));

	}

}
/// /////////////////////////////////////////////


/// GET ZONES INFORMATION //////////////////////////////////////////////////
std::vector < std::vector<int> >& Sm::Environment::get_Zones_Information() {
	return this->zones_information;

}
/// ////////////////////////////////////////////////////////////////////////


/// GET CONFIG ////////////////////////////////////////
Sm::Environment_config& Sm::Environment::get_Config() {
	return this->config;

}
/// ///////////////////////////////////////////////////
