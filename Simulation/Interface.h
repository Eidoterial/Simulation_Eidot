#pragma once
#include "Element_Interface.h"

namespace Sm {

	class Interface {

		/// Scalar position element on screen
		///
		/// Take 5 argument
		/// Rectangle element 
		/// ScalarX_start
		/// ScalarY_start
		/// ScalarX-end
		/// ScalarY-end
		void SCALAR_POSITION_ELEMENT_INTERFACE_ON_SCREEN(Sm::Rectangle_Geom&, float, float, float, float);

		/// Scalar position element on element
		///
		/// Take 6 argument
		/// Rectangle element parent
		/// Rectangle element
		/// ScalarX_start
		/// ScalarY_start
		/// ScalarX-end
		/// ScalarY-end
		void SCALAR_POSITION_ELEMENT_INTERFACE_ON_ELEMENT(Sm::Rectangle_Geom, Sm::Rectangle_Geom&, float, float, float, float);


		/// Scalar position text on button
		///
		/// Take 1 argument
		/// Rectangle button element 
		void CENTER_POSITION_TEXT_ON_BUTTON(Sm::Rectangle_Button&);

		/// Scalar position text on element
		///
		/// Take 6 argument
		/// Rectangle element parent
		/// Label
		/// ScalarX_start
		/// ScalarY_start
		void SCALAR_POSITION_TEXT_ON_ELEMENT(Sm::Rectangle_Geom, Sm::Label&, float, float);



		int size_font = 12;


		Sm::Rectangle_Frame frame_information_count_resource_organism_and_void;

		Sm::Label label_information_count_resource;

		Sm::Rectangle_Frame frame_main_toolbar_program;

		Sm::Rectangle_Button button_select;

		sf::Vector2u size_screen;

		sf::Font font;


	public:

		/// Main constructor
		///
		/// Take 1 argument
		/// Size screen
		Interface(sf::Vector2u);

		/// Draw created interface on screen 
		///
		/// Take 1 argument
		/// Self windows
		void draw_Interface_On_Screen(sf::RenderWindow&);

	};


}