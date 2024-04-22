#include "Resource.h"

// Constructor
Sm::Resource::Resource(){}


// Setter
void Sm::Resource::set_Type_Resource(int type) {
	this->type_resource.type = type;
}
void Sm::Resource::set_Energi_Status(bool status) {
	this->energi_status = status;
}
void Sm::Resource::set_Energi_Count(int energi) {
	this->energi_count = energi;
}
void Sm::Resource::set_Id_Position(sf::Vector2i position) {
	this->id_position = position;
}


// Getter
int Sm::Resource::get_Type_Resource() {
	return this->type_resource.type;
}
bool Sm::Resource::get_Energi_Status() {
	return this->energi_status;
}
int Sm::Resource::get_Energi_Count() {
	return this->energi_count;
}
sf::Vector2i Sm::Resource::get_Id_Position() {
	return this->id_position;
}