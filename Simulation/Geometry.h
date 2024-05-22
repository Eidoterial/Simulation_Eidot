#pragma once
#include <SFML/Graphics.hpp>



namespace Sm {

	struct Color_sm {

		/// Color red
		int _r{ 0 };

		/// Color green
		int _g{ 0 };

		/// Color blue
		int _b{ 0 };

		/// Alpha - visible
		int _a{ 255 };



	};

	class Rectangle_Geom {

		/// Position rectangle on screen axisX, axisY
		sf::Vector2f position;

		/// Size restangle axisX, axisY
		sf::Vector2f size;


	public:

		/// Main constructor 
		Rectangle_Geom();

		/// Set position rectangle
		///
		/// Take 1 argument
		/// Position axisX, axisY
		void set_Position(sf::Vector2f);

		/// Set size rectangle
		///
		/// Take 1 argument
		/// Size axisX, axisY
		void set_Size(sf::Vector2f);

		/// Return position rectangle on screen
		sf::Vector2f get_Position();

		/// Return size rectangle
		sf::Vector2f get_Size();

	};

}