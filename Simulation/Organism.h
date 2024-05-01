#pragma once
#include "Element_Environment.h"



namespace Sm {


	class Organism : public Sm::Element_Environment {

		int age_organism;

		int generation_organism;

		int temperature_organism;

	public:

		Organism(); // Constructor


		// Setter
		void set_Age_Organism(int);
		void set_Generation_Organism(int);
		void set_Temperature_Organism(int);


		// Getter
		int get_Age_Organism();
		int get_Generation_Organism();
		int get_Temperature_Organism();

	};

}