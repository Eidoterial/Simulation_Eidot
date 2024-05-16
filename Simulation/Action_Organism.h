#pragma once
#include <SFML/Graphics.hpp>
#include "Organism.h"
#include "Resource.h"
#include <vector>

namespace Sm {

	struct Arround_Element_Info {

		/// Type element
		int type{ 0 };

		/// Position element
		sf::Vector2i position;

	};


	struct Result_Action {

		/// Save result check arround
		std::vector<Arround_Element_Info> result_Check_Arround;

		/// Save result check status
		double result_Check_Energi_Status{ 0 };

		/// Save result check memory
		std::vector<double> result_Check_Memory;

	};

	class Action_Organism {

		/// Save all result action organism
		Sm::Result_Action result_action;

	public:

		/// Main constructor
		Action_Organism();

		/// Return results action
		Sm::Result_Action get_Result_Action();

		/// Check element environment arround organism
		///
		/// Take 3 argument
		/// Organism
		/// Count zone in environment
		/// Environment zones_information
		void check_Arround(Sm::Organism, sf::Vector2i, std::vector < std::vector<int> >);

		/// Check energi status organism
		///
		/// Take 1 argument
		/// Organism
		void check_Energi_Status(Sm::Organism);

		/// Check memory organism
		///
		/// Take 3 argument
		/// Organism
		/// All organisms
		/// All resources
		void check_Memory(Sm::Organism, std::vector<Sm::Organism>, std::vector<Sm::Resource>);

	};

}