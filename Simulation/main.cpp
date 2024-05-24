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

double size_c_x{ 0 };
double size_c_y{ 0 };

int main() {


	std::cin >> sizeX;
	std::cin >> sizeY;


	sf::RenderWindow window(sf::VideoMode(400, 400), "Simulation", sf::Style::None);
	window.setFramerateLimit(60);

	size_c_x = window.getSize().x * 0.5 / sizeX;
	size_c_y = window.getSize().y * 0.9 / sizeY;
	

	Sm::Interface interface_program(window.getSize());
	
	sf::RectangleShape mask;
	mask.setSize(sf::Vector2f(size_c_x, size_c_y));


	
	Sm::Interface_Hover interface_hover;

	sf::Mouse mouse;

	
	Sm::Environment environment(sf::Vector2i(sizeX, sizeY));
	
	Sm::Resource_Manager resource_manager(10, environment.get_Config_Zone_Manager().count_environment_zone, environment.get_Config_Zone_Manager().zones_information);
	environment.get_Config_Zone_Manager().zones_information = resource_manager.get_Config_Zone_Manager().zones_information;
	Sm::Organism_Manager organism_manager(10, environment.get_Config_Zone_Manager().count_environment_zone, environment.get_Config_Zone_Manager().zones_information);
	environment.get_Config_Zone_Manager().zones_information = organism_manager.get_Config_Zone_Manager().zones_information;
	
	/// Simulation Loop

	

	int frame{ 0 };

	while (window.isOpen()) {
		sf::Event event;

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
				int result = interface_hover.check_Activate(interface_program, mouse, window);

				if (result == 1) {


				}


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

					//std::cout << "ID organism: " << id << std::endl;
					//organism_manager.call_Action_Organism_1_Sloy(id);
					//organism_manager.call_Action_Organism_2_Sloy(id);

					//organism_manager.info_action();

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
		
		
		interface_program.draw_Interface_On_Screen(window);

		


		window.display();


		///break;
	}
	


	/// Parse tester
	
	/*
	for (int i{ 0 }; i < environment.get_Zones_Information().size(); i++) {
		for (int j{ 0 }; j < environment.get_Zones_Information()[0].size(); j++) {
			std::cout << environment.get_Zones_Information()[i][j];
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (int i{ 0 }; i < resource_manager.zones_information.size(); i++) {
		for (int j{ 0 }; j < resource_manager.zones_information[0].size(); j++) {
			std::cout << resource_manager.zones_information[i][j];
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	environment.get_Zones_Information() = resource_manager.zones_information;
			
	for (int i{ 0 }; i < environment.get_Zones_Information().size(); i++) {
		for (int j{ 0 }; j < environment.get_Zones_Information()[0].size(); j++) {
			std::cout << environment.get_Zones_Information()[i][j];
		}
		std::cout << std::endl;
	}
	*/

	sf::Text text;

	return 0;

}