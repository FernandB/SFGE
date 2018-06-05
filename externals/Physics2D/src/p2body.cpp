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
#include <p2body.h>
#include <p2collider.h>
#include <iostream>
p2Vec2 p2Body::GetLinearVelocity()
{
	return linearVelocity;
}

p2BodyType p2Body::GetType()
{
	return type;
}

void p2Body::SetLinearVelocity(p2Vec2 velocity)
{
	linearVelocity = velocity;
}

void p2Body::SetPosition(p2Vec2 pos)
{
	position = pos;
	aabb->bottomLeft= position - p2Vec2(aabb->size.x / 2.0f, -aabb->size.y / 2.0f);
	aabb->topRight = position + p2Vec2(aabb->size.x / 2.0f, -aabb->size.y / 2.0f);
	
}

float p2Body::GetAngularVelocity()
{
	return angularVelocity;
}

std::list<p2Collider*> p2Body::GetColliders()
{
	return colliders;
}

p2Vec2 p2Body::GetPosition()
{

	return aabb->GetCenter();
}

p2AABB* p2Body::GetAABB()
{
	return aabb;
}
p2Collider* p2Body::CreateCollider(p2ColliderDef * colliderDef)
{
	p2Collider* collider; 

	p2Shape* shape = colliderDef->shape;
	if (shape->GetType()==p2Shape::shapeType::CIRCLE)
	{
		p2CircleShape* shape2 = dynamic_cast<p2CircleShape*>(shape);
		aabb = new p2AABB(position,p2Vec2(shape2->GetRadius()*2.f, shape2->GetRadius()*2.f));
		
	}
	else
	{
		if (shape->GetType() == p2Shape::shapeType::RECTANGLE)
		{
			p2RectShape* shape1 = dynamic_cast<p2RectShape*>(shape);
			aabb = new p2AABB(position, shape1->GetSize());
		}
		else
			std::cout << "Problem whith shape";
		
	}
	 
	collider= new p2Collider(colliderDef, this);
	colliders.push_back(collider);
	return collider;
}

p2Body::p2Body(p2BodyDef* bodydef)
{
	type=bodydef->type;
	position=bodydef->position;
	linearVelocity= bodydef->linearVelocity;
	gravityScale= bodydef->gravityScale;
	angularVelocity = bodydef->angularVelocity;
	aabb = bodydef->aabb;
}
float meter2pixel(float meter)
{
	return meter * 100;
}

sf::Vector2f meter2pixel(p2Vec2 meter)
{
	return sf::Vector2f(meter2pixel(meter.x), meter2pixel(meter.y));
}
void p2Body::Draw(sf::RenderWindow& window)
{
	sf::Vector2f pos =meter2pixel(position);
	sf::RectangleShape rectangle(meter2pixel(p2Vec2(GetAABB()->GetSize().x, GetAABB()->GetSize().y)));
	rectangle.setPosition(pos.x,pos.y);
	rectangle.setFillColor(sf::Color::Blue);
	window.draw(rectangle);
}



p2Body::~p2Body()
{
	delete(aabb);
}
