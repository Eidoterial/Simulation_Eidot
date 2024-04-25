#include <iostream>
#include "Environment.h"




int main() {
	int frame_indecator{ 0 };

	sf::RectangleShape maket;

	sf::RenderWindow window(sf::VideoMode(300, 300), "Simulation", sf::Style::Default);
	window.setFramerateLimit(60);

	Sm::Environment environment(sf::Vector2i(10, 10), 5);

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

		

		if (frame_indecator == 60) {
			for (int i{ 0 }; i < environment.get_Environment_Config().resources_count; i++) {
				std::cout << environment.get_Resources()[i].get_Position().x << std::endl;
			}
			std::cout << "" << std::endl;
			std::cout << "" << std::endl;
			std::cout << "" << std::endl;


			environment.add_Resource();
			frame_indecator = 0;
		}
		else frame_indecator++;

		for (int i{ 0 }; i < environment.get_Size().y; i++) {
			for (int j{ 0 }; j < environment.get_Size().x; j++) {
				maket.setPosition(sf::Vector2f(i * 15, j * 15));
				maket.setSize(sf::Vector2f(15, 15));
				if (environment.get_Environment_Elements_Status()[i][j].zone_stats == 0) {
					maket.setFillColor(sf::Color::Color(10, 10, 10, 255));
				}
				else if (environment.get_Environment_Elements_Status()[i][j].zone_stats == 1) {
					maket.setFillColor(sf::Color::Color(10, 100, 10, 255));
				}
				else if (environment.get_Environment_Elements_Status()[i][j].zone_stats == 2) {
					maket.setFillColor(sf::Color::Color(100, 100, 10, 255));
				}
				window.draw(maket);
			}
		}

		window.display();
	}


	return 0;
}