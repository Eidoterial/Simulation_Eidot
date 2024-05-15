#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

namespace Sm {

	struct Config_Zone_Manager {

		/// Save information about zones environment
		/// 0 - void
		/// 1 - organism
		/// 2 - resource
		std::vector < std::vector<int> > zones_information;

		/// axisX; axisY -- Source Environment.h
		sf::Vector2i count_environment_zone;

	};
	
	class Zone_Manager {
		/// Main configuration zone manager
		Sm::Config_Zone_Manager config_zone_manager;
	
	public:

		/// Main constructor
		Zone_Manager();

		/// Return configuration zone manager 
		Sm::Config_Zone_Manager& get_Config_Zone_Manager();

	};

}