#include "EZGL/Graphics/Vertex.hpp"

namespace ez
{

Vertex::Vertex(Vec3<float> pos, Color col)
{
	position = pos;
	color	= col;
}

}