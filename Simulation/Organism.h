#pragma once
#include <SFML/Graphics.hpp>
#include "Config_Environment_Zone.h"
#include "Genom.h"
#include "Memory_Organism.h"



namespace Sm {


	struct Config_Organism {

		/// Save energi organism
		int energi{ 0 };

		/// Save serial number organism
		std::vector<int> serial_number;

	};


	class Organism : public Sm::Config_Environment_Zone, public Sm::Genom {
		/// Save main configuration organism
		Sm::Config_Organism config_organism;

	public:

		/// Main constructor
		Organism();

		/// Return configuration organism
		Sm::Config_Organism& get_Config_Organism();

	};

}