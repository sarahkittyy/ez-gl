#include "EZGL/Graphics/Color.hpp"

namespace ez
{

Color::Color(float r, float g, float b, float a)
	: r(r),
	  g(g),
	  b(b),
	  a(a)
{
}

Color Color::normalize()
{
	//Normalize and return
	Color ret(r / 255.f, g / 255.f, b / 255.f, a / 255.f);
	return ret;
}

}