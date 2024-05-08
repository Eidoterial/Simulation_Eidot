#include "Resource_Manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

Sm::Resource_Manager::Resource_Manager(unsigned int start_count_resource, sf::Vector2i count_zone, int** zones_information)
{

    this->zones_information = zones_information;
    this->count_environment_zone = count_zone;
    this->resources_information = new Sm::Resource[start_count_resource];
    for (int i{ 0 }; i < start_count_resource; i++) {
        this->set_Resource_Config(i);
    }
}


void Sm::Resource_Manager::set_Resource_Config(int id) {
    std::srand(std::time(NULL));

    int id_position_x;
    int id_position_y;

    while (true) {
        id_position_x = std::rand() % this->count_environment_zone.x;
        id_position_y = std::rand() % this->count_environment_zone.y;

        if (this->zones_information[id_position_y][id_position_x] == 0) {
            this->zones_information[id_position_y][id_position_x] = 2;
            break;

        } 

    }

    this->resources_information->get_Config_Zone().id = sf::Vector2i(id_position_x, id_position_y);

    this->resources_information->get_Config_Zone().position = sf::Vector2f(this->resources_information->get_Config_Zone().size.x * id_position_x,
                                                                           this->resources_information->get_Config_Zone().size.y * id_position_y);

    this->resources_information->get_Config_Resource().type = std::rand() % 2;

    this->resources_information->get_Config_Resource().energi = std::rand() % 5 + 1;


}


Sm::Resource* Sm::Resource_Manager::get_Resources_Information()
{
    return this->resources_information;

}
