#include "Environment.h"
#include "Resource_Manager.h"
#include "Organism_Manager.h"
#include "Interface.h"
#include "Interface_Action.h"
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>


int sizeX{ 0 };
int sizeY{ 0 };
int count_resource{ 0 };
int count_organism{ 0 };

double size_c_x{ 0 };
double size_c_y{ 0 };

int main_counter{ 0 };


int copy_id{ -1 };


int main() {

	std::cin >> sizeX;
	std::cin >> sizeY;
	std::cin >> count_resource;
	std::cin >> count_organism;


	sf::RenderWindow window(sf::VideoMode(400, 400), "Simulation", sf::Style::None);

	Sm::Interface interface_program(window.getSize());

	Sm::Interface_Hover interface_hover;

	sf::Mouse mouse;


	size_c_x = window.getSize().x * 0.5 / sizeX;
	size_c_y = window.getSize().y * 0.9 / sizeY;

	sf::RectangleShape mask;
	mask.setSize(sf::Vector2f(size_c_x, size_c_y));
	
	Sm::Environment environment(sf::Vector2i(sizeX, sizeY));
	
	Sm::Resource_Manager resource_manager(count_resource, environment.get_Config_Zone_Manager().count_environment_zone, environment.get_Config_Zone_Manager().zones_information);
	environment.get_Config_Zone_Manager().zones_information = resource_manager.get_Config_Zone_Manager().zones_information;
	Sm::Organism_Manager organism_manager(count_organism, environment.get_Config_Zone_Manager().count_environment_zone, environment.get_Config_Zone_Manager().zones_information);
	environment.get_Config_Zone_Manager().zones_information = organism_manager.get_Config_Zone_Manager().zones_information;
	resource_manager.get_Config_Zone_Manager().zones_information = environment.get_Config_Zone_Manager().zones_information;
	
	/// Simulation Loop
	window.setFramerateLimit(60);

	while (window.isOpen()) {
		sf::Event event;

		main_counter++;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed) {

				if (event.key.code == sf::Keyboard::Escape) {
					window.close();

				}

			}
			else if (event.type == sf::Event::MouseMoved) {
				interface_hover.check_Colision(interface_program, mouse, window);

			}
			else if (event.type == sf::Event::MouseButtonPressed) {
				sf::Vector2f position_mouse(mouse.getPosition(window));
				interface_hover.check_Activate(interface_program, mouse, window);


				if (interface_program.get_Interface_Elements().button_select.get_Status()) {
					if (position_mouse.x <= window.getSize().x * 0.5 && position_mouse.y <= window.getSize().y * 0.9) {
						sf::Vector2i select_id(position_mouse.x / size_c_x, position_mouse.y / size_c_y);
						
						int id = organism_manager.get_Organism_On_Id(select_id);

						if (id != organism_manager.get_Organisms_Information().size()) {
							interface_program.get_Interface_Elements().label_count_serial_number.set_Text(std::to_string(organism_manager.get_Organisms_Information()[id].get_Config_Organism().serial_number[0]));
							interface_program.get_Interface_Elements().label_count_energi_status.set_Text(std::to_string(organism_manager.get_Organisms_Information()[id].get_Config_Organism().energi));

						}
						else {
							interface_program.get_Interface_Elements().label_count_serial_number.set_Text("--");
							interface_program.get_Interface_Elements().label_count_energi_status.set_Text("--");

						}
					}

				}
				else if (interface_program.get_Interface_Elements().button_creeate.get_Status()) {
					if (position_mouse.x <= window.getSize().x * 0.5 && position_mouse.y <= window.getSize().y * 0.9) {
						sf::Vector2i select_id(position_mouse.x / size_c_x, position_mouse.y / size_c_y);


						if (copy_id != -1 && environment.get_Config_Zone_Manager().zones_information[select_id.y][select_id.x] == 0) {

							organism_manager.add_Copy_Organism(copy_id, select_id);

							environment.get_Config_Zone_Manager().zones_information = organism_manager.get_Config_Zone_Manager().zones_information;
							resource_manager.get_Config_Zone_Manager().zones_information = environment.get_Config_Zone_Manager().zones_information;

						};
						

					}

				}
				else if(interface_program.get_Interface_Elements().button_copy.get_Status()){
					if (position_mouse.x <= window.getSize().x * 0.5 && position_mouse.y <= window.getSize().y * 0.9) {
						sf::Vector2i select_id(position_mouse.x / size_c_x, position_mouse.y / size_c_y);

						int id = organism_manager.get_Organism_On_Id(select_id);

						if (id != organism_manager.get_Organisms_Information().size()) copy_id = id;
						else copy_id = -1;

					}

				}
				else if (interface_program.get_Interface_Elements().button_remove.get_Status()) {
					if (position_mouse.x <= window.getSize().x * 0.5 && position_mouse.y <= window.getSize().y * 0.9) {
						sf::Vector2i select_id(position_mouse.x / size_c_x, position_mouse.y / size_c_y);

						int id = organism_manager.get_Organism_On_Id(select_id);

						if (id != organism_manager.get_Organisms_Information().size()) {
							organism_manager.remove_Select_Organism(id);

							environment.get_Config_Zone_Manager().zones_information = organism_manager.get_Config_Zone_Manager().zones_information;
							resource_manager.get_Config_Zone_Manager().zones_information = environment.get_Config_Zone_Manager().zones_information;

						}

					}

				}

			}

		}


		if (main_counter % 120 == 0) {
			
			resource_manager.add_New_Resource();

			environment.get_Config_Zone_Manager().zones_information = resource_manager.get_Config_Zone_Manager().zones_information;
			organism_manager.get_Config_Zone_Manager().zones_information = environment.get_Config_Zone_Manager().zones_information;

		}

		if (main_counter % 10 == 0) {
			std::vector<Sm::Organism> copyter(organism_manager.get_Organisms_Information().size());
			copyter = organism_manager.get_Organisms_Information();

			for (int i{ 0 }; i < copyter.size(); i++) {

				organism_manager.call_Action_Organism_1_Sloy(copyter[i]);

				organism_manager.call_Action_Organism_2_Sloy(copyter[i]);

				organism_manager.call_Action_Organism(copyter[i]);

				environment.get_Config_Zone_Manager().zones_information = organism_manager.get_Config_Zone_Manager().zones_information;
				resource_manager.get_Config_Zone_Manager().zones_information = environment.get_Config_Zone_Manager().zones_information;


			}

		}

		window.clear();

		for (int i{ 0 }; i < environment.get_Config_Zone_Manager().count_environment_zone.y; i++) {
			for (int j{ 0 }; j < environment.get_Config_Zone_Manager().count_environment_zone.x; j++) {

				if (environment.get_Config_Zone_Manager().zones_information[i][j] == 0) {
					mask.setPosition(sf::Vector2f(j * size_c_x, i * size_c_y));
					mask.setFillColor(sf::Color::Color(40, 40, 40, 255));
				}
				else if (environment.get_Config_Zone_Manager().zones_information[i][j] == 1) {

					int id = organism_manager.get_Organism_On_Id(sf::Vector2i(j, i));

					mask.setPosition(sf::Vector2f(j * size_c_x, i * size_c_y));
					mask.setFillColor(sf::Color::Color(organism_manager.get_Organisms_Information()[id].get_Color_Zone()._r,
						organism_manager.get_Organisms_Information()[id].get_Color_Zone()._g,
						organism_manager.get_Organisms_Information()[id].get_Color_Zone()._b,
						organism_manager.get_Organisms_Information()[id].get_Color_Zone()._a));

				}
				else if (environment.get_Config_Zone_Manager().zones_information[i][j] == 2) {

					int id = resource_manager.get_Resource_On_Id(sf::Vector2i(j, i));

					mask.setPosition(sf::Vector2f(j * size_c_x, i * size_c_y));
					mask.setFillColor(sf::Color::Color(resource_manager.get_Resources_Information()[id].get_Color_Zone()._r,
						resource_manager.get_Resources_Information()[id].get_Color_Zone()._g,
						resource_manager.get_Resources_Information()[id].get_Color_Zone()._b,
						resource_manager.get_Resources_Information()[id].get_Color_Zone()._a));

				}

				window.draw(mask);

			}

		}


		interface_program.get_Interface_Elements().label_count_resource.set_Text(std::to_string(resource_manager.get_Resources_Information().size()));
		interface_program.get_Interface_Elements().label_count_organism.set_Text(std::to_string(organism_manager.get_Organisms_Information().size()));

		interface_program.draw_Interface_On_Screen(window);

		
		window.display();

		if (main_counter == 180) main_counter = 0;
	}
	
	return 0;

}