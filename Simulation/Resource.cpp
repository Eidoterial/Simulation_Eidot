#include "Resource.h"

// Constructor
Sm::Resource::Resource(){}


// Setter
void Sm::Resource::set_Type_Resource(int type) {
	this->type_resource = type;
}
void Sm::Resource::set_Energi_Recover_Resource(int energi) {
	this->energi_recover_resource = energi;
}


// Getter
int Sm::Resource::get_Type_Resource() {
	return this->type_resource;
}
int Sm::Resource::get_Energi_Recover_Resource() {
	return this->energi_recover_resource;
}