#include "Environment.h"

#include <iostream>


Sm::Environment::Environment(sf::Vector2i size, unsigned int start_resource_count) {
	std::srand(std::time(NULL));


	this->environment_config.size_environment = size;

	// Create array status elements 
	this->environment_elements_status = new Sm::Environment_elements_status* [size.y];
	for (int i{ 0 }; i < size.y; i++) {
		this->environment_elements_status[i] = new Sm::Environment_elements_status[size.x];
	}

	// Create start resource
	this->resources = new Sm::Resource[start_resource_count];
	for (int i{ 0 }; i < start_resource_count; i++) {
		this->set_Resource(i);
	}
	this->environment_config.resources_count = start_resource_count;
}

void Sm::Environment::set_Resource(int id) {

	while (true) {
		int resource_position_x = std::rand() % this->environment_config.size_environment.x;
		int resource_position_y = std::rand() % this->environment_config.size_environment.y;

		if (!this->environment_elements_status[resource_position_y][resource_position_x].zone_stats) {
			this->resources[id].set_Position(sf::Vector2i(resource_position_x, resource_position_y));
			this->resources[id].set_Type(2);
			this->resources[id].set_Type_Resource(std::rand() % 3);
			if (this->resources[id].get_Type_Resource()) this->resources[id].set_Energi_Recover_Resource(std::rand() % 11);
			else this->resources[id].set_Energi_Recover_Resource(std::rand() % 5);
			
			this->environment_elements_status[resource_position_y][resource_position_x].zone_stats = 2;
			break;
		}
	}
}

void Sm::Environment::add_Resource() {
	Sm::Resource* resource_memory = this->resources;

	this->resources = new Sm::Resource[this->environment_config.resources_count += 1];

	for (int i{ 0 }; i < this->environment_config.resources_count; i++) {
		if (i == this->environment_config.resources_count - 1) this->set_Resource(this->environment_config.resources_count - 1);
		else this->resources[i] = resource_memory[i];
		
	}
	delete resource_memory;
}



// Setter
void Sm::Environment::set_Season(int season) {
	this->environment_config.season_environment = season;
}
void Sm::Environment::set_Time(int time) {
	this->environment_config.time_environment = time;
}
void Sm::Environment::set_Temperature(int temperature) {
	this->environment_config.temperature_environment = temperature;
}


// Getter
sf::Vector2i Sm::Environment::get_Size() {
	return this->environment_config.size_environment;
}
int Sm::Environment::get_Season() {
	return this->environment_config.season_environment;
}
int Sm::Environment::get_Time() {
	return this->environment_config.time_environment;
}
int Sm::Environment::get_temperature() {
	return this->environment_config.temperature_environment;
}
Sm::Environment_elements_status** Sm::Environment::get_Environment_Elements_Status() {
	return this->environment_elements_status;
}
Sm::Resource* Sm::Environment::get_Resources() {
	return this->resources;
}
Sm::Environment_config& Sm::Environment::get_Environment_Config() {
	return this->environment_config;
}