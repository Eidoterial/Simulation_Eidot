#pragma once
#include "Element_Interface.h"

namespace Sm {

	struct Interface_Elements {

		/// INFORMATION COUNT

		Sm::Rectangle_Frame frame_information_count_resource_organism;

		Sm::Label label_information_count_resource;
		Sm::Label label_count_resource;

		Sm::Label label_information_count_organism;
		Sm::Label label_count_organism;



		

		/// TOOL BAR
		Sm::Rectangle_Frame frame_main_toolbar_program;

		Sm::Rectangle_Button button_select;
		Sm::Rectangle_Button button_creeate;
		Sm::Rectangle_Button button_copy;
		Sm::Rectangle_Button button_remove;

		Sm::Label label_information_serial_number;
		Sm::Label label_count_serial_number;

		Sm::Label label_information_energi_status;
		Sm::Label label_count_energi_status;

	};

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

		sf::Vector2u size_screen;

		int size_font{ 0 };

		Sm::Interface_Elements interface_elements;
		

		sf::Font font;


	public:

		/// Main constructor
		///
		/// Take 1 argument
		/// Size screen
		Interface(sf::Vector2u);


		/// Return all interface elements
		Sm::Interface_Elements& get_Interface_Elements();

		/// Draw created interface on screen 
		///
		/// Take 1 argument
		/// Self windows
		void draw_Interface_On_Screen(sf::RenderWindow&);

	};


}