#include "Action_Organism.h"
#include <cmath>

/// CONSTRUCTOR
/// /////////////////////////////////////
Sm::Action_Organism::Action_Organism() {};
/// /////////////////////////////////////


/// GET RESULT ACTION
/// ////////////////////////////////////////////////////////
Sm::Result_Action Sm::Action_Organism::get_Result_Action() {
	return this->result_action;

}
/// ////////////////////////////////////////////////////////


/// CHECK ARROUND
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Sm::Action_Organism::check_Arround(Sm::Organism organism, sf::Vector2i count_environment_zone, std::vector < std::vector<int> > zones_information) {
	this->result_action.result_Check_Arround.resize(0);
	
	sf::Vector2i position_organism = organism.get_Config_Zone().id_E;

	Sm::Arround_Element_Info el;


	for (int i{ 0 }; i < 3; i++) {
		for (int j{ 0 }; j < 3; j++) {

			if (i == 1 && j == 1) continue;

			else if ((position_organism.x == 0 && j == 0) or (position_organism.y == 0 && i == 0)) continue;

			else if ((position_organism.x == count_environment_zone.x - 1 && j == 2) or (position_organism.y == count_environment_zone.y - 1 && i == 2)) continue;

			el.type = zones_information[position_organism.y - 1 + i][position_organism.x - 1 + j];

			el.position = sf::Vector2i(position_organism.x - 1 + j, position_organism.y - 1 + i);

			this->result_action.result_Check_Arround.push_back(el);					


		} 

	}

}
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/// CHECK ENERGI STATUS
/// //////////////////////////////////////////////////////////
void Sm::Action_Organism::check_Energi_Status(Sm::Organism organism) {

	double max = organism.gen_0_Decipherment();
	double min = organism.gen_1_Decipherment();

	if (max < min) {
		double t = max;

		max = min;

		min = t;

	}

	double a = std::round((min / (max - organism.get_Config_Organism().energi + min)) * 100) / 100;

	if (a > 1) a = 1;
	
	this->result_action.result_Check_Energi_Status = a;

}
/// //////////////////////////////////////////////////////////


/// CHECK MEMORY

void Sm::Action_Organism::check_Memory(Sm::Organism organism, std::vector<Sm::Organism> organisms, std::vector<Sm::Resource> resources) {
	this->result_action.result_Check_Memory.resize(8);

	for (int i{ 0 }; i < result_action.result_Check_Memory.size(); i++) {

		if (this->result_action.result_Check_Arround[i].type == 1) {
			Sm::Organism select_organism;

			for (int j{ 0 }; j < organisms.size(); j++) {
				if (organisms[j].get_Config_Zone().id_E == this->result_action.result_Check_Arround[i].position) {
					select_organism = organisms[j]; break;

				}

			}

			if (organism.get_Memory_Organisms().get_Good().size() > 0) {
				
				for (int j{ 0 }; j < organism.get_Memory_Organisms().get_Good().size(); j++) {
					
					if (organism.get_Memory_Organisms().get_Good()[j]._r == select_organism.get_Color_Zone()._r &&
						organism.get_Memory_Organisms().get_Good()[j]._g == select_organism.get_Color_Zone()._g &&
						organism.get_Memory_Organisms().get_Good()[j]._b == select_organism.get_Color_Zone()._b) {

						//this->result_action.result_Check_Memory[i] = 0 ;

					}

				}

			}
			else this->result_action.result_Check_Memory[i] = 1.0;

		}

	}



}
