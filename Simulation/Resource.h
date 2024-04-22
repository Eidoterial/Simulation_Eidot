#pragma once
#include <SFML/Graphics.hpp>

namespace Sm {

	struct Type_resource {
		// 0 - default
		// 1 - super-resource
		// 2 - unresource
		int type;
	};

	class Resource {
		Sm::Type_resource type_resource;
		bool energi_status;
		int energi_count;
		sf::Vector2i id_position;

	public:

		Resource(); // Constructor

		// Setter
		void set_Type_Resource(int);
		void set_Energi_Status(bool);
		void set_Energi_Count(int);
		void set_Id_Position(sf::Vector2i);

		// Getter
		int get_Type_Resource();
		bool get_Energi_Status();
		int get_Energi_Count();
		sf::Vector2i get_Id_Position();

	};

}