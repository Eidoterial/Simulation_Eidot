#include "Environment.h"
#include "Resource_Manager.h"
#include "Organism_Manager.h"
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>



int main() {

	sf::RectangleShape mask;


	Sm::Environment environment(sf::Vector2i(10, 10));


	Sm::Resource_Manager resource_manager(10, environment.get_Config_Zone_Manager().count_environment_zone, environment.get_Config_Zone_Manager().zones_information);
	environment.get_Config_Zone_Manager().zones_information = resource_manager.get_Config_Zone_Manager().zones_information;
	Sm::Organism_Manager organism_manager(5, environment.get_Config_Zone_Manager().count_environment_zone, environment.get_Config_Zone_Manager().zones_information);
	environment.get_Config_Zone_Manager().zones_information = organism_manager.get_Config_Zone_Manager().zones_information;
	
	/// Simulation Loop
	
	sf::RenderWindow window(sf::VideoMode(400, 400), "Simulation", sf::Style::Default);
	window.setFramerateLimit(60);

	
	

	int frame{ 0 };

	while (window.isOpen()) {
		sf::Event event;


		while (window.pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed) {

				if (event.key.code == sf::Keyboard::Escape) {
					window.close();

				}

			}

		}


		window.clear();


		for (int i{ 0 }; i < environment.get_Config_Zone_Manager().count_environment_zone.y; i++) {
			for (int j{ 0 }; j < environment.get_Config_Zone_Manager().count_environment_zone.x; j++) {
				
				if (environment.get_Config_Zone_Manager().zones_information[i][j] == 0) {
					mask.setSize(sf::Vector2f(10, 10));
					mask.setPosition(sf::Vector2f(j * 10, i * 10));
					mask.setFillColor(sf::Color::Color(40, 40, 40, 255));
				}
				else if (environment.get_Config_Zone_Manager().zones_information[i][j] == 1) {

					int id = organism_manager.get_Organism_On_Id(sf::Vector2i(j, i));

					std::cout << "ID organism: " << id << std::endl;
					organism_manager.call_Action_Organism_1_Sloy(id);
					organism_manager.call_Action_Organism_2_Sloy(id);

					organism_manager.info_action();

					mask.setSize(sf::Vector2f(organism_manager.get_Organisms_Information()[id].get_Config_Zone().size));
					mask.setPosition(sf::Vector2f(j * organism_manager.get_Organisms_Information()[id].get_Config_Zone().size.x, i * organism_manager.get_Organisms_Information()[id].get_Config_Zone().size.y));
					mask.setFillColor(sf::Color::Color(organism_manager.get_Organisms_Information()[id].get_Color_Zone()._r,
						organism_manager.get_Organisms_Information()[id].get_Color_Zone()._g,
						organism_manager.get_Organisms_Information()[id].get_Color_Zone()._b,
						organism_manager.get_Organisms_Information()[id].get_Color_Zone()._a));

				}
				else if (environment.get_Config_Zone_Manager().zones_information[i][j] == 2) {

					int id = resource_manager.get_Resource_On_Id(sf::Vector2i(j, i));

					mask.setSize(sf::Vector2f(resource_manager.get_Resources_Information()[id].get_Config_Zone().size));
					mask.setPosition(sf::Vector2f(j * resource_manager.get_Resources_Information()[id].get_Config_Zone().size.x, i * resource_manager.get_Resources_Information()[id].get_Config_Zone().size.y));
					mask.setFillColor(sf::Color::Color(resource_manager.get_Resources_Information()[id].get_Color_Zone()._r,
													   resource_manager.get_Resources_Information()[id].get_Color_Zone()._g,
													   resource_manager.get_Resources_Information()[id].get_Color_Zone()._b,
													   resource_manager.get_Resources_Information()[id].get_Color_Zone()._a));

				}

				window.draw(mask);

			}

		}

		window.display();

		break;
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


	return 0;

}