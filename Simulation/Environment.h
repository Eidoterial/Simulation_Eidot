#pragma once
#include <SFML/Graphics.hpp>
#include "Resource.h"
#include "Organism.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


namespace Sm {

	struct Environment_elements_status {

		// 0 - void zone
		// 1 - organism zone
		// 2 - resource zone
		int element_status = 0;
	};

	struct Environment_config {

		// Lenght x; Lenght y;
		sf::Vector2i size_environment;

		// Period spawn resource
		int period_spawn_resource;
		
		// 0 - Summer
		// 1 - Outem
		// 2 - Winter
		// 3 - Spring
		int season_environment;

		// 0 - Night
		// 1 - Day
		int time_environment;

		// Temperature in Celsius
		int temperature_environment;

		unsigned int resources_count = 0;
		unsigned int organisms_count = 0;

	};

	class Environment {
		Sm::Environment_config environment_config;

		Sm::Environment_elements_status** environment_elements_status;

		Sm::Resource* resources;
		Sm::Organism* organisms;

	public:

		// Size environment
		// Start resourse count
		// start organism count
		Environment(sf::Vector2i, unsigned int, unsigned int); // Constructor


		// Setter
		void set_Season(int);
		void set_Time(int);
		void set_Temperature(int);


		// Getter
		sf::Vector2i get_Size();
		int get_Season();
		int get_Time();
		int get_temperature();
		Sm::Environment_elements_status** get_Environment_Elements_Status();
		Sm::Resource* get_Resources();
		Sm::Environment_config& get_Environment_Config();


		// Function
		void set_Resource(int);
		void add_Resource();

		void set_Organism(int);
		void add_Organism();
	};

}