#include "Environment.h"


Sm::Environment::Environment(sf::Vector2i size, int start_resource_count) {
	this->environment_config.size_environment = size;
	this->resources_count = start_resource_count;

	this->environment_zone_status = new Sm::Zone_status* [size.y];
	for (int i{ 0 }; i < size.y; i++) {
		this->environment_zone_status[i] = new Sm::Zone_status[size.x];
	}


	Sm::Environment::Spawn_Resource(start_resource_count);

}

void Sm::Environment::Spawn_Resource(int resource_count) {
	Sm::Environment::Add_Elements_Array(this->resources[this->resources_count], resource_count);

	


}

void Sm::Environment::Add_Elements_Array(Sm::Resource*& ar, int count) {
	Sm::Resource* memory_array = ar;

	ar = new Sm::Resource[this->resources_count + count];
	for (int i{ 0 }; i < this->resources_count; i++) {
		ar[i] = memory_array[i];
	}
	delete memory_array;

	this->resources_count += count;

}