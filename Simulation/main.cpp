#include "Environment.h"
#include "Resource_Manager.h"
#include <iostream>




int main() {

	sf::RectangleShape mask;

	Sm::Environment environment(sf::Vector2i(10, 10));
	Sm::Resource_Manager resource_manager(30, environment.get_Config().count_environment_zone, environment.get_Zones_Information());

	/// Simulation Loop
	/*
	sf::RenderWindow window(sf::VideoMode(400, 400), "Simulation", sf::Style::Default);
	window.setFramerateLimit(60);


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

		for (int i{ 0 }; i < environment.get_Config().count_environment_zone.y; i++) {
			for (int j{ 0 }; j < environment.get_Config().count_environment_zone.x; j++) {
				
				if (environment.get_Zones_Information()[i][j] == 0) {
					mask.setSize(sf::Vector2f(10, 10));
					mask.setPosition(sf::Vector2f(j * 10, i * 10));
					mask.setFillColor(sf::Color::Color(40, 40, 40, 255));
				}
				else if (environment.get_Zones_Information()[i][j] == 2) {
					mask.setSize(sf::Vector2f(resource_manager.get_Resources_Information()->get_Config_Zone().size));
					mask.setPosition(sf::Vector2f(j * resource_manager.get_Resources_Information()->get_Config_Zone().size.x, i * resource_manager.get_Resources_Information()->get_Config_Zone().size.y));
					mask.setFillColor(sf::Color::Color(60, 100, 60, 255));
				}

				window.draw(mask);

			}
		}

		window.display();

	}
	*/


	
	/// Parse tester
	/*
	for (int i{ 0 }; i < environment.get_Config().count_environment_zone.y; i++) {
		for (int j{ 0 }; j < environment.get_Config().count_environment_zone.x; j++) {
			std::cout << i << "." << j << " -" << environment.get_Zones_Information()[i][j] << "- ";
		}
		std::cout << std::endl;
	}
	*/


	return 0;

}