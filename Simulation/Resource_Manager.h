#pragma once
#include "Resource.h"
#include <vector>

namespace Sm {

	class Resource_Manager {

		/// Save information about resources environment
		std::vector<Sm::Resource> resources_information;

		/// Save information about zones environment -- Source Environment.h
		std::vector < std::vector<int> > zones_information;

		/// axisX; axisY -- Source Environment.h
		sf::Vector2i count_environment_zone;

	public:

		/// Main constructor
		///
		/// Take 3 argument
		/// Start count resource
		/// Count zone in environment
		/// Environment zones_information
		Resource_Manager(unsigned int, sf::Vector2i, std::vector < std::vector<int> >);

		/// Return information about all resources in environment
		std::vector<Sm::Resource>& get_Resources_Information();

		/// Set configuration resource
		///
		/// Take 1 argument
		/// Id resource
		void set_Resource_Config(int);

		/// Addition new resource in environment
		void add_New_Resource();

		/// Remove select resource in environment
		///
		/// Take 1 argument
		/// Id resource
		void remove_Select_Resource(int);

		/// Return Information about all zone in environment 
		std::vector < std::vector<int> > get_Zones_Information();
		
		/// Return index resource
		///
		/// Take 1 argument
		/// Id resource in environment
		int get_Resource_On_Id(sf::Vector2i);

	};


}

