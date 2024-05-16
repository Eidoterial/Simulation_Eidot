#pragma once
#include <vector>


namespace Sm {

	
	struct Memory_Target {
		/// Red color 
		unsigned int _r{ 0 };

		/// Green color 
		unsigned int _g{ 0 };

		/// Blue color 
		unsigned int _b{ 0 };

		/// Value energi
		int value{ 0 };

	};

	class Memory_Status {

		/// Save color good element
		std::vector<Sm::Memory_Target> good;

		/// Save color bad element
		std::vector<Sm::Memory_Target> bad;
	
	public:

		/// Main constructor
		Memory_Status();

		/// Return color good organism
		std::vector<Sm::Memory_Target>& get_Good();

		/// Return color bad organism
		std::vector<Sm::Memory_Target>& get_Bad();

	};

}