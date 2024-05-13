#include "Resource_Manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

/// CONSTRUCTOR
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Sm::Resource_Manager::Resource_Manager(unsigned int start_count_resource, sf::Vector2i count_zone, std::vector < std::vector<int> > zones_information) {

    this->zones_information = zones_information;

    this->count_environment_zone = count_zone;
    
    this->resources_information.resize(start_count_resource);
    
    for (int i{ 0 }; i < start_count_resource; i++) {
        this->set_Resource_Config(i);

    }

}
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/// ADD NEW RESOURCE
/// ///////////////////////////////////////////
void Sm::Resource_Manager::add_New_Resource() {
    this->resources_information.resize(this->resources_information.size() + 1);

    this->set_Resource_Config(this->resources_information.size() - 1);

}
/// ///////////////////////////////////////////


/// REMOVE SELECT RESOURCE
/// ///////////////////////////////////////////////////////
void Sm::Resource_Manager::remove_Select_Resource(int id) {
    this->zones_information[this->resources_information[id].get_Config_Zone().id_E.y][this->resources_information[id].get_Config_Zone().id_E.x] = 0;

    this->resources_information.erase(this->resources_information.begin() + id);
    
}
/// ///////////////////////////////////////////////////////


/// SET RESOURCE CONFIG
/// ////////////////////////////////////////////////////
void Sm::Resource_Manager::set_Resource_Config(int id) {
    std::srand(std::time(NULL));

    int id_position_x;
    int id_position_y;

    while (true) {
        id_position_x = std::rand() % this->count_environment_zone.x;
        id_position_y = std::rand() % this->count_environment_zone.y;

        if (this->zones_information[id_position_y][id_position_x] == 0) {
            this->zones_information[id_position_y][id_position_x] = 2; break;
           
        } 

    }

    this->resources_information[id].get_Config_Zone().id_E = sf::Vector2i(id_position_x, id_position_y);

    this->resources_information[id].get_Config_Zone().position = sf::Vector2f(this->resources_information[id].get_Config_Zone().size.x * id_position_x,
                                                                           this->resources_information[id].get_Config_Zone().size.y * id_position_y);

    this->resources_information[id].get_Config_Resource().type = std::rand() % 2;

    this->resources_information[id].get_Config_Resource().energi = std::rand() % 5 + 1;

    if (this->resources_information[id].get_Config_Resource().type == 0) {
        this->resources_information[id].get_Color_Zone()._g = 200;

        this->resources_information[id].get_Color_Zone()._r = 100;

    }
    else {
        this->resources_information[id].get_Color_Zone()._g = 100;

        this->resources_information[id].get_Color_Zone()._r = 200;

    }

    this->resources_information[id].get_Color_Zone()._b = 255 / this->resources_information[id].get_Config_Resource().energi;

    this->resources_information[id].get_Color_Zone()._a = 255;


}
/// ////////////////////////////////////////////////////


/// GET RESOURCE ON ID
/// ///////////////////////////////////////////////////////////
int Sm::Resource_Manager::get_Resource_On_Id(sf::Vector2i id) {
    for (int i{ 0 }; i < this->resources_information.size(); i++) {
        if (this->resources_information[i].get_Config_Zone().id_E == id) return i;

    }

}
/// ///////////////////////////////////////////////////////////


/// GET RESOURCE INFORMATION
/// //////////////////////////////////////////////////////////////////////////
std::vector<Sm::Resource>& Sm::Resource_Manager::get_Resources_Information() {
    return this->resources_information;

}
/// //////////////////////////////////////////////////////////////////////////


/// GET ZONES INFORMATION
/// ////////////////////////////////////////////////////////////////////////////
std::vector < std::vector<int> > Sm::Resource_Manager::get_Zones_Information() {
    return this->zones_information;

}
/// ////////////////////////////////////////////////////////////////////////////
