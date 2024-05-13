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

	class Resource_Memory_Status {

		/// Save color good organism
		Memory_Target good_resource;

		/// Save color bad organism
		Memory_Target bad_resource;

	public:

		/// Main constructor
		Resource_Memory_Status();

		/// Return color good organism
		Sm::Memory_Target& get_Good_Resource();

		/// Return color bad organism
		Sm::Memory_Target& get_Bad_Resource();

	};

}