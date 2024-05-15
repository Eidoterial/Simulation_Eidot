#pragma once
#include <vector>

namespace Sm {

	class Gen {

		/// Save gen organism
		std::vector<int> gen;

	public:

		/// Main constructor
		Gen();

		/// Return gen organism
		std::vector<int>& get_Gen();

	};

}