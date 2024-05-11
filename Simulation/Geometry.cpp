#include "Geometry.h"

/// RECTANGLE GEOM
/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/// CONSTRUCTOR
/// ///////////////////////////////////
Sm::Rectangle_Geom::Rectangle_Geom() {}
/// ///////////////////////////////////


/// SET POSITION
/// //////////////////////////////////////////////////////////
void Sm::Rectangle_Geom::set_Position(sf::Vector2f position) {
	this->position = position;

}
/// //////////////////////////////////////////////////////////


/// SET SIZE
/// //////////////////////////////////////////////////
void Sm::Rectangle_Geom::set_Size(sf::Vector2f size) {
	this->size = size;

}
/// //////////////////////////////////////////////////


/// GET POSITION ////////////////////////////////
sf::Vector2f Sm::Rectangle_Geom::get_Position() {
	return this->position;

}
/// /////////////////////////////////////////////


/// GET SIZE
/// /////////////////////////////////////////
sf::Vector2f Sm::Rectangle_Geom::get_Size() {
	return this->size;

}
/// /////////////////////////////////////////



/// CIRCLE GEOM
/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/// CONSTRUCTOR
/// ///////////////////////////////////
Sm::Circle_Geom::Circle_Geom() {}
/// ///////////////////////////////////


/// SET POSITION
/// //////////////////////////////////////////////////////////
void Sm::Circle_Geom::set_Position(sf::Vector2f position) {
	this->position = position;

}
/// //////////////////////////////////////////////////////////


/// SET RADIUS
/// //////////////////////////////////////////////////
void Sm::Circle_Geom::set_Radius(float radius) {
	this->radius = radius;

}
/// //////////////////////////////////////////////////


/// GET POSITION ////////////////////////////////
sf::Vector2f Sm::Circle_Geom::get_Position() {
	return this->position;

}
/// /////////////////////////////////////////////


/// GET RADIUS
/// /////////////////////////////////////////
float Sm::Circle_Geom::get_Radius() {
	return this->radius;

}
/// /////////////////////////////////////////