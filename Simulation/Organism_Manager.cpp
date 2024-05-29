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


/// ADD COPY ORGANISM
/// /////////////////////////////////////////////////////////////////////////
void Sm::Organism_Manager::add_Copy_Organism(int id, sf::Vector2i position) {
    
    this->organisms_information.resize(this->organisms_information.size() + 1);
    int id_c = this->organisms_information.size() - 1;

    this->get_Config_Zone_Manager().zones_information[position.y][position.x] = 1;

    this->organisms_information[id_c].get_Config_Zone().id_E = sf::Vector2i(position.x, position.y);

    this->organisms_information[id_c].get_Config_Zone().position = sf::Vector2f(this->organisms_information[id_c].get_Config_Zone().size.x * position.x,
        this->organisms_information[id_c].get_Config_Zone().size.y * position.y);

    this->organisms_information[id_c].get_Config_Organism().serial_number.resize(this->organisms_information[id_c].get_Config_Organism().serial_number.size() + 1);
    this->organisms_information[id_c].get_Config_Organism().serial_number[this->organisms_information[id_c].get_Config_Organism().serial_number.size() - 1] = this->counter_serial_number;
    this->counter_serial_number++;

    this->organisms_information[id_c].get_Genom().resize(10);
    for (int i{ 0 }; i < this->organisms_information[id_c].get_Genom().size(); i++) {
        this->organisms_information[id_c].get_Genom()[i].get_Gen().resize(10);

        for (int j{ 0 }; j < this->organisms_information[id].get_Genom()[i].get_Gen().size(); j++) {
            this->organisms_information[id_c].get_Genom()[i].get_Gen()[j] = this->organisms_information[id].get_Genom()[i].get_Gen()[j];

        }

    }

    this->organisms_information[id_c].get_Color_Zone()._r = 255;
    this->organisms_information[id_c].get_Color_Zone()._g = 255;
    this->organisms_information[id_c].get_Color_Zone()._b = 255;
    this->organisms_information[id_c].get_Color_Zone()._a = 255;

}
/// /////////////////////////////////////////////////////////////////////////


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

    this->organisms_information[id].get_Genom().resize(10);


    /// Test //////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    this->organisms_information[id].get_Memory_Organisms().get_Good().resize(1);
    this->organisms_information[id].get_Memory_Organisms().get_Good()[0]._r = std::rand() % 256;
    this->organisms_information[id].get_Memory_Organisms().get_Good()[0]._g = std::rand() % 256;
    this->organisms_information[id].get_Memory_Organisms().get_Good()[0]._b = std::rand() % 256;
    this->organisms_information[id].get_Memory_Organisms().get_Good()[0].value = std::rand() % 5;

    this->organisms_information[id].get_Memory_Organisms().get_Bad().resize(1);
    this->organisms_information[id].get_Memory_Organisms().get_Bad()[0]._r = std::rand() % 256;
    this->organisms_information[id].get_Memory_Organisms().get_Bad()[0]._g = std::rand() % 256;
    this->organisms_information[id].get_Memory_Organisms().get_Bad()[0]._b = std::rand() % 256;
    this->organisms_information[id].get_Memory_Organisms().get_Bad()[0].value = std::rand() % 5;

    this->organisms_information[id].get_Memory_Resources().get_Good().resize(1);
    this->organisms_information[id].get_Memory_Resources().get_Good()[0]._r = std::rand() % 256;
    this->organisms_information[id].get_Memory_Resources().get_Good()[0]._g = std::rand() % 256;
    this->organisms_information[id].get_Memory_Resources().get_Good()[0]._b = std::rand() % 256;
    this->organisms_information[id].get_Memory_Resources().get_Good()[0].value = std::rand() % 5;

    this->organisms_information[id].get_Memory_Resources().get_Bad().resize(1);
    this->organisms_information[id].get_Memory_Resources().get_Bad()[0]._r = std::rand() % 256;
    this->organisms_information[id].get_Memory_Resources().get_Bad()[0]._g = std::rand() % 256;
    this->organisms_information[id].get_Memory_Resources().get_Bad()[0]._b = std::rand() % 256;
    this->organisms_information[id].get_Memory_Resources().get_Bad()[0].value = std::rand() % 5;
    */
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    /// //////////////////////////////////////////////////////////////////////////////////////////////

    
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
void Sm::Organism_Manager::call_Action_Organism_1_Sloy(Sm::Organism organism) {

    this->action_organism.check_Arround(organism, this->get_Config_Zone_Manager().count_environment_zone, this->get_Config_Zone_Manager().zones_information);
    this->action_organism.check_Energi_Status(organism);
    this->action_organism.check_Memory(organism);

}
/// ////////////////////////////////////////////////////////////


/// CALL ACTION ORGANISM 2 SLOY
/// ////////////////////////////////////////////////////////////
void Sm::Organism_Manager::call_Action_Organism_2_Sloy(Sm::Organism organism) {

    this->action_organism.check_Priority_Move(organism);
    this->action_organism.check_Priority_Convertation(organism);
    this->action_organism.check_Priority_Reproduction(organism);

}
/// ////////////////////////////////////////////////////////////


/// CALL ACTION ORGANISM

void Sm::Organism_Manager::call_Action_Organism(Sm::Organism organism) {

    bool rem{ true };

    int id = this->get_Organism_On_Id(organism.get_Config_Zone().id_E);

    if (organism.get_Config_Organism().energi > organism.gen_0_Decipherment()) {

        if (this->action_organism.get_Result_Action().result_Check_priority_Reproduction > 0.0) {
            
            this->add_Copy_Organism(id, this->action_organism.reproduction_Organism(this->organisms_information[id]));
            this->organisms_information[this->organisms_information.size() - 1].get_Config_Organism().energi = this->organisms_information[id].get_Config_Organism().energi / 2;

            this->organisms_information[id].get_Config_Organism().energi -= this->organisms_information[id].gen_7_Decipherment();

        }

        else if (this->action_organism.get_Result_Action().result_Check_Priority_Move > 0.0) {
            sf::Vector2i new_position(this->action_organism.move_Organism(this->organisms_information[id]));

            this->organisms_information[id].get_Config_Organism().energi--;

            this->get_Config_Zone_Manager().zones_information[this->organisms_information[id].get_Config_Zone().id_E.y][this->organisms_information[id].get_Config_Zone().id_E.x] = 0;
            this->get_Config_Zone_Manager().zones_information[new_position.y][new_position.x] = 1;

            this->organisms_information[id].get_Config_Zone().id_E = new_position;

        }    

        else if (this->action_organism.get_Result_Action().result_Check_Priority_Convertation > 0.0) {
            this->organisms_information[id].get_Config_Organism().energi += this->action_organism.energi_Convertation_Organism(this->organisms_information[id]);

        }

    }
    else this->remove_Select_Organism(id); rem = false;

    if (organism.get_Config_Organism().energi <= organism.gen_0_Decipherment() && rem) this->remove_Select_Organism(id);
        

}


/// GET ORGANISM ON ID
/// ///////////////////////////////////////////////////////////
int Sm::Organism_Manager::get_Organism_On_Id(sf::Vector2i id) {
    for (int i{ 0 }; i < this->organisms_information.size(); i++) {
        if (this->organisms_information[i].get_Config_Zone().id_E == id) return i;

    }
    return this->organisms_information.size();

}
/// ///////////////////////////////////////////////////////////


/// GET ORGANISM INFORMATION
/// //////////////////////////////////////////////////////////////////////////
std::vector<Sm::Organism>& Sm::Organism_Manager::get_Organisms_Information() {
    return this->organisms_information;

}
/// //////////////////////////////////////////////////////////////////////////


void Sm::Organism_Manager::info_action() {

    for (int i{ 0 }; i < this->action_organism.get_Result_Action().result_Check_Arround.size(); i++) {
        std::cout << "Type element: " << this->action_organism.get_Result_Action().result_Check_Arround[i].type << " , ";
        std::cout << "Position element: " << this->action_organism.get_Result_Action().result_Check_Arround[i].position.x << "." << this->action_organism.get_Result_Action().result_Check_Arround[i].position.y << std::endl;

    }


    std::cout << "Energi status: " << this->action_organism.get_Result_Action().result_Check_Energi_Status << std::endl;

    if (this->action_organism.get_Result_Action().result_Check_Memory_Good_Organism.size() != 0) {
        std::cout << "Memory good organism" << std::endl;

        for (int i{ 0 }; i < this->action_organism.get_Result_Action().result_Check_Memory_Good_Organism.size(); i++) {
            std::cout << "Slot: " << i << std::endl;

            for (int j{ 0 }; j < 4; j++) {
                std::cout << "Red: " << this->action_organism.get_Result_Action().result_Check_Memory_Good_Organism[i]._r << " , ";
                std::cout << "Green: " << this->action_organism.get_Result_Action().result_Check_Memory_Good_Organism[i]._g << " , ";
                std::cout << "Blue: " << this->action_organism.get_Result_Action().result_Check_Memory_Good_Organism[i]._b << " , ";
                std::cout << "Value energi: " << this->action_organism.get_Result_Action().result_Check_Memory_Good_Organism[i].value << std::endl;

            }
            
        }

    }
    else std::cout << "Not memory good organism" << std::endl;

    if (this->action_organism.get_Result_Action().result_Check_Memory_Good_Organism.size() != 0) {
        std::cout << "Memory bad organism" << std::endl;

        for (int i{ 0 }; i < this->action_organism.get_Result_Action().result_Check_Memory_Bad_Organism.size(); i++) {
            std::cout << "Slot: " << i << std::endl;

            for (int j{ 0 }; j < 4; j++) {
                std::cout << "Red: " << this->action_organism.get_Result_Action().result_Check_Memory_Bad_Organism[i]._r << " , ";
                std::cout << "Green: " << this->action_organism.get_Result_Action().result_Check_Memory_Bad_Organism[i]._g << " , ";
                std::cout << "Blue: " << this->action_organism.get_Result_Action().result_Check_Memory_Bad_Organism[i]._b << " , ";
                std::cout << "Value energi: " << this->action_organism.get_Result_Action().result_Check_Memory_Bad_Organism[i].value << std::endl;

            }

        }

    }
    else std::cout << "Not memory bad organism" << std::endl;

    if (this->action_organism.get_Result_Action().result_Check_Memory_Good_Resource.size() != 0) {
        std::cout << "Memory good resource" << std::endl;

        for (int i{ 0 }; i < this->action_organism.get_Result_Action().result_Check_Memory_Good_Resource.size(); i++) {
            std::cout << "Slot: " << i << std::endl;

            for (int j{ 0 }; j < 4; j++) {
                std::cout << "Red: " << this->action_organism.get_Result_Action().result_Check_Memory_Good_Resource[i]._r << " , ";
                std::cout << "Green: " << this->action_organism.get_Result_Action().result_Check_Memory_Good_Resource[i]._g << " , ";
                std::cout << "Blue: " << this->action_organism.get_Result_Action().result_Check_Memory_Good_Resource[i]._b << " , ";
                std::cout << "Value energi: " << this->action_organism.get_Result_Action().result_Check_Memory_Good_Resource[i].value << std::endl;

            }

        }

    }
    else std::cout << "Not memory good resource" << std::endl;

    if (this->action_organism.get_Result_Action().result_Check_Memory_Good_Resource.size() != 0) {
        std::cout << "Memory bad resource" << std::endl;

        for (int i{ 0 }; i < this->action_organism.get_Result_Action().result_Check_Memory_Bad_Resource.size(); i++) {
            std::cout << "Slot: " << i << std::endl;

            for (int j{ 0 }; j < 4; j++) {
                std::cout << "Red: " << this->action_organism.get_Result_Action().result_Check_Memory_Bad_Resource[i]._r << " , ";
                std::cout << "Green: " << this->action_organism.get_Result_Action().result_Check_Memory_Bad_Resource[i]._g << " , ";
                std::cout << "Blue: " << this->action_organism.get_Result_Action().result_Check_Memory_Bad_Resource[i]._b << " , ";
                std::cout << "Value energi: " << this->action_organism.get_Result_Action().result_Check_Memory_Bad_Resource[i].value << std::endl;

            }

        }

    }
    else std::cout << "Not memory bad resource" << std::endl;

    
    std::cout << "Priority move: " << this->action_organism.get_Result_Action().result_Check_Priority_Move << std::endl;

    std::cout << "Priority convertation: " << this->action_organism.get_Result_Action().result_Check_Priority_Convertation << std::endl;
    
    std::cout << "---------------------------------------------------------------------------------------------------------------";
    std::cout << std::endl;
}