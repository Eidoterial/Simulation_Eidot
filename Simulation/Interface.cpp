#include "Interface.h"
#include <iostream>

/// CONSTRUCTOR
/// /////////////////////////////////////////
Sm::Interface::Interface(sf::Vector2u size) {
	this->size_screen = size;


	if (!this->font.loadFromFile("arial.ttf")) {
		// erroe...
		std::cout << "error";
	}

	/// START CREATE /// frame_information_count_resource_organism_and_void
	this->SCALAR_POSITION_ELEMENT_INTERFACE_ON_SCREEN(this->frame_information_count_resource_organism_and_void, 0.0, 0.9, 1.0, 1.0);
	this->frame_information_count_resource_organism_and_void.get_Background()._r = 100;
	this->frame_information_count_resource_organism_and_void.get_Background()._g = 100;
	this->frame_information_count_resource_organism_and_void.get_Background()._b = 100;
	/// END CREATE /// frame_information_count_resource_organism_and_void
	
	/// START CREATE /// label_information_count_resourse
	this->label_information_count_resource.set_Text("Resource:");
	this->SCALAR_POSITION_TEXT_ON_ELEMENT(this->frame_information_count_resource_organism_and_void, this->label_information_count_resource, 0.1, 0.6);
	this->label_information_count_resource.get_Color_Text()._r = 230;
	this->label_information_count_resource.get_Color_Text()._g = 230;
	this->label_information_count_resource.get_Color_Text()._b = 230;
	/// END CREATE /// label_information_count_resource

	/// START CREATE /// frame_main_toolbar_program
	this->SCALAR_POSITION_ELEMENT_INTERFACE_ON_SCREEN(this->frame_main_toolbar_program, 0.65, 0.0, 1.0, 1.0);
	this->frame_main_toolbar_program.get_Background()._r = 120;
	this->frame_main_toolbar_program.get_Background()._g = 120;
	this->frame_main_toolbar_program.get_Background()._b = 120;
	/// END CREATE /// frame_main_toolbar_program

	/// START CREATE /// button_select
	this->SCALAR_POSITION_ELEMENT_INTERFACE_ON_ELEMENT(this->frame_main_toolbar_program, this->button_select, 0.05, 0.05, 0.45, 0.1);
	this->button_select.set_Text("Select");
	this->button_select.get_Color_Text()._r = 230;
	this->button_select.get_Color_Text()._g = 230;
	this->button_select.get_Color_Text()._b = 230;
	this->CENTER_POSITION_TEXT_ON_BUTTON(this->button_select);
	this->button_select.get_Background()._r = 180;
	this->button_select.get_Background()._g = 140;
	this->button_select.get_Background()._b = 140;
	/// END CREATE /// button_select

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
		(button.get_Size().y - button.get_Position().y) / 2 + button.get_Position().y));

}
/// //////////////////////////////////////////////////////////////////////////////


/// SCALAR POSITION TEXT ON ELEMENT

void Sm::Interface::SCALAR_POSITION_TEXT_ON_ELEMENT(Sm::Rectangle_Geom parent, Sm::Label& element, float scalX_start, float scalY_start) {

	element.set_Text_Position(sf::Vector2f((parent.get_Size().x - parent.get_Position().x) * scalX_start + parent.get_Position().x,
		(parent.get_Size().y - parent.get_Position().y) * scalY_start + parent.get_Position().y));

}


/// DRAW INTERFACE ON SCREEN
/// ////////////////////////////////////////////////////////////////////
void Sm::Interface::draw_Interface_On_Screen(sf::RenderWindow& window) {
	sf::RectangleShape rectangle_mask;

	sf::Text text;
	text.setFont(this->font);
	text.setCharacterSize(this->size_font);



	/// START DRAW /// frame_information_count_resource_organism_and_void
	rectangle_mask.setPosition(this->frame_information_count_resource_organism_and_void.get_Position());
	rectangle_mask.setSize(this->frame_information_count_resource_organism_and_void.get_Size());
	rectangle_mask.setFillColor(sf::Color::Color(this->frame_information_count_resource_organism_and_void.get_Background()._r,
		this->frame_information_count_resource_organism_and_void.get_Background()._g,
		this->frame_information_count_resource_organism_and_void.get_Background()._b,
		this->frame_information_count_resource_organism_and_void.get_Background()._a));
	window.draw(rectangle_mask);
	/// END DRAW /// frame_information_count_resource_organism_and_void

	/// START DRAW /// label_information_count_resource
	text.setString(this->label_information_count_resource.get_Text());
	text.setPosition(this->label_information_count_resource.get_Text_Position());
	text.setFillColor(sf::Color::Color(this->label_information_count_resource.get_Color_Text()._r,
		this->label_information_count_resource.get_Color_Text()._g,
		this->label_information_count_resource.get_Color_Text()._b,
		this->label_information_count_resource.get_Color_Text()._a));
	window.draw(text);

	/// END DRAW /// label_information_count_resource

	/// START DRAW /// frame_main_toolbar_program
	rectangle_mask.setPosition(this->frame_main_toolbar_program.get_Position());
	rectangle_mask.setSize(this->frame_main_toolbar_program.get_Size());
	rectangle_mask.setFillColor(sf::Color::Color(this->frame_main_toolbar_program.get_Background()._r,
		this->frame_main_toolbar_program.get_Background()._g,
		this->frame_main_toolbar_program.get_Background()._b,
		this->frame_main_toolbar_program.get_Background()._a));
	window.draw(rectangle_mask);
	/// END DRAW /// frame_main_toolbar_program

	/// START DRAW /// button_select
	rectangle_mask.setPosition(this->button_select.get_Position());
	rectangle_mask.setSize(this->button_select.get_Size());
	rectangle_mask.setFillColor(sf::Color::Color(this->button_select.get_Background()._r,
		this->button_select.get_Background()._g,
		this->button_select.get_Background()._b,
		this->button_select.get_Background()._a));
	text.setString(this->button_select.get_Text());
	text.setPosition(this->button_select.get_Text_Position());
	text.setFillColor(sf::Color::Color(this->button_select.get_Color_Text()._r,
		this->button_select.get_Color_Text()._g,
		this->button_select.get_Color_Text()._b,
		this->button_select.get_Color_Text()._a));
	window.draw(rectangle_mask);
	window.draw(text);
	/// END DRAW /// button_select

}
/// ////////////////////////////////////////////////////////////////////
