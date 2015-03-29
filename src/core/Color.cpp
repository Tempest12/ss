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