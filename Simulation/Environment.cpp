#include "Environment.h"


Sm::Environment::Environment(sf::Vector2i size, int start_resource_count) {
	this->environment_config.size_environment = size;
	this->resources_count = start_resource_count;

	this->environment_zone_status = new Sm::Zone_status* [size.y];
	for (int i{ 0 }; i < size.y; i++) {
		this->environment_zone_status[i] = new Sm::Zone_status[size.x];
	}


}


// Setter
void Sm::Environment::set_Period_Spawn_Resource(int period) {
	this->environment_config.period_spawn_resource = period;
}
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
Sm::Zone_status** Sm::Environment::get_Environment_Zone_Status() {
	return this->environment_zone_status;
}