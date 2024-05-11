#pragma once
#include <SFML/Graphics.hpp>



namespace Sm {

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


	class Circle_Geom {

		/// Position circle on screen axisX, axisY
		sf::Vector2f position;

		/// Radius circle 
		float radius{ 0.0 };

	public:

		/// Main constructor
		Circle_Geom();


		/// Set position circle
		///
		/// Take 1 argument
		/// Position axisX, axisY
		void set_Position(sf::Vector2f);

		/// Set radius circle
		///
		/// Take 1 argument
		/// Position axisX, axisY
		void set_Radius(float);

		/// Return position circle on screen
		sf::Vector2f get_Position();

		/// Return radius circle
		float get_Radius();

	};


}