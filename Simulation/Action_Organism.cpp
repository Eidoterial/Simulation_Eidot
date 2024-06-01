#include "Action_Organism.h"
#include <cmath>
#include <iostream>

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
	this->result_action.result_Check_Energi_Status = 0.0;

	double max = organism.get_De_Gen().de_gen_0;
	double min = organism.get_De_Gen().de_gen_1;

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
/// ///////////////////////////////////////////////////////////
void Sm::Action_Organism::check_Memory(Sm::Organism organism) {
	this->result_action.result_Check_Memory_Good_Organism.resize(0);
	this->result_action.result_Check_Memory_Bad_Organism.resize(0);
	this->result_action.result_Check_Memory_Good_Resource.resize(0);
	this->result_action.result_Check_Memory_Bad_Resource.resize(0);

	std::vector<int> MCS = organism.get_De_Gen().de_gen_3;

	Sm::Memory_Target RCM;


	for (int i{ 0 }; i < organism.get_Memory_Organisms().get_Good().size(); i++) {
		
		if (MCS[0] != 0) RCM._r = organism.get_Memory_Organisms().get_Good()[i]._r;
		else RCM._r = 0;

		if (MCS[1] != 0) RCM._g = organism.get_Memory_Organisms().get_Good()[i]._g;
		else RCM._g = 0;

		if (MCS[2] != 0) RCM._b = organism.get_Memory_Organisms().get_Good()[i]._b;
		else RCM._b = 0;

		if (MCS[6] != 0) RCM.value = organism.get_Memory_Organisms().get_Good()[i].value;
		else RCM.value = 0;
		
		this->result_action.result_Check_Memory_Good_Organism.push_back(RCM);

	}

	for (int i{ 0 }; i < organism.get_Memory_Organisms().get_Bad().size(); i++) {

		if (MCS[3] != 0) RCM._r = organism.get_Memory_Organisms().get_Bad()[i]._r;
		else RCM._r = 0;

		if (MCS[4] != 0) RCM._g = organism.get_Memory_Organisms().get_Bad()[i]._g;
		else RCM._g = 0;

		if (MCS[5] != 0) RCM._b = organism.get_Memory_Organisms().get_Bad()[i]._b;
		else RCM._b = 0;

		if (MCS[6] != 0) RCM.value = organism.get_Memory_Organisms().get_Bad()[i].value;
		else RCM.value = 0;

		this->result_action.result_Check_Memory_Bad_Organism.push_back(RCM);

	}

	for (int i{ 0 }; i < organism.get_Memory_Resources().get_Good().size(); i++) {

		if (MCS[0] != 0) RCM._r = organism.get_Memory_Resources().get_Good()[i]._r;
		else RCM._r = 0;

		if (MCS[1] != 0) RCM._g = organism.get_Memory_Resources().get_Good()[i]._g;
		else RCM._g = 0;

		if (MCS[2] != 0) RCM._b = organism.get_Memory_Resources().get_Good()[i]._b;
		else RCM._b = 0;

		if (MCS[6] != 0) RCM.value = organism.get_Memory_Resources().get_Good()[i].value;
		else RCM.value = 0;

		this->result_action.result_Check_Memory_Good_Resource.push_back(RCM);

	}

	for (int i{ 0 }; i < organism.get_Memory_Resources().get_Bad().size(); i++) {

		if (MCS[3] != 0) RCM._r = organism.get_Memory_Resources().get_Bad()[i]._r;
		else RCM._r = 0;

		if (MCS[4] != 0) RCM._g = organism.get_Memory_Resources().get_Bad()[i]._g;
		else RCM._g = 0;

		if (MCS[5] != 0) RCM._b = organism.get_Memory_Resources().get_Bad()[i]._b;
		else RCM._b = 0;

		if (MCS[6] != 0) RCM.value = organism.get_Memory_Resources().get_Bad()[i].value;
		else RCM.value = 0;

		this->result_action.result_Check_Memory_Bad_Resource.push_back(RCM);

	}

}
/// ///////////////////////////////////////////////////////////


/// CHECK PRIORITY MOVE
/// //////////////////////////////////////////////////////////////////
void Sm::Action_Organism::check_Priority_Move(Sm::Organism organism) {
	this->result_action.result_Check_Priority_Move = 0.0;

	if (organism.get_De_Gen().de_gen_4) {
		int count_r_o{ 0 };

		for (int i{ 0 }; i < this->result_action.result_Check_Arround.size(); i++) {
			if (this->result_action.result_Check_Arround[i].type == 1 || this->result_action.result_Check_Arround[i].type == 2) count_r_o++;

		}

		result_action.result_Check_Priority_Move = std::round(1.0 / (1 + count_r_o) * (1 + this->result_action.result_Check_Energi_Status) * 100) / 100;

	}

}
/// //////////////////////////////////////////////////////////////////


/// CHECK PRIORITY CONVERTATION
/// //////////////////////////////////////////////////////////////////////////
void Sm::Action_Organism::check_Priority_Convertation(Sm::Organism organism) {
	this->result_action.result_Check_Priority_Convertation = 0.0;

	if (organism.get_De_Gen().de_gen_8) {
		int count_r_o{ 0 };

		for (int i{ 0 }; i < this->result_action.result_Check_Arround.size(); i++) {
			if (this->result_action.result_Check_Arround[i].type == 1 || this->result_action.result_Check_Arround[i].type == 2) count_r_o++;

		}

		this->result_action.result_Check_Priority_Convertation = std::round(1.0 / (1 + count_r_o) / (1 + this->result_action.result_Check_Energi_Status) * 100) / 100;

	}

}
/// //////////////////////////////////////////////////////////////////////////


/// CHECK PRIORITY REPRODUCTION
/// //////////////////////////////////////////////////////////////////////////
void Sm::Action_Organism::check_Priority_Reproduction(Sm::Organism organism) {
	this->result_action.result_Check_Priority_Reproduction = 0.0;


	if (organism.get_De_Gen().de_gen_6 && organism.get_Config_Organism().energi >= organism.get_De_Gen().de_gen_7) {

		for (int i{ 0 }; i < this->result_action.result_Check_Arround.size(); i++) {
			if (this->result_action.result_Check_Arround[i].type == 0) {
				this->result_action.result_Check_Priority_Reproduction = 1.0;
				break;

			}

		}

	}

}
/// //////////////////////////////////////////////////////////////////////////


/// CHECK PRIORITY ABSORPTION
/// ////////////////////////////////////////////////////////////////////////
void Sm::Action_Organism::check_Priority_Absorption(Sm::Organism organism) {
	this->result_action.result_Check_Priority_Absorption = 0.0;

	if (organism.get_De_Gen().de_gen_5) {
		int count_v{ 0 };

		for (int i{ 0 }; i < this->result_action.result_Check_Arround.size(); i++) {
			if (this->result_action.result_Check_Arround[i].type == 0) count_v++;

		}

		this->result_action.result_Check_Priority_Absorption = std::round(1.0 / (1 + count_v) * (1 + this->result_action.result_Check_Energi_Status) * 100) / 100;

	}

}
/// ////////////////////////////////////////////////////////////////////////


/// MOVE ORGANISM
/// ////////////////////////////////////////////////////////////////////
sf::Vector2i Sm::Action_Organism::move_Organism(Sm::Organism organism) {
	int selecter{ 0 };

	std::cout << "M";

	while (true) {
		selecter = std::rand() % this->result_action.result_Check_Arround.size();

		if (this->result_action.result_Check_Arround[selecter].type == 0) break;

	}

	return this->result_action.result_Check_Arround[selecter].position;

}
/// ////////////////////////////////////////////////////////////////////


/// ENERGI CONVERTATION ORGANISM
/// //////////////////////////////////////////////////////////////////////////
int Sm::Action_Organism::energi_Convertation_Organism(Sm::Organism organism) {
	int count_void{ 0 };

	std::cout << "C";

	for (int i{ 0 }; i < this->result_action.result_Check_Arround.size(); i++) {
		if (this->result_action.result_Check_Arround[i].type == 0) count_void++;

	}
	
	return count_void;

}
/// //////////////////////////////////////////////////////////////////////////


/// REPRODUCTION ORGANISM
/// ////////////////////////////////////////////////////////////////////////////
sf::Vector2i Sm::Action_Organism::reproduction_Organism(Sm::Organism organism) {

	int selecter{ 0 };

	std::cout << "R";

	while (true) {
		selecter = std::rand() % this->result_action.result_Check_Arround.size();

		if (this->result_action.result_Check_Arround[selecter].type == 0) break;

	}

	return sf::Vector2i(this->result_action.result_Check_Arround[selecter].position);

}
/// ////////////////////////////////////////////////////////////////////////////


/// ABSORPTION ORGANISM
/// //////////////////////////////////////////////////////////////////////////
sf::Vector2i Sm::Action_Organism::Adsorption_Organism(Sm::Organism organism) {
	int selecter{ 0 };

	int limiter{ 0 };

	std::cout << "A";

	while (10 > limiter) {
		selecter = std::rand() % this->result_action.result_Check_Arround.size();

		if (this->result_action.result_Check_Arround[selecter].type == 2) return sf::Vector2i(this->result_action.result_Check_Arround[selecter].position);

		limiter++;
	}

	return sf::Vector2i(-1, -1);
}
/// //////////////////////////////////////////////////////////////////////////