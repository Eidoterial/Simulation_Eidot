#include "Organism_Check_Around.h"


Sm::Check_Around::Check_Around(){}


void Sm::Check_Around::Check_Around_Organism(Sm::Organism organism, Sm::Environment environment) {

	for (int i{ 0 }; i < 3; i++) {
		for (int j{ 0 }; j < 3; j++) {
			if (i == 1 && j == 1) continue;
			else {
				this->element_around[i][j].type_element = environment.get_Environment_Elements_Status()[organism.get_Position().y - 1 + i][organism.get_Position().x - 1 + j].element_status;
				this->element_around[i][j].position_element = sf::Vector2i(organism.get_Position().y - 1 + i, organism.get_Position().x - 1 + j);
			}
		}
	}

}
