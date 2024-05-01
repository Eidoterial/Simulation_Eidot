#include "Organism.h"


Sm::Organism::Organism(){}





// Setter
void Sm::Organism::set_Age_Organism(int age) {
	this->age_organism = age;
}
void Sm::Organism::set_Generation_Organism(int generation) {
	this->generation_organism = generation;
}
void Sm::Organism::set_Temperature_Organism(int temperature) {
	this->temperature_organism = temperature;
}


// Getter
int Sm::Organism::get_Age_Organism() {
	return this->age_organism;
}
int Sm::Organism::get_Generation_Organism() {
	return this->generation_organism;
}
int Sm::Organism::get_Temperature_Organism() {
	return this->temperature_organism;
}
