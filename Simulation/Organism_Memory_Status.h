#pragma once


namespace Sm {


	struct Memory_Target {
		/// Red color 
		unsigned int _r{ 0 };

		/// Green color 
		unsigned int _g{ 0 };

		/// Blue color 
		unsigned int _b{ 0 };

	};

	class Organism_Memory_Status {

		/// Save color good organism
		Memory_Target good_organism;

		/// Save color bad organism
		Memory_Target bad_organism;
	
	public:

		/// Main constructor
		Organism_Memory_Status();

		/// Return color good organism
		Sm::Memory_Target& get_Good_Organism();

		/// Return color bad organism
		Sm::Memory_Target& get_Bad_Organism();

	};

}