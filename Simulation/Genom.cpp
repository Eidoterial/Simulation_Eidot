#include "Genom.h"
#include <cmath>

/// CONSTRUCTOR
/// /////////////////
Sm::Genom::Genom() {};
/// /////////////////

/// GET GENOM
/// //////////////////////////////////////////
std::vector<Sm::Gen>& Sm::Genom::get_Genom() {
	return this->genom;

}
/// //////////////////////////////////////////


/// GEN 0 DECIPHERMENT
/// ////////////////////////////////////
double Sm::Genom::gen_0_Decipherment() {
	double block_1{ 10 };
	double block_2{ 0 };
	double block_3{ 5 };
	double block_4{ 5 };
	double block_5{ 0 };
	double block_6{ 0 };

	if (this->genom[0].get_Gen()[0] == 1) block_1 += 4;
	if (this->genom[0].get_Gen()[1] == 1) block_1 += 2;
	if (this->genom[0].get_Gen()[2] == 1) block_1 += 1;

	if (this->genom[0].get_Gen()[3] == 0) block_2 = 2;
	else if (this->genom[0].get_Gen()[3] == 1) block_2 = 3;

	if (this->genom[0].get_Gen()[4] == 1) block_3 -= 2;
	if (this->genom[0].get_Gen()[5] == 1) block_3 -= 1;

	if (this->genom[0].get_Gen()[6] == 1) block_4 -= 2;
	if (this->genom[0].get_Gen()[7] == 1) block_4 -= 1;

	if (this->genom[0].get_Gen()[8] == 0) block_5 = 1;
	else if (this->genom[0].get_Gen()[8] == 1) block_5 = 5;

	if (this->genom[0].get_Gen()[9] == 0) block_6 = 2;
	else if (this->genom[0].get_Gen()[9] == 1) block_6 = 1;

	return std::round((((block_1 / block_2 + block_3 + block_4) / block_5) * block_6) * 10) / 10;

}
/// ////////////////////////////////////


/// GEN 1 DECIPHERMENT
/// ////////////////////////////////////
double Sm::Genom::gen_1_Decipherment() {
	double block_1{ 5 };
	double block_2{ 1 };
	double block_3{ 6 };
	double block_4{ 0 };
	double block_5{ 1 };

	if (this->genom[0].get_Gen()[0] == 1) block_1 -= 2;
	if (this->genom[0].get_Gen()[1] == 1) block_1 -= 1;

	if (this->genom[0].get_Gen()[2] == 1) block_2 += 4;
	if (this->genom[0].get_Gen()[3] == 1) block_2 += 2;
	if (this->genom[0].get_Gen()[4] == 1) block_2 += 1;

	if (this->genom[0].get_Gen()[5] == 1) block_3 += 2;
	if (this->genom[0].get_Gen()[6] == 1) block_3 += 1;


	if (this->genom[0].get_Gen()[7] == 0) block_4 = 2;
	else if (this->genom[0].get_Gen()[7] == 1) block_4 = 1;

	if (this->genom[0].get_Gen()[8] == 1) block_5 += 2;
	if (this->genom[0].get_Gen()[9] == 1) block_5 += 1;

	return std::round((block_1 * block_2 / block_3 * block_4 + block_5) * 10) / 10;

}
/// ////////////////////////////////////


/// GEN 3 DECIPHERMENT
/// //////////////////////////////////////////////
std::vector<int> Sm::Genom::gen_3_Decipherment() {
	std::vector<int> MCS(7);

	int lich{ 0 };

	int S_block_1{ 0 };
	int S_block_2{ 4 };
	int S_block_3{ 8 };

	int R_block_1{ 3 };
	int R_block_2{ 7 };
	int R_block_3{ 9 };

	for (int i{ S_block_1 }; i < S_block_1 + 3; i++) {
		if (this->genom[3].get_Gen()[i] != this->genom[3].get_Gen()[R_block_1]) MCS[lich] = 1;
		else MCS[lich] = 0;
		lich++;

	}

	for (int i{ S_block_2 }; i < S_block_2 + 3; i++) {
		if (this->genom[3].get_Gen()[i] != this->genom[3].get_Gen()[R_block_2]) MCS[lich] = 1;
		else MCS[lich] = 0;
		lich++;

	}

	for (int i{ S_block_3 }; i < S_block_3 + 1; i++) {
		if (this->genom[3].get_Gen()[i] != this->genom[3].get_Gen()[R_block_3]) MCS[lich] = 1;
		else MCS[lich] = 0;
		lich++;

	}

	return MCS;

}
/// //////////////////////////////////////////////


/// GEN 4 DECIPHERMENT
/// //////////////////////////////////
bool Sm::Genom::gen_4_Decipherment() {
	bool block_1{ false };
	bool block_2{ false };
	bool block_3{ false };
	bool block_4{ false };

	if (this->genom[4].get_Gen()[0] + this->genom[4].get_Gen()[1] == 2) block_1 = false;
	else block_1 = true;

	if (this->genom[4].get_Gen()[2] + this->genom[4].get_Gen()[3] + this->genom[4].get_Gen()[4] == 0) block_2 = false;
	else block_2 = true;

	if (this->genom[4].get_Gen()[5] + this->genom[4].get_Gen()[6] + this->genom[4].get_Gen()[7] == 0) block_3 = false;
	else block_3 = true;

	if (this->genom[4].get_Gen()[8] + this->genom[4].get_Gen()[9] == 0) block_4 = false;
	else block_4 = true;

	if ((block_1 && block_2 && block_3 && block_4) || (block_1 && block_2 && !block_3 && !block_4) ||
		(!block_1 && !block_2 && block_3 && block_4)) return true ;
	else return false;

}
/// //////////////////////////////////


/// GEN 6 DECIPHERMENT
/// //////////////////////////////////
bool Sm::Genom::gen_6_Decipherment() {
	bool block_1{ false };
	bool block_2{ false };
	bool block_3{ false };

	if (this->genom[6].get_Gen()[0] + this->genom[6].get_Gen()[1] + this->genom[6].get_Gen()[2] == 0) block_1 = false;
	else block_1 = true;

	if ((this->genom[6].get_Gen()[3] == 0 && this->genom[6].get_Gen()[4] == 0 && this->genom[6].get_Gen()[5] == 0 && this->genom[6].get_Gen()[4] == 0) ||
		(this->genom[6].get_Gen()[3] == 0 && this->genom[6].get_Gen()[4] == 0 && this->genom[6].get_Gen()[5] == 1 && this->genom[6].get_Gen()[4] == 0) ||
		(this->genom[6].get_Gen()[3] == 0 && this->genom[6].get_Gen()[4] == 0 && this->genom[6].get_Gen()[5] == 0 && this->genom[6].get_Gen()[4] == 1) ||
		(this->genom[6].get_Gen()[3] == 0 && this->genom[6].get_Gen()[4] == 1 && this->genom[6].get_Gen()[5] == 0 && this->genom[6].get_Gen()[4] == 0) ||
		(this->genom[6].get_Gen()[3] == 1 && this->genom[6].get_Gen()[4] == 0 && this->genom[6].get_Gen()[5] == 0 && this->genom[6].get_Gen()[4] == 0) ||
		(this->genom[6].get_Gen()[3] == 1 && this->genom[6].get_Gen()[4] == 0 && this->genom[6].get_Gen()[5] == 0 && this->genom[6].get_Gen()[4] == 1) ||
		(this->genom[6].get_Gen()[3] == 1 && this->genom[6].get_Gen()[4] == 1 && this->genom[6].get_Gen()[5] == 0 && this->genom[6].get_Gen()[4] == 0) ||
		(this->genom[6].get_Gen()[3] == 0 && this->genom[6].get_Gen()[4] == 0 && this->genom[6].get_Gen()[5] == 1 && this->genom[6].get_Gen()[4] == 1)
		) block_2 = true;
	else block_2 = false;


	if (this->genom[6].get_Gen()[7] + this->genom[6].get_Gen()[8] + this->genom[6].get_Gen()[9] == 0) block_3 = false;
	else block_3 = true;

	if ((block_1 && block_2 && block_3) || (!block_1 && block_2 && block_3) ||
		(block_1 && block_2 && !block_3)) return true;
	else return false;

}
/// //////////////////////////////////


/// GEN 7 DECIPHERMENT
/// /////////////////////////////////
int Sm::Genom::gen_7_Decipherment() {
	int block_1{ 0 };
	int block_2{ 0 };
	int block_3{ 2 };
	int block_4{ 0 };

	if (this->genom[7].get_Gen()[0] == 1) block_1 += 2;
	if (this->genom[7].get_Gen()[1] == 1) block_1 += 1;

	if (this->genom[7].get_Gen()[2] == 1) block_2 += 4;
	if (this->genom[7].get_Gen()[3] == 1) block_2 += 2;
	if (this->genom[7].get_Gen()[4] == 1) block_2 += 1;

	if (this->genom[7].get_Gen()[5] == 1) block_3 += 2;
	if (this->genom[7].get_Gen()[6] == 1) block_3 += 1;

	if (this->genom[7].get_Gen()[7] == 1) block_4 += 4;
	if (this->genom[7].get_Gen()[8] == 1) block_4 += 2;
	if (this->genom[7].get_Gen()[9] == 1) block_4 += 1;

	return block_1 * block_2 / block_3 + block_4;

}
/// /////////////////////////////////


/// GEN 8 DECIPHERMENT
/// //////////////////////////////////
bool Sm::Genom::gen_8_Decipherment() {
	bool block_1{ false };
	bool block_2{ false };
	bool block_3{ false };
	bool block_4{ false };
	bool block_5{ false };

	bool S_block_1{ false };
	bool S_block_2{ false };


	if (this->genom[8].get_Gen()[0] + this->genom[8].get_Gen()[1] == 2) block_1 = false;
	else block_1 = true;

	if (this->genom[8].get_Gen()[2] + this->genom[8].get_Gen()[3] == 2) block_2 = false;
	else block_2 = true;

	if (this->genom[8].get_Gen()[4] + this->genom[8].get_Gen()[5] == 0) block_3 = false;
	else block_3 = true;

	if (this->genom[8].get_Gen()[6] + this->genom[8].get_Gen()[7] == 0) block_4 = false;
	else block_4 = true;

	if (this->genom[8].get_Gen()[8] + this->genom[8].get_Gen()[9] == 2) block_5 = false;
	else block_5 = true;

	if (!block_1 && !block_2) S_block_1 = false;
	else S_block_1 = true;

	if (!block_3 && !block_4) S_block_2 = false;
	else S_block_2 = true;

	if ((S_block_1 && S_block_2 && block_5) || (!S_block_1 && S_block_2 && block_5) ||
		(S_block_1 && S_block_2 && !block_5)) return true;
	else return false;

}
/// //////////////////////////////////