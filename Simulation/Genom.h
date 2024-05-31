#pragma once
#include "Gen.h"


namespace Sm {

	struct De_gen {

		double de_gen_0{ 0.0 };

		double de_gen_1{ 0.0 };

		std::vector<int> de_gen_3;

		bool de_gen_4{ false };

		bool de_gen_6{ false };

		int de_gen_7{ false };

		bool de_gen_8{ false };

	};


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

		Sm::De_gen de_gen;

	public:

		/// Main constructor
		Genom();

		/// Return de_gen
		Sm::De_gen& get_De_Gen();

		/// Return genom organism
		std::vector<Sm::Gen>& get_Genom();

		/// Decipherment 0 - gen
		void gen_0_Decipherment();

		/// Decipherment 1 - gen
		void gen_1_Decipherment();

		/// Decipherment 3 - gen
		void gen_3_Decipherment();

		/// Decipherment 4 - gen
		void gen_4_Decipherment();

		/// Deciphrement 6 - gen
		void gen_6_Decipherment();

		/// Decipherment 7 - gen
		void gen_7_Decipherment();

		/// Decipherment 8 - gen
		void gen_8_Decipherment();
		
		
	};

}