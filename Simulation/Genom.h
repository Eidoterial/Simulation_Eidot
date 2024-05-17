#pragma once
#include "Gen.h"


namespace Sm {


	class Genom {

		/// Save genom organism
		///
		/// 0 - Minimum status energi
		/// 1 - Maximum status energi
		/// 2 - Ñolor corecter status
		/// 3 - Memory correcter status
		/// 4 - Posibility move
		/// 5 - Posibility absorption
		/// 6 - Posibility reproduction
		/// 7 - Count energi for reproduction
		/// 8 - Posibility for convertation
		/// 9 - Posibility aggression
		std::vector<Sm::Gen> genom;

	public:

		/// Main constructor
		Genom();

		/// Return genom organism
		std::vector<Sm::Gen>& get_Genom();

		/// Decipherment 0 - gen
		double gen_0_Decipherment();

		/// Decipherment 1 - gen
		double gen_1_Decipherment();

		/// Decipherment 3 - gen
		std::vector<int> gen_3_Decipherment();

		/// Decipherment 4 - gen
		bool gen_4_Decipherment();

		/// Deciphrement 6 - gen
		bool gen_6_Decipherment();

		/// Decipherment 7 - gen
		int gen_7_Decipherment();

		/// Decipherment 8 - gen
		bool gen_8_Decipherment();
		
		
	};

}