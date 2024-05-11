#pragma once
#include <SFML/Graphics.hpp>


namespace Sm {

	struct Config_Zone {
		/// Position zone on screen axisX and axisY
		sf::Vector2f position;

		/// Size zone on screen axisX and axisY
		sf::Vector2f size = sf::Vector2f(10, 10);

		/// Id zone on environment axisX and axisY
		sf::Vector2i id_E;

	};

	class Config_Environment_Zone {
		/// Save main configuration zone
		Sm::Config_Zone config_zone;
		
	public:

		/// Main constructor
		Config_Environment_Zone();

		/// Return main configuration zone
		Sm::Config_Zone& get_Config_Zone();

	};

}