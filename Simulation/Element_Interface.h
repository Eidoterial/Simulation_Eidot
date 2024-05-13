#pragma once
#include "Geometry.h"
#include "string.h"

namespace Sm {

	class Rectangle_Button : public Sm::Rectangle_Geom {

		sf::Color color;

		std::string text;

	public:


		
	};


	class Circle_Button : public Sm::Circle_Geom {

		sf::Color color;

		std::string text;

	};

	class Label : public Sm::Rectangle_Geom {

		sf::Color color;

		std::string text;

	};

	class Frame : public Sm::Rectangle_Geom {

		sf::Color color;

	};


}