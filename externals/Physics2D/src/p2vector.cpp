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

#include <p2vector.h>
#include <cmath>

p2Vec2::p2Vec2()
{
}

p2Vec2::p2Vec2(float x, float y):x(x),y(y)
{
	
}

p2Vec2 p2Vec2::operator+(p2Vec2 v)
{
	return p2Vec2();
}

p2Vec2 p2Vec2::operator+=(p2Vec2 v)
{
	return p2Vec2();
}

p2Vec2 p2Vec2::operator-(p2Vec2 v)
{
	return p2Vec2();
}

p2Vec2 p2Vec2::operator-=(p2Vec2 v)
{
	return p2Vec2();
}

p2Vec2 p2Vec2::operator/(float f)
{
	return p2Vec2();
}

p2Vec2 p2Vec2::operator*(float f)
{
	return p2Vec2();
}

float p2Vec2::Dot(p2Vec2 v1, p2Vec2 v2)
{
	float xResult = v1.x*v2.x;
	float yResult = v1.y*v2.y;
	return xResult + yResult;
}

float p2Vec2::GetMagnitude()
{
	float nb = x * x + y * y;
	return pow(nb, 0.5f);
}

p2Vec2 p2Vec2::Normalized()
{
	float length = GetMagnitude();
	return p2Vec2(x / length, y / length);
}

void p2Vec2::Normalize()
{
	float length = GetMagnitude();
	this->x = x / length;
	this->y = y / length;
}

p2Vec3 p2Vec2::to3()
{

	return p2Vec3(x, y, 0);
}

p2Vec3::p2Vec3()
{
}

p2Vec3::p2Vec3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

float p2Vec3::Dot(p2Vec3 v1, p2Vec3 v2)
{
	float xResult = v1.x*v2.x;
	float yResult = v1.y*v2.y;
	float zResult = v1.z*v2.z;
	return xResult + yResult + zResult;
}

p2Vec3 p2Vec3::Cross(p2Vec3 v1, p2Vec3 v2)
{
	float xResult = (v1.y*v2.z) - (v1.z*v2.y);
	float yResult = (v1.z*v2.x) - (v1.x*v2.z);
	float zResult = (v1.x*v2.y) - (v1.y*v2.x);
	return p2Vec3(xResult, yResult, zResult);
}
