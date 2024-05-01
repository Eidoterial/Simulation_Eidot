#pragma once
#include <SFML/Graphics.hpp>


namespace Sm {

	class Element_Environment {

		sf::Vector2i position;

		// 0 - Void
		// 1 - Organism
		// 2 - Resource
		// 3 - Die organism
		int type{};

	public:

		Element_Environment(); // Constructor


		// Setter
		void set_Position(sf::Vector2i);
		void set_Type(int);


		// Getter
		sf::Vector2i get_Position();
		int get_Type();
	};

}