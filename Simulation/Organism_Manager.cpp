#include "Organism_Manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

/// CONSTRUCTOR
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Sm::Organism_Manager::Organism_Manager(unsigned int start_count_organism, sf::Vector2i count_zone, std::vector < std::vector<int> > zones_information) {

    this->get_Config_Zone_Manager().zones_information = zones_information;

    this->get_Config_Zone_Manager().count_environment_zone = count_zone;

    this->organisms_information.resize(start_count_organism);

    for (int i{ 0 }; i < start_count_organism; i++) {
        this->set_Organism_Config(i);

    }

}
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/// ADD NEW ORGANISM
/// ///////////////////////////////////////////
void Sm::Organism_Manager::add_New_Organism() {
    this->organisms_information.resize(this->organisms_information.size() + 1);

    this->set_Organism_Config(this->organisms_information.size() - 1);

}
/// ///////////////////////////////////////////


/// REMOVE SELECT ORGANISM
/// ///////////////////////////////////////////////////////
void Sm::Organism_Manager::remove_Select_Organism(int id) {
    this->get_Config_Zone_Manager().zones_information[this->organisms_information[id].get_Config_Zone().id_E.y][this->organisms_information[id].get_Config_Zone().id_E.x] = 0;

    this->organisms_information.erase(this->organisms_information.begin() + id);

}
/// ///////////////////////////////////////////////////////


/// SET ORGANISM CONFIG
/// ////////////////////////////////////////////////////
void Sm::Organism_Manager::set_Organism_Config(int id) {
    std::srand(std::time(NULL));

    int id_position_x;
    int id_position_y;

    while (true) {
        id_position_x = std::rand() % this->get_Config_Zone_Manager().count_environment_zone.x;
        id_position_y = std::rand() % this->get_Config_Zone_Manager().count_environment_zone.y;

        if (this->get_Config_Zone_Manager().zones_information[id_position_y][id_position_x] == 0) {
            this->get_Config_Zone_Manager().zones_information[id_position_y][id_position_x] = 1; break;

        }

    }

    this->organisms_information[id].get_Config_Zone().id_E = sf::Vector2i(id_position_x, id_position_y);

    this->organisms_information[id].get_Config_Zone().position = sf::Vector2f(this->organisms_information[id].get_Config_Zone().size.x * id_position_x,
        this->organisms_information[id].get_Config_Zone().size.y * id_position_y);

    this->organisms_information[id].get_Config_Organism().serial_number.resize(this->organisms_information[id].get_Config_Organism().serial_number.size() + 1);
    this->organisms_information[id].get_Config_Organism().serial_number[this->organisms_information[id].get_Config_Organism().serial_number.size() - 1] = this->counter_serial_number;
    this->counter_serial_number++;

    this->organisms_information[id].get_Genom().resize(9);
    
    for (int i{ 0 }; i < this->organisms_information[id].get_Genom().size(); i++) {
        this->organisms_information[id].get_Genom()[i].get_Gen().resize(10);

        for (int j{ 0 }; j < this->organisms_information[id].get_Genom()[i].get_Gen().size(); j++) {
            this->organisms_information[id].get_Genom()[i].get_Gen()[j] = std::rand() % 2;

        }

    }

    this->organisms_information[id].get_Color_Zone()._r = 255;
    this->organisms_information[id].get_Color_Zone()._g = 255;
    this->organisms_information[id].get_Color_Zone()._b = 255;
    this->organisms_information[id].get_Color_Zone()._a = 255;


}
/// ////////////////////////////////////////////////////


/// CALL ACTION ORGANISM 1 SLOY
/// ////////////////////////////////////////////////////////////
void Sm::Organism_Manager::call_Action_Organism_1_Sloy(int id) {

    this->action_organism.check_Arround(this->organisms_information[id], this->get_Config_Zone_Manager().count_environment_zone, this->get_Config_Zone_Manager().zones_information);
    this->action_organism.check_Energi_Status(this->organisms_information[id]);

    std::cout << this->action_organism.get_Result_Action().result_Check_Energi_Status << std::endl;

    

}
/// ////////////////////////////////////////////////////////////


/// GET ORGANISM ON ID
/// ///////////////////////////////////////////////////////////
int Sm::Organism_Manager::get_Organism_On_Id(sf::Vector2i id) {
    for (int i{ 0 }; i < this->organisms_information.size(); i++) {
        if (this->organisms_information[i].get_Config_Zone().id_E == id) return i;

    }

}
/// ///////////////////////////////////////////////////////////


/// GET ORGANISM INFORMATION
/// //////////////////////////////////////////////////////////////////////////
std::vector<Sm::Organism>& Sm::Organism_Manager::get_Organisms_Information() {
    return this->organisms_information;

}
/// //////////////////////////////////////////////////////////////////////////