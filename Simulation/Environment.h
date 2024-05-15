#pragma once
#include <SFML/Graphics.hpp>
#include "Zone_Manager.h"

namespace Sm {


	struct Environment_config {

		/// Period spawn resource
		int period_spawn_resource{ 0 };

	};

	class Environment : public Sm::Zone_Manager {
		/// Save main configuration environment 
		Sm::Environment_config config;

	public:

		/// Main constructor ennvironment
		///
		/// Take 1 argument
		/// Count environment zone axisX and axisY
		Environment(sf::Vector2i); // Constructor

		/// Return main configuration environment
		Sm::Environment_config& get_Config();
		
	};

}