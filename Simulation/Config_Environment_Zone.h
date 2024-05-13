#pragma once
#include <SFML/Graphics.hpp>


namespace Sm {

	struct Color_Zone {
		/// Red color
		unsigned int _r{ 0 };

		/// Green color
		unsigned int _g{ 0 };

		/// Blue color
		unsigned int _b{ 0 };

		/// Alpha
		unsigned int _a{ 0 };

	};


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

		/// Color struct zone
		Color_Zone color_zone;
		
	public:

		/// Main constructor
		Config_Environment_Zone();

		/// Return main configuration zone
		Sm::Config_Zone& get_Config_Zone();

		/// Return color zone
		Sm::Color_Zone& get_Color_Zone();

	};

}