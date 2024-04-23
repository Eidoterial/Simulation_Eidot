#include <iostream>
#include "Environment.h"


int main() {

	sf::RectangleShape maket;

	sf::RenderWindow window(sf::VideoMode(300, 300), "Simulation", sf::Style::Default);

	Sm::Environment environment(sf::Vector2i(10, 10), 1);


	environment.get_Environment_Zone_Status()[1][1].zone_stats = 1;
	environment.get_Environment_Zone_Status()[3][3].zone_stats = 1;
	environment.get_Environment_Zone_Status()[5][4].zone_stats = 1;
	environment.get_Environment_Zone_Status()[3][5].zone_stats = 1;
	environment.get_Environment_Zone_Status()[2][6].zone_stats = 2;
	environment.get_Environment_Zone_Status()[1][7].zone_stats = 1;
	environment.get_Environment_Zone_Status()[1][8].zone_stats = 1;
	environment.get_Environment_Zone_Status()[6][1].zone_stats = 1;
	environment.get_Environment_Zone_Status()[7][1].zone_stats = 1;
	environment.get_Environment_Zone_Status()[7][5].zone_stats = 2;
	environment.get_Environment_Zone_Status()[7][6].zone_stats = 1;
	environment.get_Environment_Zone_Status()[5][8].zone_stats = 1;
	environment.get_Environment_Zone_Status()[4][9].zone_stats = 1;
	environment.get_Environment_Zone_Status()[3][0].zone_stats = 2;
	environment.get_Environment_Zone_Status()[9][4].zone_stats = 1;
	environment.get_Environment_Zone_Status()[8][3].zone_stats = 1;
	environment.get_Environment_Zone_Status()[7][2].zone_stats = 1;
	environment.get_Environment_Zone_Status()[7][9].zone_stats = 2;
	environment.get_Environment_Zone_Status()[6][0].zone_stats = 1;
	environment.get_Environment_Zone_Status()[2][0].zone_stats = 1;
	environment.get_Environment_Zone_Status()[2][5].zone_stats = 2;
	environment.get_Environment_Zone_Status()[2][4].zone_stats = 2;
	environment.get_Environment_Zone_Status()[3][7].zone_stats = 1;
	environment.get_Environment_Zone_Status()[3][2].zone_stats = 1;
	environment.get_Environment_Zone_Status()[9][0].zone_stats = 1;
	environment.get_Environment_Zone_Status()[4][6].zone_stats = 2;
	environment.get_Environment_Zone_Status()[4][5].zone_stats = 1;


	for (int i{ 0 }; i < environment.get_Size().y; i++) {
		for (int j{ 0 }; j < environment.get_Size().x; j++) {
			std::cout << i << ": " << environment.get_Environment_Zone_Status()[i][j].zone_stats << std::endl;
		}
	}


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

		for (int i{ 0 }; i < environment.get_Size().y; i++) {
			for (int j{ 0 }; j < environment.get_Size().x; j++) {
				maket.setPosition(sf::Vector2f(i * 15, j * 15));
				maket.setSize(sf::Vector2f(15, 15));
				if (environment.get_Environment_Zone_Status()[i][j].zone_stats == 0) {
					maket.setFillColor(sf::Color::Color(10, 10, 10, 255));
				}
				else if (environment.get_Environment_Zone_Status()[i][j].zone_stats == 1) {
					maket.setFillColor(sf::Color::Color(10, 100, 10, 255));
				}
				else if (environment.get_Environment_Zone_Status()[i][j].zone_stats == 2) {


					maket.setFillColor(sf::Color::Color(100, 100, 10, 255));
				}
				window.draw(maket);
			}
		}

		window.display();
	}


	return 0;
}