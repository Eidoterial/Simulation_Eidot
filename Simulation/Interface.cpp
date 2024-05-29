#include "Interface.h"
#include <iostream>

/// CONSTRUCTOR
/// /////////////////////////////////////////
Sm::Interface::Interface(sf::Vector2u size) {
	this->size_screen = size;
	this->size_font = size.x / 100 * 3;

	if (!this->font.loadFromFile("arial.ttf")) {
		// erroe...
		std::cout << "error";
	}

	/// INFORMATION COUNT /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/// START CREATE /// frame_information_count_resource_organism_and_void
	this->SCALAR_POSITION_ELEMENT_INTERFACE_ON_SCREEN(this->interface_elements.frame_information_count_resource_organism, 0.0, 0.9, 0.5, 0.1);
	this->interface_elements.frame_information_count_resource_organism.get_Background()._r = 100;
	this->interface_elements.frame_information_count_resource_organism.get_Background()._g = 100;
	this->interface_elements.frame_information_count_resource_organism.get_Background()._b = 100;
	/// END CREATE /// frame_information_count_resource_organism_and_void
	
	/// START CREATE /// label_information_count_resourse
	this->interface_elements.label_information_count_resource.set_Text("Resource:");
	this->SCALAR_POSITION_TEXT_ON_ELEMENT(this->interface_elements.frame_information_count_resource_organism, this->interface_elements.label_information_count_resource, 0.01, 0.2);
	this->interface_elements.label_information_count_resource.get_Color_Text()._r = 230;
	this->interface_elements.label_information_count_resource.get_Color_Text()._g = 230;
	this->interface_elements.label_information_count_resource.get_Color_Text()._b = 230;
	/// END CREATE /// label_information_count_resource

	/// START CREATE /// label_count_resource
	this->interface_elements.label_count_resource.set_Text("0");
	this->SCALAR_POSITION_TEXT_ON_ELEMENT(this->interface_elements.frame_information_count_resource_organism, this->interface_elements.label_count_resource, 0.29, 0.2);
	this->interface_elements.label_count_resource.get_Color_Text()._r = 230;
	this->interface_elements.label_count_resource.get_Color_Text()._g = 230;
	this->interface_elements.label_count_resource.get_Color_Text()._b = 230;
	/// END CREATE /// label_count_resource

	/// START CREATE /// label_information_count_organism
	this->interface_elements.label_information_count_organism.set_Text("Organism:");
	this->SCALAR_POSITION_TEXT_ON_ELEMENT(this->interface_elements.frame_information_count_resource_organism, this->interface_elements.label_information_count_organism, 0.51, 0.2);
	this->interface_elements.label_information_count_organism.get_Color_Text()._r = 230;
	this->interface_elements.label_information_count_organism.get_Color_Text()._g = 230;
	this->interface_elements.label_information_count_organism.get_Color_Text()._b = 230;
	/// END CREATE /// label_information_count_organism

	/// START CREATE /// label_count_organism
	this->interface_elements.label_count_organism.set_Text("0");
	this->SCALAR_POSITION_TEXT_ON_ELEMENT(this->interface_elements.frame_information_count_resource_organism, this->interface_elements.label_count_organism, 0.79, 0.2);
	this->interface_elements.label_count_organism.get_Color_Text()._r = 230;
	this->interface_elements.label_count_organism.get_Color_Text()._g = 230;
	this->interface_elements.label_count_organism.get_Color_Text()._b = 230;
	/// END CREATE /// label_count_organism


	/// TOOL BAR //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/// START CREATE /// frame_main_toolbar_program
	this->SCALAR_POSITION_ELEMENT_INTERFACE_ON_SCREEN(this->interface_elements.frame_main_toolbar_program, 0.5, 0.0, 1.0, 1.0);
	this->interface_elements.frame_main_toolbar_program.get_Background()._r = 120;
	this->interface_elements.frame_main_toolbar_program.get_Background()._g = 120;
	this->interface_elements.frame_main_toolbar_program.get_Background()._b = 120;
	/// END CREATE /// frame_main_toolbar_program

	/// START CREATE /// button_select
	this->SCALAR_POSITION_ELEMENT_INTERFACE_ON_ELEMENT(this->interface_elements.frame_main_toolbar_program, this->interface_elements.button_select, 0.05, 0.05, 0.4, 0.1);
	this->interface_elements.button_select.set_Text("Select");
	this->interface_elements.button_select.get_Color_Text()._r = 230;
	this->interface_elements.button_select.get_Color_Text()._g = 230;
	this->interface_elements.button_select.get_Color_Text()._b = 230;
	this->CENTER_POSITION_TEXT_ON_BUTTON(this->interface_elements.button_select);
	this->interface_elements.button_select.get_Background()._r = 180;
	this->interface_elements.button_select.get_Background()._g = 140;
	this->interface_elements.button_select.get_Background()._b = 140;
	/// END CREATE /// button_select

	
	/// START CREATE /// button_creeate
	this->SCALAR_POSITION_ELEMENT_INTERFACE_ON_ELEMENT(this->interface_elements.frame_main_toolbar_program, this->interface_elements.button_creeate, 0.55, 0.05, 0.4, 0.1);
	this->interface_elements.button_creeate.set_Text("Create");
	this->interface_elements.button_creeate.get_Color_Text()._r = 230;
	this->interface_elements.button_creeate.get_Color_Text()._g = 230;
	this->interface_elements.button_creeate.get_Color_Text()._b = 230;
	this->CENTER_POSITION_TEXT_ON_BUTTON(this->interface_elements.button_creeate);
	this->interface_elements.button_creeate.get_Background()._r = 180;
	this->interface_elements.button_creeate.get_Background()._g = 140;
	this->interface_elements.button_creeate.get_Background()._b = 140;
	/// END CREATE /// button_creeate

	/// START CREATE /// button_copy
	this->SCALAR_POSITION_ELEMENT_INTERFACE_ON_ELEMENT(this->interface_elements.frame_main_toolbar_program, this->interface_elements.button_copy, 0.05, 0.25, 0.4, 0.1);
	this->interface_elements.button_copy.set_Text("Copy");
	this->interface_elements.button_copy.get_Color_Text()._r = 230;
	this->interface_elements.button_copy.get_Color_Text()._g = 230;
	this->interface_elements.button_copy.get_Color_Text()._b = 230;
	this->CENTER_POSITION_TEXT_ON_BUTTON(this->interface_elements.button_copy);
	this->interface_elements.button_copy.get_Background()._r = 180;
	this->interface_elements.button_copy.get_Background()._g = 140;
	this->interface_elements.button_copy.get_Background()._b = 140;
	/// END CREATE /// button_copy

	/// START CREATE /// button_remove
	this->SCALAR_POSITION_ELEMENT_INTERFACE_ON_ELEMENT(this->interface_elements.frame_main_toolbar_program, this->interface_elements.button_remove, 0.55, 0.25, 0.4, 0.1);
	this->interface_elements.button_remove.set_Text("Remove");
	this->interface_elements.button_remove.get_Color_Text()._r = 230;
	this->interface_elements.button_remove.get_Color_Text()._g = 230;
	this->interface_elements.button_remove.get_Color_Text()._b = 230;
	this->CENTER_POSITION_TEXT_ON_BUTTON(this->interface_elements.button_remove);
	this->interface_elements.button_remove.get_Background()._r = 180;
	this->interface_elements.button_remove.get_Background()._g = 140;
	this->interface_elements.button_remove.get_Background()._b = 140;
	/// END CREATE /// button_remove

	/// START CREATE /// label_information_serial_number
	this->interface_elements.label_information_serial_number.set_Text("Serial number:");
	this->SCALAR_POSITION_TEXT_ON_ELEMENT(this->interface_elements.frame_main_toolbar_program, this->interface_elements.label_information_serial_number, 0.1, 0.7);
	this->interface_elements.label_information_serial_number.get_Color_Text()._r = 230;
	this->interface_elements.label_information_serial_number.get_Color_Text()._g = 230;
	this->interface_elements.label_information_serial_number.get_Color_Text()._b = 230;
	/// END CREATE /// label_information_serial_number

	/// START CREATE /// label_count_serial_number
	this->interface_elements.label_count_serial_number.set_Text("--");
	this->SCALAR_POSITION_TEXT_ON_ELEMENT(this->interface_elements.frame_main_toolbar_program, this->interface_elements.label_count_serial_number, 0.5, 0.7);
	this->interface_elements.label_count_serial_number.get_Color_Text()._r = 230;
	this->interface_elements.label_count_serial_number.get_Color_Text()._g = 230;
	this->interface_elements.label_count_serial_number.get_Color_Text()._b = 230;
	/// END CREATE /// label_count_serial_number

	/// START CREATE /// label_information_energi_status
	this->interface_elements.label_information_energi_status.set_Text("Energi status:");
	this->SCALAR_POSITION_TEXT_ON_ELEMENT(this->interface_elements.frame_main_toolbar_program, this->interface_elements.label_information_energi_status, 0.1, 0.8);
	this->interface_elements.label_information_energi_status.get_Color_Text()._r = 230;
	this->interface_elements.label_information_energi_status.get_Color_Text()._g = 230;
	this->interface_elements.label_information_energi_status.get_Color_Text()._b = 230;
	/// END CREATE /// label_information_energi_status

	/// START CREATE /// label_count_energi_status
	this->interface_elements.label_count_energi_status.set_Text("--");
	this->SCALAR_POSITION_TEXT_ON_ELEMENT(this->interface_elements.frame_main_toolbar_program, this->interface_elements.label_count_energi_status, 0.5, 0.8);
	this->interface_elements.label_count_energi_status.get_Color_Text()._r = 230;
	this->interface_elements.label_count_energi_status.get_Color_Text()._g = 230;
	this->interface_elements.label_count_energi_status.get_Color_Text()._b = 230;
	/// END CREATE /// label_count_energi_status

}
/// /////////////////////////////////////////


/// SCALAR POSITION ELEMENT INTERFACE ON SCREEN
/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Sm::Interface::SCALAR_POSITION_ELEMENT_INTERFACE_ON_SCREEN(Sm::Rectangle_Geom& element, float scalX_start, float scalY_start, float scalX_end, float scalY_end) {

	element.set_Position(sf::Vector2f(this->size_screen.x * scalX_start, this->size_screen.y * scalY_start));
	element.set_Size(sf::Vector2f(this->size_screen.x * scalX_end, this->size_screen.y * scalY_end));


}
/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/// SCALAR POSITION ELEMENT INTERFACE ON ELEMENT
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Sm::Interface::SCALAR_POSITION_ELEMENT_INTERFACE_ON_ELEMENT(Sm::Rectangle_Geom parent, Sm::Rectangle_Geom& element, float scalX_start, float scalY_start, float scalX_end, float scalY_end) {

	element.set_Position(sf::Vector2f((parent.get_Size().x - parent.get_Position().x) * scalX_start + parent.get_Position().x,
		(parent.get_Size().y - parent.get_Position().y) * scalY_start + parent.get_Position().y));
	element.set_Size(sf::Vector2f((parent.get_Size().x - parent.get_Position().x) * scalX_end,
		(parent.get_Size().y - parent.get_Position().y) * scalY_end));

}
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/// CENTER POSITION TEXT ON BUTTON
/// //////////////////////////////////////////////////////////////////////////////
void Sm::Interface::CENTER_POSITION_TEXT_ON_BUTTON(Sm::Rectangle_Button& button) {
	
	button.set_Text_Position(sf::Vector2f(button.get_Size().x / 2 - (button.get_Text().size() + this->size_font) + button.get_Position().x,
		button.get_Size().y / 2 - this->size_font / 2 + button.get_Position().y));

}
/// //////////////////////////////////////////////////////////////////////////////


/// SCALAR POSITION TEXT ON ELEMENT
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Sm::Interface::SCALAR_POSITION_TEXT_ON_ELEMENT(Sm::Rectangle_Geom parent, Sm::Label& element, float scalX_start, float scalY_start) {

	element.set_Text_Position(sf::Vector2f((parent.get_Size().x - parent.get_Position().x) * scalX_start + parent.get_Position().x,
		(parent.get_Size().y ) *scalY_start  + parent.get_Position().y));

}
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/// GET INTERFACE ELEMENTS
/// /////////////////////////////////////////////////////////////
Sm::Interface_Elements& Sm::Interface::get_Interface_Elements() {
	return this->interface_elements;

}
/// /////////////////////////////////////////////////////////////


/// DRAW INTERFACE ON SCREEN
/// ////////////////////////////////////////////////////////////////////
void Sm::Interface::draw_Interface_On_Screen(sf::RenderWindow& window) {
	sf::RectangleShape rectangle_mask;

	sf::Text text;
	text.setFont(this->font);
	text.setCharacterSize(this->size_font);



	/// START DRAW /// frame_information_count_resource_organism_and_void
	rectangle_mask.setPosition(this->interface_elements.frame_information_count_resource_organism.get_Position());
	rectangle_mask.setSize(this->interface_elements.frame_information_count_resource_organism.get_Size());
	rectangle_mask.setFillColor(sf::Color::Color(this->interface_elements.frame_information_count_resource_organism.get_Background()._r,
		this->interface_elements.frame_information_count_resource_organism.get_Background()._g,
		this->interface_elements.frame_information_count_resource_organism.get_Background()._b,
		this->interface_elements.frame_information_count_resource_organism.get_Background()._a));
	window.draw(rectangle_mask);
	/// END DRAW /// frame_information_count_resource_organism_and_void

	/// START DRAW /// label_information_count_resource
	text.setString(this->interface_elements.label_information_count_resource.get_Text());
	text.setPosition(this->interface_elements.label_information_count_resource.get_Text_Position());
	text.setFillColor(sf::Color::Color(this->interface_elements.label_information_count_resource.get_Color_Text()._r,
		this->interface_elements.label_information_count_resource.get_Color_Text()._g,
		this->interface_elements.label_information_count_resource.get_Color_Text()._b,
		this->interface_elements.label_information_count_resource.get_Color_Text()._a));
	window.draw(text);
	/// END DRAW /// label_information_count_resource

	/// START DRAW /// label_count_resource
	text.setString(this->interface_elements.label_count_resource.get_Text());
	text.setPosition(this->interface_elements.label_count_resource.get_Text_Position());
	text.setFillColor(sf::Color::Color(this->interface_elements.label_count_resource.get_Color_Text()._r,
		this->interface_elements.label_count_resource.get_Color_Text()._g,
		this->interface_elements.label_count_resource.get_Color_Text()._b,
		this->interface_elements.label_count_resource.get_Color_Text()._a));
	window.draw(text);
	/// END DRAW /// label_count_resource

	/// START DRAW /// label_information_count_organism
	text.setString(this->interface_elements.label_information_count_organism.get_Text());
	text.setPosition(this->interface_elements.label_information_count_organism.get_Text_Position());
	text.setFillColor(sf::Color::Color(this->interface_elements.label_information_count_organism.get_Color_Text()._r,
		this->interface_elements.label_information_count_organism.get_Color_Text()._g,
		this->interface_elements.label_information_count_organism.get_Color_Text()._b,
		this->interface_elements.label_information_count_organism.get_Color_Text()._a));
	window.draw(text);
	/// END DRAW /// label_information_count_organism

	/// START DRAW /// label_count_organism
	text.setString(this->interface_elements.label_count_organism.get_Text());
	text.setPosition(this->interface_elements.label_count_organism.get_Text_Position());
	text.setFillColor(sf::Color::Color(this->interface_elements.label_count_organism.get_Color_Text()._r,
		this->interface_elements.label_count_organism.get_Color_Text()._g,
		this->interface_elements.label_count_organism.get_Color_Text()._b,
		this->interface_elements.label_count_organism.get_Color_Text()._a));
	window.draw(text);
	/// END DRAW /// label_count_organism








	/// START DRAW /// frame_main_toolbar_program
	rectangle_mask.setPosition(this->interface_elements.frame_main_toolbar_program.get_Position());
	rectangle_mask.setSize(this->interface_elements.frame_main_toolbar_program.get_Size());
	rectangle_mask.setFillColor(sf::Color::Color(this->interface_elements.frame_main_toolbar_program.get_Background()._r,
		this->interface_elements.frame_main_toolbar_program.get_Background()._g,
		this->interface_elements.frame_main_toolbar_program.get_Background()._b,
		this->interface_elements.frame_main_toolbar_program.get_Background()._a));
	window.draw(rectangle_mask);
	/// END DRAW /// frame_main_toolbar_program


	/// START DRAW /// button_select
	rectangle_mask.setPosition(this->interface_elements.button_select.get_Position());
	rectangle_mask.setSize(this->interface_elements.button_select.get_Size());
	rectangle_mask.setFillColor(sf::Color::Color(this->interface_elements.button_select.get_Background()._r,
		this->interface_elements.button_select.get_Background()._g,
		this->interface_elements.button_select.get_Background()._b,
		this->interface_elements.button_select.get_Background()._a));
	text.setString(this->interface_elements.button_select.get_Text());
	text.setPosition(this->interface_elements.button_select.get_Text_Position());
	text.setFillColor(sf::Color::Color(this->interface_elements.button_select.get_Color_Text()._r,
		this->interface_elements.button_select.get_Color_Text()._g,
		this->interface_elements.button_select.get_Color_Text()._b,
		this->interface_elements.button_select.get_Color_Text()._a));
	window.draw(rectangle_mask);
	window.draw(text);
	/// END DRAW /// button_select

	/// START DRAW /// button_creeate
	rectangle_mask.setPosition(this->interface_elements.button_creeate.get_Position());
	rectangle_mask.setSize(this->interface_elements.button_creeate.get_Size());
	rectangle_mask.setFillColor(sf::Color::Color(this->interface_elements.button_creeate.get_Background()._r,
		this->interface_elements.button_creeate.get_Background()._g,
		this->interface_elements.button_creeate.get_Background()._b,
		this->interface_elements.button_creeate.get_Background()._a));
	text.setString(this->interface_elements.button_creeate.get_Text());
	text.setPosition(this->interface_elements.button_creeate.get_Text_Position());
	text.setFillColor(sf::Color::Color(this->interface_elements.button_creeate.get_Color_Text()._r,
		this->interface_elements.button_creeate.get_Color_Text()._g,
		this->interface_elements.button_creeate.get_Color_Text()._b,
		this->interface_elements.button_creeate.get_Color_Text()._a));
	window.draw(rectangle_mask);
	window.draw(text);
	/// END DRAW /// button_creeate

	/// START DRAW /// button_copy
	rectangle_mask.setPosition(this->interface_elements.button_copy.get_Position());
	rectangle_mask.setSize(this->interface_elements.button_copy.get_Size());
	rectangle_mask.setFillColor(sf::Color::Color(this->interface_elements.button_copy.get_Background()._r,
		this->interface_elements.button_copy.get_Background()._g,
		this->interface_elements.button_copy.get_Background()._b,
		this->interface_elements.button_copy.get_Background()._a));
	text.setString(this->interface_elements.button_copy.get_Text());
	text.setPosition(this->interface_elements.button_copy.get_Text_Position());
	text.setFillColor(sf::Color::Color(this->interface_elements.button_copy.get_Color_Text()._r,
		this->interface_elements.button_copy.get_Color_Text()._g,
		this->interface_elements.button_copy.get_Color_Text()._b,
		this->interface_elements.button_copy.get_Color_Text()._a));
	window.draw(rectangle_mask);
	window.draw(text);
	/// END DRAW /// button_copy

	/// START DRAW /// button_remove
	rectangle_mask.setPosition(this->interface_elements.button_remove.get_Position());
	rectangle_mask.setSize(this->interface_elements.button_remove.get_Size());
	rectangle_mask.setFillColor(sf::Color::Color(this->interface_elements.button_remove.get_Background()._r,
		this->interface_elements.button_remove.get_Background()._g,
		this->interface_elements.button_remove.get_Background()._b,
		this->interface_elements.button_remove.get_Background()._a));
	text.setString(this->interface_elements.button_remove.get_Text());
	text.setPosition(this->interface_elements.button_remove.get_Text_Position());
	text.setFillColor(sf::Color::Color(this->interface_elements.button_remove.get_Color_Text()._r,
		this->interface_elements.button_remove.get_Color_Text()._g,
		this->interface_elements.button_remove.get_Color_Text()._b,
		this->interface_elements.button_remove.get_Color_Text()._a));
	window.draw(rectangle_mask);
	window.draw(text);
	/// END DRAW /// button_remove

	/// START DRAW /// label_information_serial_number
	text.setString(this->interface_elements.label_information_serial_number.get_Text());
	text.setPosition(this->interface_elements.label_information_serial_number.get_Text_Position());
	text.setFillColor(sf::Color::Color(this->interface_elements.label_information_serial_number.get_Color_Text()._r,
		this->interface_elements.label_information_serial_number.get_Color_Text()._g,
		this->interface_elements.label_information_serial_number.get_Color_Text()._b,
		this->interface_elements.label_information_serial_number.get_Color_Text()._a));
	window.draw(text);
	/// END DRAW /// label_information_serial_number

	/// START DRAW /// label_count_serial_number
	text.setString(this->interface_elements.label_count_serial_number.get_Text());
	text.setPosition(this->interface_elements.label_count_serial_number.get_Text_Position());
	text.setFillColor(sf::Color::Color(this->interface_elements.label_count_serial_number.get_Color_Text()._r,
		this->interface_elements.label_count_serial_number.get_Color_Text()._g,
		this->interface_elements.label_count_serial_number.get_Color_Text()._b,
		this->interface_elements.label_count_serial_number.get_Color_Text()._a));
	window.draw(text);
	/// END DRAW /// label_count_serial_number

	/// START DRAW /// label_information_energi_status
	text.setString(this->interface_elements.label_information_energi_status.get_Text());
	text.setPosition(this->interface_elements.label_information_energi_status.get_Text_Position());
	text.setFillColor(sf::Color::Color(this->interface_elements.label_information_energi_status.get_Color_Text()._r,
		this->interface_elements.label_information_energi_status.get_Color_Text()._g,
		this->interface_elements.label_information_energi_status.get_Color_Text()._b,
		this->interface_elements.label_information_energi_status.get_Color_Text()._a));
	window.draw(text);
	/// END DRAW /// label_information_energi_status

	/// START DRAW /// label_count_energi_status
	text.setString(this->interface_elements.label_count_energi_status.get_Text());
	text.setPosition(this->interface_elements.label_count_energi_status.get_Text_Position());
	text.setFillColor(sf::Color::Color(this->interface_elements.label_count_energi_status.get_Color_Text()._r,
		this->interface_elements.label_count_energi_status.get_Color_Text()._g,
		this->interface_elements.label_count_energi_status.get_Color_Text()._b,
		this->interface_elements.label_count_energi_status.get_Color_Text()._a));
	window.draw(text);
	/// END DRAW /// label_count_energi_status

}
/// ////////////////////////////////////////////////////////////////////
