#pragma once
#include "Geometry.h"
#include "string.h"

namespace Sm {

	class Rectangle_Button : public Sm::Rectangle_Geom {

		Sm::Color_sm background;

		Sm::Color_sm color_text;

		sf::Vector2f text_position;

		std::string text;

	public:

		/// Main constructor
		Rectangle_Button();
		
		/// Return background
		Sm::Color_sm& get_Background();

		/// Return color text
		Sm::Color_sm& get_Color_Text();

		/// Set text
		void set_Text(std::string);

		/// Set text position
		void set_Text_Position(sf::Vector2f);

		/// Return text
		std::string get_Text();

		/// Return text position
		sf::Vector2f get_Text_Position();

	};

	class Label {

		sf::Vector2f text_position;

		Sm::Color_sm color_text;

		std::string text;

	public:

		/// Main constructor
		Label();

		/// Return color text
		Sm::Color_sm& get_Color_Text();

		/// Set text
		void set_Text(std::string);

		/// Set text position
		void set_Text_Position(sf::Vector2f);

		/// Return text
		std::string get_Text();

		/// Return text position
		sf::Vector2f get_Text_Position();


	};

	class Rectangle_Frame : public Sm::Rectangle_Geom {

		Sm::Color_sm background;


	public:

		/// Main constructor
		Rectangle_Frame();

		/// Return background
		Sm::Color_sm& get_Background();

	};


}