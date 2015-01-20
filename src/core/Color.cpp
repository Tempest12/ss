#include <random>

#include "core/Color.hpp"

using namespace Core;

Color::Color()
{
	this->set(0.0f);
}

Color::Color(float all)
{
	this->set(all);
}

Color::Color(float red  , float green, float blue)
{
	this->set(red, green, blue);
}

Color::Color(float red  , float green, float blue, float alpha)
{
	this->set(red, green, blue, alpha);
}

Color::~Color()
{
}

void Color::set(float all)
{
	this->set(all, all, all, all);
}

void Color::set(float red  , float green, float blue)
{
	this->set(red, green, blue, 1.0f);
}

void Color::set(float red  , float green, float blue , float alpha)
{
	this->red   = red;
	this->green = green;
	this->blue  = blue;
	this->alpha = alpha;
}

////////////////////////////////////////////////////////////////////////////////////
///                           Static Stuff:                                      ///
////////////////////////////////////////////////////////////////////////////////////
Color* Color::getRandomColor(void)
{
	std::minstd_rand random = std::minstd_rand();
	std::normal_distribution<float> distribution = std::normal_distribution<float>(0.0f, 1.0f);

	return new Color(distribution(random), distribution(random), distribution(random), distribution(random));
}