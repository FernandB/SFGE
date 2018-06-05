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

#include <p2aabb.h>

p2AABB::p2AABB()
{
}

p2AABB::p2AABB(p2Vec2 position, p2Vec2 size)
{
	bottomLeft = position - p2Vec2(size.x / 2.0f,-size.y/2.0f);
	topRight = position + p2Vec2(size.x / 2.0f, -size.y / 2.0f);
	this->size = size;
}


p2Vec2 p2AABB::GetCenter()
{
	return p2Vec2((topRight.x+bottomLeft.x)/2.0f,(bottomLeft.y-topRight.y)/2.0f);
}

p2Vec2 p2AABB::GetSize()
{
	size = p2Vec2(topRight.x - bottomLeft.x, bottomLeft.y - topRight.y);
	return size;
}

p2Vec2 p2AABB::GetExtends()
{
	return (topRight - bottomLeft) / 2.f;
}
