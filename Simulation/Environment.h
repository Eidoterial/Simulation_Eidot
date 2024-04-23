#pragma once
#include <SFML/Graphics.hpp>
#include "Resource.h"


namespace Sm {

	

	struct Zone_status {

		// 0 - void zone
		// 1 - organism zone
		// 2 - resource zone
		int zone_stats = 0;
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

	};

	class Environment {
		Sm::Environment_config environment_config;

		Sm::Zone_status** environment_zone_status;
		int resources_count = 0;
		Sm::Resource* resources[1];
		//Organism

	public:

		// Size environment
		// Start resourse count
		//
		//
		Environment(sf::Vector2i, int); // Constructor


		// Setter
		void set_Period_Spawn_Resource(int);
		void set_Season(int);
		void set_Time(int);
		void set_Temperature(int);


		// Getter
		sf::Vector2i get_Size();
		int get_Season();
		int get_Time();
		int get_temperature();
		Sm::Zone_status** get_Environment_Zone_Status();

		// Function

		// Count spawn resource
		void Spawn_Resource(int);
		void Add_Elements_Array(Sm::Resource*&, int);
	};

}