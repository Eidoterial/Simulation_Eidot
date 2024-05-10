#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

namespace Sm {


	struct Environment_config {
		/// axisX; axisY
		sf::Vector2i count_environment_zone;

		/// Period spawn resource
		int period_spawn_resource{ 0 };

		/// Save count all resources in environment
		unsigned int resources_count{ 0 };

		/// Save count all organisms in environment
		unsigned int organisms_count{ 0 };

	};

	class Environment {
		/// Save main configuration environment 
		Sm::Environment_config config;

		/// Save information about zones environment
		/// 0 - void
		/// 1 - organism
		/// 2 - resource
		std::vector < std::vector<int> > zones_information;

	public:

		/// Main constructor ennvironment
		///
		/// Take 1 argument
		/// Count environment zone axisX and axisY
		Environment(sf::Vector2i); // Constructor

		
		/// Getter

		/// Return Information about all zone in environment
		std::vector < std::vector<int> >& get_Zones_Information();

		/// Return main configuration environment
		Sm::Environment_config& get_Config();
		
	};

}