#include "Zone_Manager.h"

/// CONSTRUCTOR
/// ///////////////////////////////
Sm::Zone_Manager::Zone_Manager() {};
/// ///////////////////////////////


/// GET ZONES INFORMATION
/// ////////////////////////////////////////////////////////////////////////////
Sm::Config_Zone_Manager& Sm::Zone_Manager::get_Config_Zone_Manager() {
    return this->config_zone_manager;

}
/// ////////////////////////////////////////////////////////////////////////////