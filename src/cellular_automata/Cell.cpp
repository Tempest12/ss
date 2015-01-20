#include "cellular_automata/Cell.hpp"
#include "core/Color.hpp"

using namespace cellularAutomata;

Cell::Cell()
{
	this->color = new Core::Color(0.0f);
	this->value = 0.0f;
}

Cell::Cell(float red, float green, float blue)
{
	this->color = new Core::Color(red, green, blue);
	this->value = 0.0f;
}

Cell::~Cell()
{
	delete this->color;
}