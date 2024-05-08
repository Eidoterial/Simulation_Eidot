#pragma once
#include "Resource.h"

namespace Sm {

	class Resource_Manager {

		/// Save information about resources environment
		Sm::Resource* resources_information;

		/// Save information about zones environment -- Source Environment.h
		int** zones_information;

		/// axisX; axisY -- Source Environment.h
		sf::Vector2i count_environment_zone;

	public:

		/// Main constructor
		///
		/// Take 3 argument
		/// Start count resource
		/// Count zone in environment
		/// Environment zones_information
		Resource_Manager(unsigned int, sf::Vector2i, int**);

		/// Return information about all resources in environment
		Sm::Resource* get_Resources_Information();

		/// Set configuration resource
		///
		/// Take 1 argument
		/// Id resource
		void set_Resource_Config(int);

	};


}

