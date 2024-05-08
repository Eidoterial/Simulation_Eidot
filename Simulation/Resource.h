#pragma once
#include <SFML/Graphics.hpp>
#include "Config_Environment_Zone.h"

namespace Sm {

	struct Config_Resource {

		/// Type resource
		/// 0 - default
		/// 1 - poision
		int type{ 0 };

		/// Count addition or subtraction energi
		int energi{ 0 };

	};

	class Resource : public Sm::Config_Environment_Zone{

		/// Save main configuration resource
		Config_Resource config_resource;

	public:

		/// Main constructor
		Resource();

		/// Return main configuration resource
		Config_Resource& get_Config_Resource();

	};

}