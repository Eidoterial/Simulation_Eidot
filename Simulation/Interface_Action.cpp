#include "Interface_Action.h"
#include <iostream>


/// CONSTRUCTOR
/// ////////////////////////////////////
Sm::Interface_Hover::Interface_Hover(){}
/// ////////////////////////////////////


/// CHECK COLISION
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Sm::Interface_Hover::check_Colision(Sm::Interface& interfaces, sf::Mouse& mouse, sf::RenderWindow& window) {

	if (mouse.getPosition(window).x >= 0 && mouse.getPosition(window).y >= 0) {


			interfaces.get_Interface_Elements().button_select.get_Background()._r = 180;
			interfaces.get_Interface_Elements().button_select.get_Background()._g = 140;
			interfaces.get_Interface_Elements().button_select.get_Background()._b = 140;

			interfaces.get_Interface_Elements().button_creeate.get_Background()._r = 180;
			interfaces.get_Interface_Elements().button_creeate.get_Background()._g = 140;
			interfaces.get_Interface_Elements().button_creeate.get_Background()._b = 140;

			interfaces.get_Interface_Elements().button_copy.get_Background()._r = 180;
			interfaces.get_Interface_Elements().button_copy.get_Background()._g = 140;
			interfaces.get_Interface_Elements().button_copy.get_Background()._b = 140;

			interfaces.get_Interface_Elements().button_remove.get_Background()._r = 180;
			interfaces.get_Interface_Elements().button_remove.get_Background()._g = 140;
			interfaces.get_Interface_Elements().button_remove.get_Background()._b = 140;

			interfaces.get_Interface_Elements().button_restart.get_Background()._r = 180;
			interfaces.get_Interface_Elements().button_restart.get_Background()._g = 140;
			interfaces.get_Interface_Elements().button_restart.get_Background()._b = 140;
		
		if (this->check_Colider(interfaces.get_Interface_Elements().button_select.get_Position(), interfaces.get_Interface_Elements().button_select.get_Size(), mouse.getPosition(window))) {
			interfaces.get_Interface_Elements().button_select.get_Background()._r = 50;
			interfaces.get_Interface_Elements().button_select.get_Background()._g = 50;
			interfaces.get_Interface_Elements().button_select.get_Background()._b = 50;

		}

		else if (this->check_Colider(interfaces.get_Interface_Elements().button_creeate.get_Position(), interfaces.get_Interface_Elements().button_creeate.get_Size(), mouse.getPosition(window))) {
			interfaces.get_Interface_Elements().button_creeate.get_Background()._r = 50;
			interfaces.get_Interface_Elements().button_creeate.get_Background()._g = 50;
			interfaces.get_Interface_Elements().button_creeate.get_Background()._b = 50;

		}

		else if (this->check_Colider(interfaces.get_Interface_Elements().button_copy.get_Position(), interfaces.get_Interface_Elements().button_copy.get_Size(), mouse.getPosition(window))) {
			interfaces.get_Interface_Elements().button_copy.get_Background()._r = 50;
			interfaces.get_Interface_Elements().button_copy.get_Background()._g = 50;
			interfaces.get_Interface_Elements().button_copy.get_Background()._b = 50;

		}

		else if (this->check_Colider(interfaces.get_Interface_Elements().button_remove.get_Position(), interfaces.get_Interface_Elements().button_remove.get_Size(), mouse.getPosition(window))) {
			interfaces.get_Interface_Elements().button_remove.get_Background()._r = 50;
			interfaces.get_Interface_Elements().button_remove.get_Background()._g = 50;
			interfaces.get_Interface_Elements().button_remove.get_Background()._b = 50;

		}

		else if (this->check_Colider(interfaces.get_Interface_Elements().button_restart.get_Position(), interfaces.get_Interface_Elements().button_restart.get_Size(), mouse.getPosition(window))) {
			interfaces.get_Interface_Elements().button_restart.get_Background()._r = 50;
			interfaces.get_Interface_Elements().button_restart.get_Background()._g = 50;
			interfaces.get_Interface_Elements().button_restart.get_Background()._b = 50;

		}

	}

}
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////


/// CHECK ACTIVATE
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Sm::Interface_Hover::check_Activate(Sm::Interface& interfaces, sf::Mouse& mouse, sf::RenderWindow& window) {

	if (this->check_Colider(interfaces.get_Interface_Elements().button_select.get_Position(), interfaces.get_Interface_Elements().button_select.get_Size(), mouse.getPosition(window))) {
		if (interfaces.get_Interface_Elements().button_select.get_Status()) interfaces.get_Interface_Elements().button_select.set_Status(false);
		else interfaces.get_Interface_Elements().button_select.set_Status(true);
		return 1;

	}

	else if (this->check_Colider(interfaces.get_Interface_Elements().button_creeate.get_Position(), interfaces.get_Interface_Elements().button_creeate.get_Size(), mouse.getPosition(window))) {
		if (interfaces.get_Interface_Elements().button_creeate.get_Status()) interfaces.get_Interface_Elements().button_creeate.set_Status(false);
		else interfaces.get_Interface_Elements().button_creeate.set_Status(true);
		return 2;

	}

	else if (this->check_Colider(interfaces.get_Interface_Elements().button_copy.get_Position(), interfaces.get_Interface_Elements().button_copy.get_Size(), mouse.getPosition(window))) {
		if (interfaces.get_Interface_Elements().button_copy.get_Status()) interfaces.get_Interface_Elements().button_copy.set_Status(false);
		else interfaces.get_Interface_Elements().button_copy.set_Status(true);
		return 3;

	}

	else if (this->check_Colider(interfaces.get_Interface_Elements().button_remove.get_Position(), interfaces.get_Interface_Elements().button_remove.get_Size(), mouse.getPosition(window))) {
		if (interfaces.get_Interface_Elements().button_remove.get_Status()) interfaces.get_Interface_Elements().button_remove.set_Status(false);
		else interfaces.get_Interface_Elements().button_remove.set_Status(true);
		return 4;

	}

	else if (this->check_Colider(interfaces.get_Interface_Elements().button_restart.get_Position(), interfaces.get_Interface_Elements().button_restart.get_Size(), mouse.getPosition(window))) {
		if (interfaces.get_Interface_Elements().button_restart.get_Status()) interfaces.get_Interface_Elements().button_restart.set_Status(false);
		else interfaces.get_Interface_Elements().button_restart.set_Status(true);
		return 5;

	}
}
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////



/// CHECK COLIDER
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Sm::Interface_Hover::check_Colider(sf::Vector2f position_el, sf::Vector2f size_el, sf::Vector2i position_mouse) {
	if ((position_el.x < position_mouse.x && position_el.x + size_el.x > position_mouse.x) &&
		(position_el.y < position_mouse.y && position_el.y + size_el.y > position_mouse.y)) return true;
	else return false;

}
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////