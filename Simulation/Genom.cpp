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