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

		/// Sloy 1
		/// /////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////

		/// Save result check arround
		std::vector<Arround_Element_Info> result_Check_Arround;

		/// Save result check status
		double result_Check_Energi_Status{ 0.0 };

		/// Save result check memory
		std::vector<Sm::Memory_Target> result_Check_Memory_Good_Organism;
		std::vector<Sm::Memory_Target> result_Check_Memory_Bad_Organism;
		std::vector<Sm::Memory_Target> result_Check_Memory_Good_Resource;
		std::vector<Sm::Memory_Target> result_Check_Memory_Bad_Resource;

		/////////////////////////////////////////////////////////////
		/// /////////////////////////////////////////////////////////


		/// Sloy 2
		/// /////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////

		/// Save result check priority move
		double result_Check_Priority_Move{ 0.0 };

		/// Save result check priority convertation
		double result_Check_Priority_Convertation{ 0.0 };

		/// Save result check priority reproduction
		double result_Check_Priority_Reproduction{ 0.0 };

		/// Save result check priority absorption
		double  result_Check_Priority_Absorption{ 0.0 };
		
		/////////////////////////////////////////////////////////////
		/// /////////////////////////////////////////////////////////

	};

	class Action_Organism {

		/// Save all result action organism
		Sm::Result_Action result_action;

	public:

		/// Main constructor
		Action_Organism();

		/// Return results action
		Sm::Result_Action get_Result_Action();

		/// Sloy 1
		/// /////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////

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
		/// Take 1 argument
		/// Organism
		void check_Memory(Sm::Organism);

		/////////////////////////////////////////////////////////////
		/// /////////////////////////////////////////////////////////

		/// Sloy 2
		/// /////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////

		/// Check priority move organism
		///
		/// Take 1 argument
		/// Organism
		void check_Priority_Move(Sm::Organism);

		/// Check priority convertation organism
		///
		/// Take 1 argument
		/// Organism
		void check_Priority_Convertation(Sm::Organism);

		/// Check priority reproduction organism
		///
		/// Take 1 argument
		/// Organism
		void check_Priority_Reproduction(Sm::Organism);

		/// Check priority absorption organism
		///
		/// Take 1 argument
		/// Organism
		void check_Priority_Absorption(Sm::Organism);

		/////////////////////////////////////////////////////////////
		/// /////////////////////////////////////////////////////////
		

		/// Action
		/// /////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////

		/// Move organism
		///
		/// Take 1 argument
		/// Organism
		sf::Vector2i move_Organism(Sm::Organism);

		/// Energi convertation organism
		///
		/// Take 1 argument
		/// Organism
		int energi_Convertation_Organism(Sm::Organism);

		/// Reproduction organism
		///
		/// Take 1 argument
		/// Organism
		sf::Vector2i reproduction_Organism(Sm::Organism);

		/// Adsorption organism
		///
		/// Take 1 argument
		/// Organism
		sf::Vector2i Adsorption_Organism(Sm::Organism);

		/////////////////////////////////////////////////////////////
		/// /////////////////////////////////////////////////////////

	};

}