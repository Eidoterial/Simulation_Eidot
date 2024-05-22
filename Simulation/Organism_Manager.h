#pragma once
#include "Action_Organism.h"
#include "Organism.h"
#include "Zone_Manager.h"


namespace Sm {


	class Organism_Manager : public Sm::Zone_Manager {

		/// Save information about organisms environment
		std::vector<Sm::Organism> organisms_information;

		/// Save counter serial number
		int counter_serial_number{ 0 };

		/// Action current organism
		Sm::Action_Organism action_organism;

	public:

		/// Main constructor
		///
		/// Take 3 argument
		/// Start count resource
		/// Count zone in environment
		/// Environment zones_information
		Organism_Manager(unsigned int, sf::Vector2i, std::vector < std::vector<int> >);

		/// Return information about all organisms in environment
		std::vector<Sm::Organism>& get_Organisms_Information();

		/// Set configuration organism
		///
		/// Take 1 argument
		/// Id organism
		void set_Organism_Config(int);

		/// Addition new organism in environment
		void add_New_Organism();

		/// Remove select organism in environment
		///
		/// Take 1 argument
		/// Id organism
		void remove_Select_Organism(int);

		/// Return index organism
		///
		/// Take 1 argument
		/// Id organism in environment
		int get_Organism_On_Id(sf::Vector2i);

		/// Call action organism 1 sloy
		///
		/// Take 1 argument
		/// Id organism
		void call_Action_Organism_1_Sloy(int);

		/// Call action organism 2 sloy
		///
		/// Take 1 argument
		/// Id organism
		void call_Action_Organism_2_Sloy(int);

		/// Information 
		void info_action();

	};

}
