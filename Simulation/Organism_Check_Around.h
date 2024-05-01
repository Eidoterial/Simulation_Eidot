#pragma once
#include "Environment.h"


namespace Sm {


	struct Element_Around {

		int type_element;
		sf::Vector2i position_element;

	};

	
	class Check_Around {

		Sm::Element_Around element_around[3][3];

	public:

		Check_Around(); // Constructor

		void Check_Around_Organism(Sm::Organism, Sm::Environment);
	};
	 

}