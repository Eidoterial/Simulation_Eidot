#pragma once
#include <SFML/Graphics.hpp>
#include "Element_Environment.h"

namespace Sm {

	

	class Resource : public Sm::Element_Environment {

		// 0 - Default resource
		// 1 - Super resource
		// 2 - Destruct resource
		int type_resource;

		int energi_recover_resource;

	public:

		Resource(); // Constructor

		// Setter
		void set_Type_Resource(int);
		void set_Energi_Recover_Resource(int);

		// Getter
		int get_Type_Resource();
		int get_Energi_Recover_Resource();
	};

}