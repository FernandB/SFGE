/*
MIT License

Copyright (c) 2017 SAE Institute Switzerland AG

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <p2shape.h>



void p2RectShape::SetType(shapeType type2)
{
	p2Shape::SetType(type2);
}

p2RectShape::p2RectShape()
{
	SetType(p2Shape::shapeType::RECTANGLE);
}

p2RectShape * p2RectShape::clone() const
{
	p2RectShape* clone = new p2RectShape();
	*clone = *this;
	return clone;
}



p2CircleShape * p2CircleShape::clone() const
{
	p2CircleShape* clone = new p2CircleShape();

	*clone = *this;
	return clone;
}
void p2CircleShape::SetType(shapeType type2)
{
	p2Shape::SetType(type2);
}

p2CircleShape::p2CircleShape()
{
	SetType(p2Shape::shapeType::CIRCLE);
	
}


void p2CircleShape::SetRadius(float radius)
{
	m_Radius = radius;
}

float p2CircleShape::GetRadius()
{
	return m_Radius;
}



p2Shape::shapeType p2Shape::GetType()
{
	return type;
}
void p2Shape::SetType(shapeType type2)
{
	type = type2;
}

void p2RectShape::SetSize(p2Vec2 size)
{
	m_Size = size;
}

p2Vec2 p2RectShape::GetSize()
{
	return m_Size;
}


