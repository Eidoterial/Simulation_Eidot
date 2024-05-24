#pragma once
#include "Interface.h"
#include <vector>


namespace Sm {

	class Interface_Hover {


	public:

		/// Main constructor
		Interface_Hover();

		/// Check colision element interface
		///
		/// Take 3 argument
		/// All interface program
		/// Information about mouse
		/// Main screen
		void check_Colision(Sm::Interface&, sf::Mouse&, sf::RenderWindow&);

		/// Check colider element interface
		///
		/// Take 3 argument
		/// Position element
		/// Size element
		/// Position mouse 
		bool check_Colider(sf::Vector2f, sf::Vector2f, sf::Vector2i);

		/// Check colision element interface
		///
		/// Take 3 argument
		/// All interface program
		/// Information about mouse
		/// Main screen
		int check_Activate(Sm::Interface&, sf::Mouse&, sf::RenderWindow&);


	};


}
