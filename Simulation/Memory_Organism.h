#pragma once
#include "Memory_Status.h"

namespace Sm {
	
	class Memory_Organism {
		/// Save status memory about organism
		Sm::Memory_Status memory_organisms;

		/// Save status memory about resource
		Sm::Memory_Status memory_resources;


	public:

		/// Main constructor
		Memory_Organism();

		/// Return memory about organisms
		Sm::Memory_Status& get_Memory_Organisms();

		/// Return memory about resources
		Sm::Memory_Status& get_Memory_Resources();

	};

}