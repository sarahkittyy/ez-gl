#include "EZGL/Graphics/VertexArray.hpp"

namespace ez
{

VertexArray::VertexArray(Window* window)
	: mWindow(window)
{
	//Default values.
	mPrimitive = Primitive::Points;
	init();
}

void VertexArray::init()
{
	//Generate and bind the vertex arrays
	glGenVertexArrays(1, &mVAO);
	glBindVertexArray(mVAO);

	//Generate and bind the vertex buffer.
	glGenBuffers(1, &mVBO);
	glBindBuffer(GL_ARRAY_BUFFER, mVBO);

	//Set the buffer data.
	glBufferData(GL_ARRAY_BUFFER, mData.size() * sizeof(float), mData.data(), GL_DYNAMIC_DRAW);

	//Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
	//Color attribute
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));

	//Enable the attributes
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	//Use the default shader
	Shader::useDefault();

	//Unbind
	glBindVertexArray(0);
	glBindBuffer(0, GL_ARRAY_BUFFER);
}

void VertexArray::setPrimitiveType(Primitive p)
{
	mPrimitive = p;
}

void VertexArray::push(Vertex v)
{
	mVertices.push_back(v);
	update();
}

void VertexArray::update()
{
	//Reset the data.
	mData.clear();
	Vec2<size_t> ws = mWindow->getSize();

	//For every vertex.
	for (auto& v : mVertices)
	{
		mData.push_back(v.position.x / ws.x * 2 - 1.0f);
		mData.push_back(v.position.y / ws.y * 2 - 1.0f);
		mData.push_back(v.position.z / ws.x * 2 - 1.0f);   //This can be ws.depth of view? TODO
		mData.push_back(v.color.r / 255.f);
		mData.push_back(v.color.g / 255.f);
		mData.push_back(v.color.b / 255.f);
		mData.push_back(v.color.a / 255.f);
	}

	updateGL();
}

void VertexArray::updateGL()
{
	//Bind
	glBindVertexArray(mVAO);
	glBindBuffer(mVBO, GL_ARRAY_BUFFER);

	glBufferData(GL_ARRAY_BUFFER, mData.size() * sizeof(float), mData.data(), GL_DYNAMIC_DRAW);

	//Unbind
	glBindVertexArray(0);
	glBindBuffer(0, GL_ARRAY_BUFFER);
}

void VertexArray::draw()
{
	//Bind the buffer
	glBindVertexArray(mVAO);
	glDrawArrays(mPrimitive, 0, mVertices.size());
	glBindVertexArray(0);
}

}