#pragma once
#include "Resource.h"
#include "Zone_Manager.h"

namespace Sm {

	class Resource_Manager : public Sm::Zone_Manager {

		/// Save information about resources environment
		std::vector<Sm::Resource> resources_information;

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
		
		/// Return index resource
		///
		/// Take 1 argument
		/// Id resource in environment
		int get_Resource_On_Id(sf::Vector2i);

	};


}

