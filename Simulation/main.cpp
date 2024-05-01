#include <iostream>
#include "Environment.h"




int main() {
	int frame_indecator{ 0 };

	sf::RectangleShape maket;

	sf::RenderWindow window(sf::VideoMode(300, 300), "Simulation", sf::Style::Default);
	window.setFramerateLimit(60);

	Sm::Environment environment(sf::Vector2i(50, 50), 50, 50);

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
			environment.add_Resource();
			environment.add_Organism();
			frame_indecator = 0;
		}
		else frame_indecator++;

		for (int i{ 0 }; i < environment.get_Size().y; i++) {
			for (int j{ 0 }; j < environment.get_Size().x; j++) {
				maket.setPosition(sf::Vector2f(i * 3, j * 3));
				maket.setSize(sf::Vector2f(1, 1));
				if (environment.get_Environment_Elements_Status()[i][j].element_status == 0) {
					maket.setFillColor(sf::Color::Color(20, 20, 20, 255));
				}
				else if (environment.get_Environment_Elements_Status()[i][j].element_status == 1) {
					maket.setFillColor(sf::Color::Color(20, 200, 20, 255));
				}
				else if (environment.get_Environment_Elements_Status()[i][j].element_status == 2) {
					maket.setFillColor(sf::Color::Color(200, 200, 20, 255));
				}
				window.draw(maket);
			}
		}

		window.display();

	}


	return 0;
}