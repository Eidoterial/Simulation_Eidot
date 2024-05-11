#include "Environment.h"
#include "Resource_Manager.h"
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>



int main() {

	sf::RectangleShape mask;

	Sm::Environment environment(sf::Vector2i(10, 10));
	Sm::Resource_Manager resource_manager(10, environment.get_Config().count_environment_zone, environment.get_Zones_Information());

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


		if (frame == 20) {
			int ran_id{ 0 };

			resource_manager.add_New_Resource();
			resource_manager.add_New_Resource();
			resource_manager.add_New_Resource();


			std::srand(std::time(NULL));

			
			ran_id = rand() % resource_manager.get_Resources_Information().size();
			resource_manager.remove_Select_Resource(ran_id);
			ran_id = rand() % resource_manager.get_Resources_Information().size();
			resource_manager.remove_Select_Resource(ran_id);
			ran_id = rand() % resource_manager.get_Resources_Information().size();
			resource_manager.remove_Select_Resource(ran_id);
			
			frame = 0;
			environment.get_Zones_Information() = resource_manager.get_Zones_Information();

		}
		else frame++;


		window.clear();

		int resours_counter{ 0 };

		for (int i{ 0 }; i < environment.get_Config().count_environment_zone.y; i++) {
			for (int j{ 0 }; j < environment.get_Config().count_environment_zone.x; j++) {
				
				if (environment.get_Zones_Information()[i][j] == 0) {
					mask.setSize(sf::Vector2f(10, 10));
					mask.setPosition(sf::Vector2f(j * 10, i * 10));
					mask.setFillColor(sf::Color::Color(40, 40, 40, 255));
				}
				else if (environment.get_Zones_Information()[i][j] == 2) {

					mask.setSize(sf::Vector2f(resource_manager.get_Resources_Information()[resours_counter].get_Config_Zone().size));
					mask.setPosition(sf::Vector2f(j * resource_manager.get_Resources_Information()[resours_counter].get_Config_Zone().size.x, i * resource_manager.get_Resources_Information()[resours_counter].get_Config_Zone().size.y));
					mask.setFillColor(sf::Color::Color(60, 100, 60, 255));
					resours_counter++;
				}

				window.draw(mask);

			}

		}

		window.display();

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